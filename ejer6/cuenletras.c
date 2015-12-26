/* Programa al que se introduce un texto por teclado y cuenta el 
   numero de lineas, palabras y aes, ees, ies, oes, ues que contiene.
   (29-04-03) */
   

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int palabras=0, lineas=0;
 char car;
 char vocales[5];  // declaramos un array asociativo (cada indice tendrá una 
 const int SI = 1; // serie de valores).
 const int NO = 0;
 int palabra = NO;
 puts ("Introduzca un texto por teclado");
 puts ("Para finalizar introduzca ctrl-Z: \n");
 
 while ((car=getchar())!= EOF)
 {
   if((car==' ') || (car=='\t') || (car=='\n'))
   {
     palabra= NO;
   }
   else if (palabra==NO)
   {
     palabras++;
     palabra= SI;
   }
     
   if (car=='\n') 
   {
     lineas++;
   }   
   
   if ((car=='A') || (car=='a'))
   { vocales[0]++; }
   if ((car=='E') || (car=='e'))
   { vocales[1]++; }
   if ((car=='I') || (car=='i'))
   { vocales[2]++; }
   if ((car=='O') || (car=='o'))
   { vocales[3]++; }
   if ((car=='U') || (car=='u'))
   { vocales[4]++; }
  } 
   puts ("\n");
   printf ("El texto tiene %d palabras \n\n", palabras);
   printf ("%d lineas \n", lineas);
   printf ("\n");
   printf ("%d aes \n", vocales[0]);
   printf ("%d ees \n", vocales[1]);
   printf ("%d ies \n", vocales[2]);
   printf ("%d oes \n", vocales[3]);
   printf ("%d ues \n", vocales[4]);
   puts ("\n");
   system ("pause");
   return 0;
  } 
