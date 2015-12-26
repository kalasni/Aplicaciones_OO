/* Programa al que se introduce un texto por teclado y cuenta el 
   numero de lineas, palabras y aes, ees, ies, oes, ues que contiene.
   (29-04-03) */
   

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int palabras=0, lineas=0, a=0, e=0, i=0, o=0, u=0;
 char car;
 
 const int SI = 1;
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
   { a++; }
   if ((car=='E') || (car=='e'))
   { e++; }
   if ((car=='I') || (car=='i'))
   { i++; }
   if ((car=='O') || (car=='o'))
   { o++; }
   if ((car=='U') || (car=='u'))
   { u++; }
  } 
   
   printf ("El texto tiene %d palabras \n", palabras);
   printf ("%d lineas \n", lineas);
   printf ("\n");
   printf ("%d aes \n", a);
   printf ("%d ees \n", e);
   printf ("%d iis \n", i);
   printf ("%d oos \n", o);
   printf ("%d uus \n", u);
   puts ("\n");
   system ("pause");
   return 0;
  } 
