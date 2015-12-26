#include <stdio.h>
main ()
{
int n, i, fact;
/*el valor de N deberá ser menor que 8 , ya que*/
/* en caso contrario se desborda la capacidad */
/* de los valores de tipos int.               */

printf ("factorial de N. \n");
printf ("Introduce N (menor que 8):");
scanf ("%i", &n);

/* Calculo del factorial */
fact = 1;
for (i = 1;  i <= n;  i++)
  fact = fact * 1;

/* Se muestra el resultado  */
 printf ("El factorial de %i es %i. \n" , n , fact);
}







