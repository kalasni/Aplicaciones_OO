#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición del tipo registro
typedef struct
{
  char referencia[20];
  char nombre[20];
  double precio;
} registro;

// Definición del tipo baseDeDatos.
typedef struct
{
  char nomFichero[20]; // nombre del fichero
  FILE *f;           // flujo hacia/desde el fichero
  int nregs;           // número de registros
  int tamreg;          // tamaño del registro en bytes
  int regsEliminados;  // 1 cuando se haya borrado algún registro (marca)
} TablaDeDatos;

/************************** IMPORTACION EXPLICITA ***********************************/

registro LeerRegistro( int i, TablaDeDatos tabla );

/***************************************************************************************/
/**************************** FUNCIONES BASICAS DE LOS TABLAS ***********************
***************************************************************************************/

void IniciarTabla(TablaDeDatos *tabla);
int AbrirTabla(TablaDeDatos *tabla) ;
void CerrarTabla( TablaDeDatos *tabla );
int ActualizarTabla( TablaDeDatos *tabla);

/***************************************************************************************/

void IniciarTabla(TablaDeDatos *tabla)
{
  *(tabla->nomFichero) = 0;
  tabla->f = NULL;
  tabla->nregs = 0;
  tabla->tamreg = sizeof(registro);
  tabla->regsEliminados = 0;
}

int AbrirTabla(TablaDeDatos *tabla)      
{
  char nombre[20];
  char resp = 'n';
  char *modo= "w+b";    // para el caso de que la tabla no exista

  if (tabla->f)
  {
    printf("\nYa hay una tabla abierta.\n");
    printf("¡¡¡Debe cerrar antes %s !!!\n", tabla->nomFichero);
    return 0;
  }
  system("cls");
  printf("\n\nNombre del fichero: ");
  gets(nombre); // nombre fichero
  strcpy(tabla->nomFichero,strcat(nombre,".tabla"));
  if ((tabla->f = fopen(tabla->nomFichero, "r"))!= NULL )
  {
    do
    {
      printf("\n\nEste fichero existe\n¿Desea sobrescribirlo? (s/n) ");
      resp = tolower(getchar());
      fflush(stdin);
    }
    while (resp != 's' && resp != 'n');
    if (resp == 'n')
      modo = "r+b";
  }

  if ((tabla->f = fopen(tabla->nomFichero, modo)) == NULL)
  {
    printf("Error: No se puede crear el fichero\n\n");
    tabla->f = 0; // fichero no abierto
    return 0;
  }
  // Establecer los datos longitud del registro y nº de registros
  tabla->tamreg = sizeof(registro);
  fseek(tabla->f, 0, SEEK_END);
  tabla->nregs = ftell(tabla->f)/sizeof(registro);
  rewind(tabla->f);
  printf("\n\nFichero %s abierto\n\n", tabla->nomFichero);
  return 1;
}

void CerrarTabla( TablaDeDatos *tabla )
{
  if (tabla->regsEliminados)    // elimino fisicamente los registros borrados
  {
    tabla->regsEliminados = 0;
    ActualizarTabla(tabla);
    printf("\n\nSe ha actualizado el fichero %s\n\n", tabla->nomFichero);
  }
  if (tabla->f) fclose(tabla->f); // cerrar el fichero actual
  tabla->f = NULL;
  tabla->nregs = 0;      // poner a cero el nº de registros
}

int ActualizarTabla( TablaDeDatos *tabla)
{
  int i = 0;
  registro reg;
  TablaDeDatos tablatemp;  
  IniciarTabla(&tablatemp);

  //creo una tabla temporal para guardar los cambios.
  tablatemp.f = tmpfile();
  if (tablatemp.f == NULL)
  {
    printf("Error: No se puede crear un fichero temporal\n");
    return 0;
  }
  // Copiar en el fichero temporal todos los registros del
  // fichero actual que no estén marcados para "borrar"
  for ( i = 0; i < tabla->nregs; i++ )
  {
    reg = LeerRegistro(i, *tabla);
    if (strcmp(reg.referencia, "borrar") == 0) continue; // si esta marcado continuo
    EscribirRegistro(tablatemp.nregs, reg, &tablatemp);
  }
  // Copiar en el fichero actual todos los registros del temporal.
  // Para ello, cierro el fichero actual y lo creamos de nuevo en modo w+b.
  if (tabla->f) fclose(tabla->f);
  
  if ((tabla->f = fopen(tabla->nomFichero, "w+b")) == NULL)
  {
    printf("Error: No se puede crear el fichero\n");
    return 0;
  }
  rewind(tablatemp.f); // volver al principio del fichero temporal
  for ( i = 0; i < tablatemp.nregs; i++ )
  {
    reg = LeerRegistro(i, tablatemp);
    EscribirRegistro(i, reg,tabla);
  }
  
  return 1;
}

