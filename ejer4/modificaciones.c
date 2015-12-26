/* Ejemplo de la utilización de getchar y putchar */

#include <stdio.h>
void main(void)
{
  int car =0;
  car= getchar();
  fflush(stdin);
  putchar(car);
  car = getchar();
  putchar(car);
  printf("\n");
  system("pause");
  return 0;
 } 
