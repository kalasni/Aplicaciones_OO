#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define pi 3.1415
int main()
{
float cat_o, cat_c, hip, ang;
puts("Introduzca el valor de los catetos:");
scanf("%f %f" , &cat_o, &cat_c);
hip= sqrt(cat_o*cat_o + cat_c*cat_c);
ang= 180 / pi * asin(cat_o / hip);   /* Asigna angulo en grados */
printf("Hipotenusa = %f \n" , hip);
printf ("Angulo = %f \n" , ang);
printf ("El otro angulo = %f \n", 90 - ang);
system("pause");
return 0;
}
