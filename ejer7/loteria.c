/* Programa que simula una maquina de loteria primitiva generando una 
   serie de numeros aleatorios menores de 100 (6 numeros) y despues los 
   muestra.
   Utiliza las funciones srand() para generar la semilla mediante
   time (que coje la hora del sistema y la convierte en milisegundos)
   y rand() para la generación de los numeros. (20-05-03) */


#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define cont 6

int main(void)
{
  int i, j, aux, numero[6];
  char tecla;
  
  
  printf ("\n\n\n");
  printf ("              PULSE CUALQUIER TECLA PARA GENERAR Y 'N' PARA SALIR: \n"); 
  while ((tecla= getchar())!= 'n')
  {
    fflush (stdin);
    system ("cls");
    srand(time(NULL));  // Cada vez que se llama a time da valor en miliseg.
  
    for (i=0; i<cont; i++)
    {
       do 
       {
         numero[i]= rand() % 49;  // Hace el modulo e impide que sean mayores de 100.   
       } while (numero[i]==0);
        
    }
    
    
    
       
    
    for (i=0; i<cont-1; i++)
    {
      for (j=i+1; j<cont; j++)
      {
         if (numero[i] > numero[j])
         {
           aux= numero[i];
           numero[i]= numero[j];
           numero[j]= aux;
         }
      }
    }

     printf ("\n\n");
     printf ("           Los numeros entre 1 y 49 son: \n\n");
     for (i=0; i<cont; i++)
     {
        printf ("        %d  " , numero[i]);
     }
      printf ("\n\n");
   
  }
     
 return 0;
}
