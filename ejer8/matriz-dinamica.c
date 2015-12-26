/* Programa que crea, visualiza y ordena una matriz dinamica (pide el 
   numero de filas y el de columnas). (02-06-03) */


#include <stdio.h>
#include <stdio.h>
#include <string.h>

int crear_matriz(void);
int leer_datos(void);
int ver_datos(void);
int inicia_matriz(void);
void ordenar_matriz(void);
void liberar_matriz(void);

char **matriz= NULL;
int filas, colum;

int main()
{

  if (crear_matriz())
  {
  inicia_matriz();
  
  if(leer_datos())
  {
    ver_datos();
  }  
  ordenar_matriz();
  liberar_matriz();
  }
  system ("pause");
  return 0;
}

int crear_matriz()
{
  int i, j;
  printf ("Introduzca el numero de filas de la matriz: \n");
  scanf ("%d", &filas);
  fflush (stdin);
  printf ("Introduzca el numero de columnas de la matriz: \n");
  scanf ("%d", &colum);
  fflush (stdin);

  /* Creamos la matriz con una dimension mas (filas y columnas) para utilizarlo 
     luego en la comparación */
    
  if (!(matriz= (char**) malloc ((filas+1)* sizeof (char*))))
  {
    printf ("No se ha podido crear matriz \n");
    return 0;
  }  

  for (i=0; i<filas+1; i++)
  {
    if (!(matriz[i]= (char*) malloc ((colum+1)* sizeof (char))))
    {
        printf ("No se ha podido crear matriz \n");
        return 0;
     }
  }
  return 1;
}


int leer_datos()
{
  int i, j;
  
  for (i=0; i<filas; i++)
  {
    for (j=0; j<colum; j++)
    {
      printf ("elemento [%d][%d] \n", i+1, j+1);
      if (!scanf ("%c", &matriz[i][j]))
      {
       return 0;
      }
      fflush (stdin);
    }  
  }
  return 1;
}       


int ver_datos()
{
  int i, j;
  
  for (i=0; i<filas; i++)
  {
    for (j=0; j<colum; j++)
    {
      printf ("%c ", matriz[i][j]);
    }
    printf ("\n"); 
  }
  printf ("\n\n");
}        

int inicia_matriz()
{
 int i, j;
 
 /* Inicializamos matriz con el caracter z para que no compare el 
    ultimo elemento de la matriz y lo tenga como referencia */
 
 for (i=0; i<filas+1; i++)
 {
   for (j=0; j<colum+1; j++)
   {
     matriz[i][j]='z';
   }  
 }  
}

 
void liberar_matriz()
{
  int i;
  for(i=0; i<filas+1; i++)
  { 
    free (matriz[i]);
  }  
  free(matriz);
 
  printf ("Espacio de matriz liberado \n\n\n");
}  

void ordenar_matriz()
{
   printf ("Matriz ordenada \n\n");
   char aux;
   int ordenado;
   
   int fil, col, i, j;
 do
 { 
   ordenado= 0;
   for (i=0; i<filas; i++)
   {
     fil= i;
     
     for (j=0; j<colum; j++)
     {
       col= j+1;
       
       if (i==filas-1 && j==colum-1)
       break;
       if (j==colum-1)
       {
         fil++;
         col= 0;
       }
       if (matriz[i][j] > matriz[fil][col]) 
       { 
         aux = matriz[i][j];
         matriz[i][j]= matriz[fil][col];
         matriz[fil][col]= aux;
         ordenado= 1;
         
       }
     }
   }
 }while (ordenado==1); 
   
    
    for (i=0; i<filas; i++)
    {
      for (j=0; j<colum; j++)
      {
         printf ("%c ", matriz[i][j]);
      }
      printf ("\n\n");
    }         
  }     

