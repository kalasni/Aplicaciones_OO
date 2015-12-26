/* Programa que calcula el precio de un billete de tren dependiendo de 
   varios factores como son, la distancia del recorrido, si la estancia
   en el destino es superior a 7 dias o si se reserva billete de ida y
   de vuelta.  (22-04-03) */

#include <stdio.h>
#include <stdlib.h>
#define tar 0.05

float distancia, precio;
int sig;
int main()
{
 puts ("Introduzca la distancia: \n");
 scanf ("%f", &distancia);
 fflush(stdin);
 puts ("Elija de este menu la opcion que mas le convenga:\n");
 puts ("(1)- Distancia superior a 800km");
 puts ("     Estancia superior a 7 dias");
 puts ("     Desea billete de ida y vuelta \n");
 puts ("(2)- Desea billete de ida y vuelta \n"); 
 puts ("(3)- No desea billete de ida y vuelta \n"); 
 scanf ("%d", &sig);

 switch (sig){
         case 1:
           precio= ((distancia*tar*2)*60)/100;
           printf ("El precio del billete son: %f euros \n", precio);
           break;
	 case 2:
           precio= ((distancia*tar*2)*90)/100;
	   printf ("El precio del billete son: %f euros \n", precio);
           break;
         case 3:
           precio= distancia*tar;
           printf ("El precio del billete son: %f euros \n", precio);
           break;
  }
 
  return 0;
 }   		    
