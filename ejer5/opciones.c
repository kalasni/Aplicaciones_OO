/* Programa que visualiza un menú y pide la introducción de una de
   las opciones (28-04-03) */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int pares(void);
int impares(void);
int multiplos(void);
int main()
{
 int opc;
 do
 {
  puts ("Elija una de las siguiente opciones:\n");
  puts ("(1)- Pares entre 10 y 20 \n");
  puts ("(2)- Impares entre 100 y 150 \n");
  puts ("(3)- Multiplos de 3 entre 10 y 40 \n");
  puts ("(4)- Salir \n");
  scanf ("%d", &opc);
  if ((opc<1) || (opc>4)) 
  printf ("Error, opcion no valida \n"); 
  else 
  {
    switch (opc){
            case 1:
                  pares();
                  break;
            case 2:
                  impares();
                  break;
            case 3:
                  multiplos();
                  break;   
    } 
   }                                     
  }while (opc!=4);
  system ("pause");
  return 0;
 } 
 
 pares(void)
 {
  int par, resto;
  par=10;
   while (par<=20)
   {
    resto= par%2;
    if (resto==0)
    printf ("%d \t", par);
    par++;
   }
    printf ("\n");
  } 
     
 impares(void)
 {
  int impar, resto;
  impar=100;
   
   while (impar<=150)
   {
    resto= impar%2;
    if (resto!=0)
    printf ("%d \t", impar);
    impar++;
   }
    printf ("\n\n");
  }  
  
  multiplos(void)
  {
   int multi, resto;
   multi= 10;
    while (multi<=40)
    {
      resto= multi%3;
      if (resto==0)
      printf ("%d \t", multi);
      multi++;
    }
      printf ("\n\n");
   }     
