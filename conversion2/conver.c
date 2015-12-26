/* Programa extensión de conversion.c. Se trata de hacer lo mismo
   pero en este caso la conversión debe de hacerse en una función.
   (11-03-04) */

#include <stdio.h>
#include <stdlib.h>
float far;
const float cons= 1.8;  /* Este es el valor de 9/5 */
int main()
{
 float m1, m2, m3, m4, m5 ;
 float conver(float x);
 puts ("Introduzca cinco medidas en grados celsius:");
 scanf ("%f %f %f %f %f", &m1, &m2, &m3, &m4, &m5);
 puts ("El resultado de la conversion es: \n");
 conver(m1);
 printf ("%f grados en fahrenheit son: %f \n\n" , m1, far);
 conver(m2);
 printf ("%f grados en fahrenheit son: %f \n\n" , m2, far);
 conver(m3);
 printf ("%f grados en fahrenheit son: %f \n\n" , m3, far);
 conver(m4);
 printf ("%f grados en fahrenheit son: %f \n\n" , m4, far);
 conver(m5);
 printf ("%f grados en fahrenheit son: %f \n\n" , m5, far);
 system ("pause");
 return 0;
} 
