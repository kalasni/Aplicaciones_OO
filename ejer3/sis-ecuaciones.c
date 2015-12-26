/* Programa que resuelve un sistema de ecuaciones lineales 
   (14-04-03) */

#include <stdlib.h>
#include <stdio.h>

int main()
{
 float a, b, c, d, e, f, x, y, den;
 puts ("Introduzca el valor de a:");
 scanf("%f", &a);
 puts ("Introduzca el valor de b:");
 scanf ("%f", &b);
 puts ("Introduzca el valor de c:");
 scanf ("%f", &c);
 puts ("Introduzca el valor de d:");
 scanf ("%f", &d);
 puts ("Introduzca el valor de e:");
 scanf ("%f", &e);
 puts ("Introduzca el valor de f:");
 scanf ("%f", &f);
 den = (a*e)-(b*d);
 if (den == 0)
 puts ( "El sistema no tiene solucion real. El denominador es 0");
  else
  {
   x= ((c*b)-(b*f))/den;
   y= ((a*f)-(c*d))/den;
   printf ("Los resultados de x y de y son:\n");
   printf ("x = %f \n", x);
   printf ("y = %f \n", y);
  }
   system ("pause");
   return 0;
 } 
