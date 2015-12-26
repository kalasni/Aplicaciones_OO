#include <stdio.h>
#include <stdlib.h>

int main()
{
 int array[10], i, j;

  printf ("Introduzca 10 numeros enteros por teclado: \n");
  for (i=0; i<=10; i++)
  {
  scanf ("%d", &array[i]);
  }
  printf ("Los elementos del array son: \n");
  for (j=0; j<10; j++)
  {
    printf ("array[%d] \n", array[j]);
  }
  system("pause");
  return 0;
 }      
 
