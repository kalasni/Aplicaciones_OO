#include <stdio.h>
#include <stdlib.h>

int main()
{
 int i=0;
 char cad[20], car;
 puts ("Introduzca una cadena de caracteres: \n");
 while ((car= getchar())!='\n' && i<20) 
 {                                   
  cad[i]= car;                           
  i++;           
 }
 puts (cad);
 system("pause");
 return 0;
 }    
