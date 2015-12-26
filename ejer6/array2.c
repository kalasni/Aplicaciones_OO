#include <stdio.h>
#include <stdlib.h>

int main()
{
 char cadena[20];
 puts ("=======================================");
 printf ("INTRODUZCA UNA CADENA POR TECLADO \n");
 puts ("=======================================\n");
 gets (cadena); // gets() coje la cadena hasta que encuentra un \n.
 puts ("\n");
 puts ("=======================================");
 printf ("LA CADENA LEIDA POR TECLADO ES: \n"); 
 puts ("=======================================\n");
 puts (cadena); // puts() muestra la cadena hasta que encuentra '\0'
 puts ("\n");
 system ("PAUSE");
 return 0;
} 
