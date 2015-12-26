/* Programa que pide introducir la hora en formato 24 horas y 
   la devuelve en formato 12 horas especificando si es antes del 
   meridiano (AM) o despues del meridiano (PM). (14-04-03) */

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int h, m;
 puts ("Introduzca la hora mediante cuatro caracteres: Ej 12:55");
 scanf ("%d : %d", &h, &m);
 if (h < 12)
   printf ("La hora en formato 12h es: %d : %d AM \n", h, m); 
 else 
   printf ("La hora en formato 12h es: %d : %d PM \n", h-12 , m); 
   system ("pause");
  return 0;
}     
