#include <stdio.h>
#include <stdlib.h>
void inicializar (int lista[50]);
void mostrar (int lista[50]);
void insertar (int lista[50]);
void borrar (int lista[50], int indice);


int main()
{
  int lista[50];
  int num;
  while (num < 6)
  {
  printf ("Elija una de las 5 opciones: \n");
  printf ("\n");
  printf ("(1)- Inicializar array \n");
  printf ("\n");
  printf ("(2)- Ver el array \n");
  printf ("\n");
  printf ("(3)- Insertar un elemento \n");
  printf ("\n");
  printf ("(4)- Borrar un elemento \n");
  printf ("\n");
  printf ("(5)- Salir \n");
  printf ("\n");
  printf ("Introduzca la opcion: \n");
  scanf ("%d", &num); 
  
  switch (num) {
          case 1:
                inicializar (lista);
                break;
          case 2:  
                mostrar (lista);
                break;                
          case 3:
                insertar (lista); 
                break;
          case 4:
                
                      
                
          case 5: 
               system ("pause"); 
               return 0;
   }
  } 
 }
  
