#include <stdio.h>
#include <stdlib.h>

int main()
{
 char cad[20];
 puts ("Introduzca una cadena de caracteres: \n");
 while (cad!='\0')
 {
   gets(cad);
   cad++;
 }
 puts (cad);
 system("pause");
 return 0;
 }    
