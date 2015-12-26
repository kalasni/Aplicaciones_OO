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

/***************************************************************************************/
/**************************** FUNCIONES ACCESO A LAS TABLAS **************************
***************************************************************************************/

registro LeerRegistro( int i, TablaDeDatos tabla );
int EscribirRegistro( int i, registro reg, TablaDeDatos *tabla );
int EliminarRegistro( char *ref, TablaDeDatos *tabla);
int BuscarRegistro( char *str, TablaDeDatos tabla );
void ModificarRegistro(TablaDeDatos tabla);
void VisualizarRegistros(TablaDeDatos tabla);

/***************************************************************************************/

registro LeerRegistro( int i, TablaDeDatos tabla )
{
  registro reg;     // para guardar el resultado de la funcion
  IniciarRegistro(&reg);    

  if (i >= 0 && i < tabla.nregs)
  {
    // Situar el puntero de L/E en el registro i
    fseek(tabla.f, i * tabla.tamreg, SEEK_SET);
    // Leer la información correspondiente al registro i
    fread(&reg, tabla.tamreg, 1, tabla.f);
  }
  else
    printf("Número de registro fuera de límites\n");

  // Devolver el registro correspondiente.
  return reg;
}


/* Recibe la posicion el registro y la tabla en donde se escribira */
int EscribirRegistro( int i, registro reg, TablaDeDatos *tabla )
{
  if (i >= 0 && i <= tabla->nregs )  
  {
    // Situar el puntero de L/E en el registro i
    fseek(tabla->f, i * tabla->tamreg, SEEK_SET);
    // Sobreescribir el registro con la nueva información
    fwrite(&reg, tabla->tamreg, 1, tabla->f);
    if (!ferror(tabla->f)) 
    {
         if (i == tabla->nregs)
           tabla->nregs++;  // en el caso añadir un nuevo    
    return 1;    //si se escribe correctamente devuelve 1
    }
    printf("\n\nError al escribir en el fichero\n");
  }
  else
    printf("Número de registro fuera de límites\n");
  
  return 0;
}

int EliminarRegistro( char *ref, TablaDeDatos *tabla)
{
  int posicion = 0;
  registro reg;
  IniciarRegistro(&reg); // Marcar el registro con la referencia "borrar"
  posicion= BuscarRegistro(ref,*tabla);
  if (posicion >= 0)
  { 
      EscribirRegistro( posicion, reg, tabla );
      tabla->regsEliminados = 1;      // pongo a 1 la marca de eliminados de la tabla
      return 1;
  }
  return 0;
}

int BuscarRegistro( char *str, TablaDeDatos tabla )
{
  int i = 0;
  registro reg;  // almaceno temporalmente el registro que leo
  
  for ( i = 0; i < tabla.nregs; i++ )
  {
    // Obtener el registro reg_i
    reg = LeerRegistro(i,tabla);
    // ¿Tiene la referencia ref?
    if (strcmp(str, reg.referencia) == 0)
    {
        return i;
    }
   }
   return -1;   // no se ha encontrado
}

void ModificarRegistro(TablaDeDatos tabla)
{
   registro reg;
   char ref[20], car;
   int op , nreg = 0;
  
   int MenuModificar()
   {
      int op=0;
      do
      {
          printf("\n\n");
          printf("MODIFICAR EL DATO:\n\n");
          printf("1. REFERENCIA\n");
          printf("2. NOMBRE\n");
          printf("3. PRECIO\n");
          printf("4. SALIR Y GUARDAR CAMBIOS\n");
          printf("5. SALIR SIN GUARDAR CAMBIOS\n\n");
          printf("   OPCION: ");
          scanf("%d", &op); fflush(stdin);
      }
      while( op < 1 && op > 5);
      return op;
   }
     
  if (tabla.nregs == 0)
  {
    printf("\n\nFICHERO VACIO\n");
    return;
  }

  // Solicitar el número de registro a modificar  
  do
  {
    printf("Referencia del registro que se desea modificar: "); 
    scanf("%s", ref); fflush(stdin);
    nreg= BuscarRegistro(ref, tabla);
    if ((strcmp(ref,"borrar")==0) || nreg == -1)
    {
        printf("\nReferencia no valida\n");
        printf("\nDesea continuar (s/n): ");
        car= getchar();
        fflush(stdin);
    }
    if (toupper(car)== 'N')
        return;   
  }
  while ((strcmp(ref,"borrar")==0) || nreg == -1);
  // Leer el registro
  reg = LeerRegistro(nreg, tabla);
  
  // Visualizarlo
  system("cls");
  printf("\n\n\tREGISTRO %d\n",nreg+1);
  printf("\t**********\n");
  VerRegistro(reg);
  do
  {
  op=MenuModificar();
  // Modificar el registro
          
    switch( op )
    {
      case 1: // modificar referencia
      do
        {
         printf("REFERENCIA: ");
         gets(reg.referencia);
         if (BuscarRegistro(reg.referencia, tabla)!= -1)
         {
            printf("\n\n¡¡ ERROR !! No se pueden duplicar referencias (clave principal)\n\n");
            system("pause");
         } 
        }
       while (BuscarRegistro(reg.referencia, tabla)!= -1);         
        break;
      case 2: // modificar nombre
        printf("NOMBRE: ");
        gets(reg.nombre);
        break;
      case 3: // modificar precio
        printf("PRECIO: ");
        scanf("%lf", &reg.precio); fflush(stdin);
        break;
      case 4: // guardar los cambios
        EscribirRegistro(nreg, reg, &tabla);
        break;
      case 5: // salir sin guardar los cambios
        break;
    }
   }
   while (op!=4 && op!=5);  // tengo la opcion de modificar mientras no elija salir (3 o 4)          
}

void VisualizarRegistros(TablaDeDatos tabla)
{
  registro reg;
  char str[20];
  int i = 0, encontrado=0;    // guardara los registros encontrados

  IniciarRegistro(&reg);
  system("cls");
  if (tabla.nregs == 0)
  {
    printf("\n\nFICHERO VACIO\n");
    return;
  }

  printf("\n\nConjunto de caracteres a buscar: ");
  gets(str);
  // str igual a * visualiza todos
  while (i<tabla.nregs)
  {
      reg = LeerRegistro(i, tabla);
      if (strstr(reg.referencia, str) || *str == '*')
      {
          printf("\n\n\tREGISTRO %d\n",i+1);
          printf("\t**********\n");
          VerRegistro(reg);
          encontrado=1;
      }
      i++;
  }
  if (!encontrado)
    printf("\nNo se encontro ningun registro\n");
  printf("\n\n");
}


