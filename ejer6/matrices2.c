/* Programa para calcular la suma, resta y producto de dos matrices del mismo orden,
   (las dos tienen que tener el mismo numero de filas y columnas). También muestra
   la traspuesta de la primera matriz. (02-05-03) */
   


#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 12


void entr_datos(void);
void entr_datos2(void);
void suma (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void resta (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void multip (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void traspues (int f1, int c1, float[][MAX]);
int i, j, f1, f2, c1, c2, num;
float mat1[MAX][MAX], mat2[MAX][MAX], resul[MAX][MAX];

int main()
{

 


 printf ("======================================\n");
 printf ("Elija el calculo que quiere realizar: \n");
 printf ("======================================\n");
 printf ("\n");
 printf ("(1) - SUMA \n");
 printf ("(2) - RESTA \n");
 printf ("(3) - MULTIPLICACION \n");
 printf ("(4) - MOSTRAR LA TRASPUESTA DE LA MATRIZ 1 \n");
 printf ("\n");
 
 scanf ("%d", &num);

 switch (num) {
          

        case 1:   entr_datos();
                  suma (f1, c1, f2, c2, mat1, mat2, resul);
                  break;  
          
        case 2:   entr_datos();
                  resta (f1, c1, f2, c2, mat1, mat2, resul);
                  break;

        case 3:   entr_datos();
                  multip (f1, c1, f2, c2, mat1, mat2, resul);
                  break;

        case 4:   entr_datos2();
                  traspues (f1, c1, mat1);
                  break; 
 }
 
 return 0;
}

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
   printf ("La suma de las matrices 1 y 2 es: \n");
   for (i=0; i<f1; i++)
   {
    for (j=0; j<c1; j++)
    {
      resul[i][j]= mat1[i][j] + mat2[i][j];
      printf ("%f ", resul[i][j]);
    }
     printf ("\n");
   }
 }

 

void resta (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX])
 {
   printf ("La resta de las matrices 1 y 2 es: \n");
   for (i=0; i<f1; i++)
   {
    for (j=0; j<c1; j++)
    {
      resul[i][j]= mat1[i][j] - mat2[i][j];
      printf ("%f ", resul[i][j]);
    }
      printf ("\n");
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
   }
   else 

   printf ("la multiplicacion de las matrices 1 y 2 es: \n");

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
  }

  
  
void traspues (int f1, int c1, float mat1[][MAX])
{
   int i=0;           

   clrscr();
   printf ("la matriz traspuesta es: \n");

   do{

       for (j=0; j<c1; j++)
       {

         printf ("%f  ", mat1[j][i]);
       }
         printf ("\n");
         i++;
	 
      }while (i<f1);
 }
