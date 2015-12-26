#include <stdio.h>
#include <stdlib.h>

typedef struct
{

  char referencia[20];
  char nombre[20];
  int precio;

} registro;  

/*       Definición de las funciones basicas de los registros:

   1. IniciarRegistro = Pone todos los campos a 0 o valor nulo.
   2. PedirRegistro = Lee del teclado los campos de un regisdtro y lo devuelve 
   3. VerRegistro = Imprime por pantalla todos los campos de un registro   */

void IniciarRegistro(registro *reg);
registro PedirRegistro();
void VerRegistro(registro reg);



/************************************************************************/
                                                                           


// Definición del tipo baseDeDatos.

typedef struct
{
  char nomFichero[20]; // nombre del fichero
  FILE *f;           // flujo hacia/desde el fichero
  int nregs;           // número de registros
  int tamreg;          // tamaño del registro en bytes
  int regsEliminados;  // 1 cuando se haya borrado algún registro (marca)
} TablaDeDatos;

/************************** IMPORTACION EXPLICITA ********************/

registro LeerRegistro( int i, TablaDeDatos tabla );


/*************** FUNCIONES BASICAS DE LOS TABLAS *******************/


void IniciarTabla(TablaDeDatos *tabla);
int AbrirTabla(TablaDeDatos *tabla) ;
void CerrarTabla( TablaDeDatos *tabla );
int ActualizarTabla( TablaDeDatos *tabla);


/******************** FUNCIONES ACCESO A LAS TABLAS ****************/


registro LeerRegistro( int i, TablaDeDatos tabla );
int EscribirRegistro( int i, registro reg, TablaDeDatos *tabla );
int EliminarRegistro( char *ref, TablaDeDatos *tabla);
int BuscarRegistro( char *str, TablaDeDatos tabla );
void ModificarRegistro(TablaDeDatos tabla);
void VisualizarRegistros(TablaDeDatos tabla);


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


/**************** FUNCIONES BASICAS DE LOS REGISTROS ***************/


void IniciarRegistro(registro *reg)
{
  strcpy(reg->referencia,"borrar");
  *(reg->nombre) = 0;
  reg->precio = 0.0;
}

registro PedirRegistro()
{
    registro reg;
    IniciarRegistro(&reg);
    system("cls");
    do
    {
        printf("\nREFERNCIA: ");
        gets(reg.referencia);
    }
    while (strcmp(reg.referencia,"borrar") == 0);
    printf("\nNOMBRE: ");
    gets(reg.nombre);
    printf("\nPRECIO: ");
    scanf("%lf",&reg.precio);
    return reg;
}

void VerRegistro(registro reg)
{
    if (strcmp(reg.referencia, "borrar"))
    {
        printf("REFERNCIA: %s\n", reg.referencia);
        printf("NOMBRE: %s\n", reg.nombre);
        printf("PRECIO: %lf\n", reg.precio);
    }
    else
        printf("ELIMINADO");
}

    
    
  /************************************************************/

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
  
/***********************************************************/

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


