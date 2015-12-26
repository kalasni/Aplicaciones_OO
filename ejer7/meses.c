/* Programa al que se le introduce un numero de mes en una
   función y esta devuelve un puntero a una cadena de caracteres
   que muestra el mes correspondiente. (23-5-03) */


#include <stdio.h>
#include <stdlib.h>
char *mes(int num);
char * meses[]= {"Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio",
 "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

int main()
{
 int num;

 puts ("Introduzca el numero de el mes: \n");
 scanf ("%d", &num);
 mes (num);
 printf ("El numero %d corresponde a: %s \n", num, mes(num));
 return 0;
}

 char * mes(int num)
 { 
   return meses[num-1];
 } 




