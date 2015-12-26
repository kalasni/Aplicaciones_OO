/* Programa al que se le introduce un numero de veces que repetirá 
   la secuencia de comparar otro numero introducido con un determinado
   valor (21-04-03) */


#include <stdio.h>
#include <stdlib.h>

int main()
{
 int nota, i;
 char a;
 int num, contador=0;
 puts ("Introduzca numero de notas por teclado:");
 scanf ("%i", &num);
 for (i=0; i<num; i++)
 {
   printf ("introduzca nota:\n");
   fflush (stdin);
   scanf ("%i", &nota);
   if (nota == 10)
   {
    contador++;
   }
 }
 printf ("\n");
 printf ("Se ha introducido %i veces el valor 10 \n\n" , contador);
 system("pause");
 return 0;
 }

