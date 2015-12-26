#include <stdlib.h>
#include <stdio.h>
#define pi 3.1415
int main()
{
float radio, peri, area;
puts("Introduzca el radio de una circunferencia:");
scanf("%f", &radio);
area= pi *(radio*radio);
peri= 2*pi*radio;
printf("El perimetro del circulo es: %f \n\n", peri);
printf ("El area del circulo es: %f \n\n", area);
system("pause");
return 0;
} 
