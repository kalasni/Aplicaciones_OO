#include <stdlib.h>
#include <stdio.h>
int main()
{
const float cons =1.8;
float m1, m2, m3, m4, m5, far;
puts("introduce 5 temp en grados cel:");
scanf("%f %f %f %f %f" , &m1, &m2, &m3, &m4, &m5);
puts("resultados:\n");
printf("%f en fahren son: %f \n" , m1, (cons*m1)+32);
printf("%f en fahren son: %f \n" , m2, (cons*m2)+32);
return 0;
}
