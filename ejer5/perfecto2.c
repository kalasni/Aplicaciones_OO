#include <stdlib.h>
#include <stdio.h>

int main()
{
 int j, i, num, resto, suma;
 i=2;
 while (i<1000)
 {
   suma=0;
   for(j=1; j<i; j++)
   {
     resto= i % j;
     if (resto==0)
     {
       suma+= j;
     }
   }
     if (j== suma)
     printf ("El numero %d es un numero perfecto \n", i);
     i++;
  }   
  return 0;
}
