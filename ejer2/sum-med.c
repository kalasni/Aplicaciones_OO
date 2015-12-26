/* Programa que calcula la suma y la media de 4 valores tipo int.
   (08-04-03) */

#include <stdio.h>
#include <stdlib.h>
float total, media, val1, val2, val3, val4;
 int main()
 {
  printf ("Introduzca cuatro valores; ");
  scanf ("%f %f %f %f", &val1, &val2, &val3, &val4);
  total = val1 + val2 + val3+ val4;
  media = total / 4;
  printf ("La suma total es %f\n" , total);
  printf ("La media es %f " , media);
  system ("PAUSE");
  return 0;
 }
