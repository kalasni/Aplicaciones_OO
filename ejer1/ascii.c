/* programa al que se le introduce un carater y devuelve su 
   codigo ascii. (08-04-03) */
   
#include <stdio.h>
#include <stdlib.h>
char valor;
int main()
{
 printf( "Introduzca un caracter: \n");
 scanf ("%c" , &valor);
 printf ("El codigo ascii de %c es %d \n
 " , valor, valor);
 system ("PAUSE");
 return 0;
 }
   
