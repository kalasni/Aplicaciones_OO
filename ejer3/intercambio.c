/* Programa que muestra el valor de dos variables, se intercambia
   dicho valor mediante una variable auxiliar y se muestra con
   printf. (10-04-03) */
   
#include <stdio.h>
#include <stdlib.h>

 int a, b, aux;
 int main()
 {
  a=5;
  b=2;
  printf( "a vale %d y b %d\n", a, b);

  aux=a;
  a=b;
  b=a;

  printf("Intercambiamos las variables\n");
  printf("ahora a vale %d y b %d\n", b, a);
  system ("PAUSE");
  return 0;
}
 
 
