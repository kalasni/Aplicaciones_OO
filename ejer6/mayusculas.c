/* Programa al que se le introduce por teclado una palabra en 
   minusculas y la devuelve con letras mayusculas. (30-04-03) */

#include <stdio.h>
#include <stdlib.h>
#define MAX 40

int main()
{
 char pal[MAX];
 int j, i=0;
 for (j=0; j<MAX; j++)
 {
   pal[j]=0;
 }
 puts ("=============================================");
 puts ("Introduzca una palabra en letras minusculas: ");
 puts ("=============================================\n");
 scanf ("%s", &pal); // Utilizando scanf y %s leera la cadena hasta
 fflush (stdin);     // que encuentre un espacio.
 printf ("\n");
 puts ("=============================================");
 puts ("La palabra en letras mayusculas es: ");
 puts ("=============================================\n");
 while (pal[i] !='\0')
 {
  printf ("%c", pal[i]-32);
  i++;
 }
 puts ("\n");
 system ("PAUSE");
 return 0;
}  
