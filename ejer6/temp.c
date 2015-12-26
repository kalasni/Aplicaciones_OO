#include <stdio.h>
#include <stdlib.h>
#define max 5

void mediatem (float tem[max]);
void superiores (float tem[max]);
float media;
int cont= 0;
int num;
float tem[max], tempsup[max];

int main()
{
 printf ("Introduzca el numero de temperaturas a introducir: \n");
 scanf ("%d", &num); 

 do
 {
   printf ("Introduzca temperatura: \n");
   scanf ("%f", &tem[cont]);
   cont++;
   
 }while (cont < num);

 mediatem (tem);
 superiores (tem);
 return 0;
}

 void mediatem (float tem[max])
 {
  int i;
  float suma=0;
  for (i=0; i<num; i++)
  {
    suma+= tem[i];
  }
   media= suma/num;
   printf ("La media de las temperaturas introducidas es %f", media);
 }

 void superiores (float tem[max])
 {
   int i=0, contsup=0;

   do
   {
     if (tem[i] > media)
     {
       tempsup[contsup]= tem[i];
       contsup++;
     }
       
     i++;  
   }while (i<num);
   
   printf ("Los temperaturas mayores que la media son: \n");
 
   for (i=0; i<contsup; i++)
   {
     printf ("%f \t", tempsup[i]);
   }
 } 
