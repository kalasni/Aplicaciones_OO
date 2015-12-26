/* Programa que calcula  los intereses producidos y el capital 
   acumulado en capitalizacion simple y en capitalización
   compuesta. (14-04-05) */
  
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
 int tiempo, total, aux;
 float int_simple, int_compues, int_anu, cap_ini;
 
 puts ("Introduzca el capital inicial:");
 scanf ("%f", &cap_ini);
 fflush(stdin);
 puts ("Introduzca el tiempo en años:");
 scanf ("%d" , &tiempo);
 fflush(stdin);
 puts ("Introduzca el interes anual:");
 scanf ("%f",  &int_anu);
 fflush(stdin);
 aux= (1+int_anu);
 total= pow(aux, tiempo);
 int_simple= cap_ini * int_anu * tiempo;
 int_compues= (cap_ini * total) -1;
 printf ("Los resultados son:\n");
 printf ("En capitalizacion simple:\n\n");
 printf ("Interes simple %f\n", int_simple);
 printf ("Capital acumulado %f\n\n", (int_simple + cap_ini));
 puts ("En capitalizacion compuesta:\n");
 printf ("Interes compuesto %f\n", int_compues);
 printf ("Capital acumulado %f\n", (int_compues + cap_ini));
 system ("pause");
 return 0;
 }
 
