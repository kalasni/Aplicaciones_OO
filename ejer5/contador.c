#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define SI 1
#define NO 0

int numlin=0, numpal=0, numcar=0;
char car;
int palabra=NO;
int main()
{
 printf ("Introduzca el texto \n");
 while ((car= getchar())!=EOF)
 { 
   numcar++;
   if ((car!=' ') || (car!= '\t') || (car!= '\n'))
   { 
     palabra=NO;
   }
     
   else if (palabra==NO)
   {
     numpal++;
     palabra==SI;
     printf ("El numero");
   } 
   else if(car=='\n')
   {
     numlin++;
   } 
  }
   printf ("El numero de caracteres es: %d \n", numcar);
   printf ("El numero de palabras es : %d \n", numpal);
   printf ("El numero de lineas es: %d \n", numlin);
   system ("pause");
   return 0;
 } 
   
