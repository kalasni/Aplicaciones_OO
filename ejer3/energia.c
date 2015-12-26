/* Programa al que se le introduce una masa en gramos y devuelve
   mediante la formula de la relatividad de Einstein (E=c*m*m*m)
   en Ergios. (11-04-03) */

#include<stdlib.h>
#include<stdio.h>
int main()
{
const float c= 2.997925e+10; /* c seria la velocidad de la luz */
float m, energ;
puts("Introduzca la masa en gramos:");
scanf("%f", &m);
energ= c*(m*m*m);
printf("La energia es %e ergios \n", energ);
system("pause");
return 0;
}

