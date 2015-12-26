#include <stdio.h>
#include <stdlib.h>
int a;
float potencia(float n, int x);
int main()
{
 float n;
 int x;
 puts ("Introduzca un numero:");
 scanf ("%f" , &n);
 puts ("Introduzca el exponente:");
 scanf ("%d", &x);
 for (a=1; a<=n; a++)
 {
  printf("%f elevado a %d es: \n", n, a);
  printf ("%f \n", potencia(n, x));
 }
  return 0;
 }
 float potencia (float n, int x)
 {
  float j, total;
  total= 1.0;
  for (j=1; j<=x; j++)
  {
   total= total*n;
   return(total);
  }
}
