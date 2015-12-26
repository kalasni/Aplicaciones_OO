/* Programa al que se le introduce 5 valores de medidas en 
   grados celsius y devuelve la conversion a grados fahrenheit. 
   (11-04-03) */
/* Modificación del programa conversión.c para que muestre los resultados
   por columnas (uso del tabulador horizontal /t). (14-04-03) */ 
     
#include <stdio.h>
#include <stdlib.h>
int main()
{
 const float cons= 1.8; /* Este es el valor de 9/5 */
 float m1, m2, m3, m4, m5, far;
 puts ("Introduzca cinco medidas en grados celsius:");
 scanf ("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);
 puts ("Los resultados son los siguientes: \n");
 printf ("%f\t" , (cons*m1)+32);
 printf ("%f\t" , (cons*m2)+32);
 printf ("%f\t" , (cons*m3)+32);
 printf ("%f\t" , (cons*m4)+32);
 printf ("%f\t\n" , (cons*m5)+32);
 system ("pause");
 return 0;
}


