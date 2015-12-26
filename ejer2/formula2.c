#include <stdio.h>
#include <stdlib.h>
int main()
{
float a, b, c, total;
printf ("Introduzca valor de a ");
scanf ("%f" , &a );
printf ("Introduzca valor de b ");
scanf ("%f" , &b);
printf ("Introduzca valor de c ");
scanf ("%f" , &c);
total= (b*b*b - 5*a*c) / (a*a);
printf ("%f \n" , total);
system ("PAUSE");
return 0;
}
