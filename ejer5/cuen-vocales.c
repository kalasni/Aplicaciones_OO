/* Programa al que se le introduce un texto por teclado y muestra el
   numero de caracteres y vocales introducidas por el mismo.
   (28-03-04) */

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int caracteres= 0, vocales= 0;
 char car;
 puts ("Introduzca un texto por teclado: \n");
 puts ("Para finalizar el texto introduzca ctrl-Z: \n");
 while ((car= getchar())!= EOF)
 {
   caracteres++;
   if ((car=='A') || (car=='a'))
       {vocales++;}
   if ((car=='E') || (car=='e'))
       {vocales++;}
   if ((car=='I') || (car=='i'))
       {vocales++;}
   if ((car=='O') || (car=='o'))
       {vocales++;}
   if ((car=='U') || (car=='u')) 
       {vocales++;}
  }
  printf("\nEl numero de caracteres del texto es: %d\n", caracteres);
  printf ("El numero de vocales contenidas en el texto es: %d\n", vocales);
  system ("pause");
  return 0;
 }                      
 

  
