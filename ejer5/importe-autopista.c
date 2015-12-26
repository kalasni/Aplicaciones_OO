/* Programa que utiliza un array de punteros para elejir mediante un
   menu la función adecuada para devolver el importe de un peaje de
   autopista, introduciendo en dicha función la distancia a recorrer
   en Km y en el caso de los camiones las Tm que transporta.
   (25-03-04) */
   

#include <stdio.h>
#include <stdlib.h>
float bicicletas();
float mot_coches();
float camiones();
int main()
{
  int veh;
  float (*importe[])()= {bicicletas, mot_coches, camiones};
  puts ("Marque el tipo de vehiculo \n");
  puts ("(1)- Bicicletas\n");
  puts ("(2)- Motos y coches \n");
  puts ("(3)- Camiones \n");
  scanf ("%d", &veh);
  printf ("El importe a pagar es %f euros \n\n", (*importe[veh-1])());
  system ("pause");
  return 0;
 }  
 
 float bicicletas()
 {
   float total;
   total= 100;
   return total;
 }
 
 float mot_coches()
 {
   float total, km; 
   puts ("Introduzca distancia a recorrer: \n");
   scanf ("%f", &km);
   total= km*30;
   return total;
 }
 
 float camiones()
 {
   float total, km, tm;
   puts ("Introduzca distancia a recorrer: \n");
   scanf ("%f", &km);
   puts ("Introduzca Tm que transporta el camion: \n");
   scanf ("%f", &tm);
   total= (km*30)+(tm*25);
   return total;
 }      
