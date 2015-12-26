/* Programa al que se le introduce una serie impar de enteros, los ordena
   mediante el algoritmo de intercambio y muestra la mediana de la serie.
   (la mediana es el numero que esta entre los numeros mas bajos y los 
   numeros mas altos de la serie). (08-05-02) */

#include <stdio.h>
#include <stdlib.h>
void ordenar (int numeros[20], int num);
void intercambio(int * x, int * y);


int main()
{
  int numeros[20];
  int i= 0, num;
  puts ("Introduzca el numero (impar) de elementos de la lista: \n");
  scanf ("%d", &num);

  do {
       printf ("Introduzca elemento: \n");
       scanf ("%d" , &numeros[i]);
       i++;
     } while (i < num);

  ordenar(numeros , num);
  return 0;
 }
 
 /* Vamos a utilizar el algoritmo de ordenacion de intercambio que ordena
    los elementos de forma ascendente */

 void ordenar (int numeros[20], int num)
 {
   int i, j, mediana;
   for (i=0; i < num - 1; i++)
   {
     for (j= i+1; j < num; j++)
     {
       if (numeros[i] > numeros[j])
       {
         intercambio( &numeros[i], &numeros[j]);
       }
     }
   }  
     printf ("\033[2J"); // Esto limpia la pantalla. Secuencia de escape.

     for (i=0; i < num; i++)
     {
       printf ("%d  ",  numeros[i]);
     }
       printf ("\n");
       mediana= (num / 2);
       printf ("La mediana es: %d \n\n", numeros[mediana]);
  }


 /* En esta funcion es donde realmente se realiza el intercambio de
    los elementos mediante los punteros. */ 

void intercambio(int * x, int * y)
{
  int aux;
  aux= *x;
  *x= *y;
  *y= aux;
} 
