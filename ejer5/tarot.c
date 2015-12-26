/* Programa al que se le introduce una fecha de nacimiento y calcula
   y muestra el numero del tarot. (24-04-03) */


#include <stdio.h>
#include <stdlib.h>


int main()
{
  int dd, mm, aa, ddo, resto, tarot;
  printf ("Introduce la fecha de tu cumpleaños: \n");
  scanf ("%d  %d  %d", &dd, &mm, &aa);
  printf ("\n");
  tarot= dd + mm + aa;
  while (tarot > 9)
  {
    ddo= tarot;
    tarot= 0;
    do {
        resto= ddo%10;
        tarot+= resto;
        ddo= ddo/10;
        } while (ddo!= 0);
   }
    printf ("Tu numero del tarot es el %d \n\n", tarot);
    system ("pause");
    return 0;   
 }       
 
