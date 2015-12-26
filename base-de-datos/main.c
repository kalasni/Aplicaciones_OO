#include <stdio.h>
#include <stdlib.h>


typedef struct
{
  char referencia[20];
  char nombre[20];
  double precio;
} registro;

// Definición del tipo TablaDeDatos.
typedef struct
{
  char nomFichero[20]; // nombre del fichero
  FILE *f;             // flujo hacia/desde el fichero
  int nregs;           // número de registros
  int tamreg;          // tamaño del registro en bytes
  int regsEliminados;  // 1 cuando se haya borrado algún registro (marca)
} TablaDeDatos;

void IniciarRegistro(registro *reg);
registro PedirRegistro();
void VerRegistro(registro reg);

registro LeerRegistro( int i, TablaDeDatos tabla );
int EscribirRegistro( int i, registro reg, TablaDeDatos *tabla );
int EliminarRegistro( char *ref, TablaDeDatos *tabla);
int BuscarRegistro( char *str, TablaDeDatos tabla );
void ModificarRegistro(TablaDeDatos tabla);
void VisualizarRegistros(TablaDeDatos tabla);

void IniciarTabla(TablaDeDatos *tabla);
int AbrirTabla(TablaDeDatos *tabla) ;
void CerrarTabla( TablaDeDatos *tabla );
int ActualizarTabla( TablaDeDatos *tabla);

int main()
{
  char referencia[20];
  int opcion = 0;
  TablaDeDatos articulos;
  registro reg;
  IniciarRegistro(&reg);
  IniciarTabla(&articulos);
  do
  {
    system("cls");
    opcion = menu(articulos);
    switch (opcion)
    {
      case 1: // abrir fichero
        IniciarTabla(&articulos);
        AbrirTabla(&articulos);
        system("pause");
        break;
      case 2: // añadir registro al final del fichero
        reg=PedirRegistro();  
        if (BuscarRegistro(reg.referencia,articulos)== -1)
        {
           if(EscribirRegistro( articulos.nregs, reg, &articulos))
                printf("\n\nSe ha anadido el registro correcatmente\n\n");
        }
        else
           printf("\n\n¡¡ ERROR !! No se pueden duplicar referencias (clave principal)\n\n");
        system("pause");
        break;
      case 3: // modificar registro
        ModificarRegistro(articulos);
        system("pause");
        break;
      case 4: // eliminar registro
        printf("\n\nREFERENCIA: "); 
        gets(referencia);
        if(EliminarRegistro(referencia, &articulos))
            printf("\n\nRegistro eliminado\n\n");
        else
            printf("\n\nNo se ha podido eliminar ese registro\n\n");
        system("pause");   
        break;
      case 5: // visualizar registros
        VisualizarRegistros(articulos);
        system("pause");
        break;
      case 6: // cerrar la tabla
        CerrarTabla(&articulos);
        system("pause");
        break;
      case 7: // salir
        CerrarTabla(&articulos);
        system("pause");
        break;
        }
  }
  while(opcion != 7);
}

int menu(TablaDeDatos tabla)
{
  int op;
  printf("\n\n\tBASE DE DATOS\n");
  printf("\t*************");
  printf("\n\n");
  printf("1. ABRIR TABLA\n");
  printf("2. ADYADIR REGISTRO\n");
  printf("3. MODIFICAR REGISTRO\n");
  printf("4. ELIMINAR REGISTRO\n");
  printf("5. VISUALIZAR REGISTROS\n");
  printf("6. CERRAR TABLA\n");  
  printf("7. SALIR\n\n");    
  printf("   OPCION: ");
  do
  {
    scanf("%d", &op); 
    fflush(stdin);
    if (op < 1 || op > 7)
      printf("\n\nOpción no válida. Elija otra: ");
  }
  while (op < 1 || op > 7);
  
  if (op== 1 && tabla.f!=NULL)
  {
    printf("\n\nERROR Tienes que cerrar la tabla que tines abierta\n\n");
    system("pause");
    return 0;
  }
  if (op > 1 && op < 7 && !tabla.f)
  {
    printf("\n\nERROR Tienes que tener una tabla abierta \n\n");
    system("pause");
    return 0;
  }
  return op;
}
