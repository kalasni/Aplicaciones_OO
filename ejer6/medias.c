/* Programa al que se le introduce un numero determinado de valores y 
   muestra el maximo, el minimo y la media de la suma de dichos 
   valores. (29-04-03) */

#include <stdio.h>
#include <stdlib.h>

int main()
{
 float media= 0;
 int mini, maxi, num, i, valores[50];
 for (i=0; i<=50; i++)
 {
   valores[i]=0;
 }  
 puts ("Introduzca el numero de valores que quiere introducir \n");
 scanf ("%d", &num);
 for (i=0; i<num; i++)
 { 
   printf ("Introduzca valor \n"),
   scanf ("%d" , &valores[i]);
   fflush(stdin);
 }
  maxi= 0;
  for (i=0; i<num; i++)
  {
    
   if (valores[i]>maxi)
   maxi=valores[i];
    
  }
  
  for (i=0; i<num; i++)
  {
   if (valores[i]< mini)
   mini= valores[i];
  }
    
  for (i=0; i<num; i++)
  {
    media+= valores[i];
  }
  media= media / num;
  printf ("La media es: %f \n", media);
  printf ("El minimo es: %d \n", mini);  
  printf ("El maximo es: %d \n\n", maxi); 
  system ("pause");
  return 0;
 }  
       
  
 
