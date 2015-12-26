/* Programa que calcula el resultado de la formula*/


#include <stdio.h>
#include <stdlib.h>
int main()
{
float a, b, c, total;
a=3;
b=4;
c=2;
total= (b*b*b - 5*a*c) / (a*a);
printf ("%f \n" , total);
system ("PAUSE");
return 0;
}


