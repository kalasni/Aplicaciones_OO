/* Programa al que se le introduce un numero y devuelve un resultado
   diciendo si es primo o no. (25-04-03) */

#include <stdio.h>
#include <stdlib.h>
int primo(int num);
int num;

int main()
{
 puts("Introduzca un numero: \n");
 scanf ("%d", &num);
 primo(num);
 system ("pause");
 return 0;
}

 int primo (int num)
 {
  int d=2;
  while (num % d !=0) d++;
  if  (num==d)
  {
    printf ("El numero %d es primo \n", num);
  }
  else printf ("El numero %d no es primo \n", num);  
 }      

