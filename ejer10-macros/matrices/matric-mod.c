
#include "matrices.h"

void entr_datos(void)
{

   printf ("Introduzca el valor de las filas de la matriz 1 : \n");
   scanf ("%d", &f1);

   printf ("Introduzca el valor de las columnas de la matriz 1: \n");
   scanf ("%d", &c1);

   printf ("Introduzca los datos de la matriz : \n");

   // Empezamos a leer los datos de matriz 1

   for (i=0; i<f1; i++)
   {
     for (j=0; j<c1; j++)
     {
        printf ("Elemento [%d %d] de matriz 1?\n", i+1, j+1);
        scanf ("%f", &mat1[i][j]);
     }
   }

   printf ("Introduzca el valor de las filas de la matriz 2: \n");
   scanf ("%d", &f2);

   printf ("Introduzca el valor de las columnas de la matriz 2: \n");
   scanf ("%d", &c2);

   printf ("Introduzca los datos de la matriz : \n");

  // Leemos los datos de matriz 2

   for (i=0; i<f1; i++)
   {
     for (j=0; j<c1; j++)
     {
       printf ("Elemento [%d %d] de matriz 2?\n", i+1, j+1);
       scanf ("%f", &mat2[i][j]);
     }
   }
}


 /* Esta funcion la vamos a utilizar para leer los datos en la opcion
    4, calculo de la traspuesta. */

void entr_datos2(void)
{
   printf ("Introduzca el valor de las filas de la matriz 1 : \n");
   scanf ("%d", &f1);

   printf ("Introduzca el valor de las columnas de la matriz 1: \n");
   scanf ("%d", &c1);

   printf ("Introduzca los datos de la matriz : \n");

   // Empezamos a leer los datos de matriz 1

   for (i=0; i<f1; i++)
   {
     for (j=0; j<c1; j++)
     {
        printf ("Elemento [%d %d] de matriz 1?\n", i+1, j+1);
        scanf ("%f", &mat1[i][j]);
     }
   }

}


void suma (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX])
 {
    if ((f1!=f2) || (c1!=c2))
    {
      printf("No se puede realizar suma. Matrices de dimensiones diferentes\n");
      printf ("\n\n");
      entr_datos();
    }
    else {  
    printf ("La suma de las matrices 1 y 2 es: \n\n\n");
    for (i=0; i<f1; i++)
    {
      for (j=0; j<c1; j++)
      {
        resul[i][j]= mat1[i][j] + mat2[i][j];
        printf ("%f ", resul[i][j]);
      }
        printf ("\n\n\n");
    }
   } 
     
 }
 

void resta (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX])
 {
   if ((f1!=f2) || (c1!=c2))
   {
     printf("No se puede realizar resta. Matrices de dimensiones diferentes\n");
     printf ("\n\n");
     entr_datos();
   }
   else {  
   printf ("La resta de las matrices 1 y 2 es: \n\n\n");
   for (i=0; i<f1; i++)
   {
    for (j=0; j<c1; j++)
    {
      resul[i][j]= mat1[i][j] - mat2[i][j];
      printf ("%f ", resul[i][j]);
    }
      printf ("\n\n\n");
   }
  } 
 }

 

void multip (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX])
 {
   int k;
   float total;

   if (c1 != f2)
   {
     printf ("El producto no se puede realizar: ");
     printf ("Matrices de dimensiones diferentes. \n");
     entr_datos();
   }
   else 

   printf ("la multiplicacion de las matrices 1 y 2 es: \n\n\n");

   for (i=0; i<f1; i++)
   {
    for (j=0; j<c1; j++)
    {
     total= 0;
     for (k=0; k<c1; k++)
     {
       total+= mat1[i][k] * mat2[k][j];
       resul[i][j]= total;
     }
    }
   }
     for (i=0; i<f1; i++)
     {
      for (j=0; j<c1; j++)
      {
        printf ("%f ", resul[i][j]);
      }
        printf ("\n");
     } 
       printf ("\n\n\n");
   
  } 

  
  
void traspues (int f1, int c1, float mat1[][MAX])
{
   int i=0;           
   printf ("la matriz traspuesta es: \n\n\n");

   do{

       for (j=0; j<c1; j++)
       {

         printf ("%f  ", mat1[j][i]);
       }
         printf ("\n");
         i++;
	 
      }while (i < c1);
      printf ("\n\n");
      
 }
