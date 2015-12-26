/* Programa calculadora para sumar, restar, multiplicar o dividir dos 
   enteros a petición del usuario. (22-04-03) */


#include <stdio.h>
#include <stdlib.h>

 int main()
 {
 int a, b, sig;
 int total;
 puts ("Introduzca dos numeros:\n");
 scanf ("%d %d", &a, &b);
 puts ("\n");
 puts ("Introduzca el numero de la operacion que quiere realizar:\n\n");
 puts ("(1)- DIVIDIR \n");
 puts ("(2)- MULTIPLICAR \n");
 puts ("(3)- SUMAR \n");
 puts ("(4)- RESTAR \n");
 scanf ("%d", &sig);
 switch (sig) {
        case 1 :
             total= a / b;
             printf ("El resultado es: %d \n\n", total);
             break;
        case 2 :  
             total= a * b;
             printf ("El resultado es: %d \n\n", total);
             break;
        case 3 :
             total = a + b;
             printf ("El resultado es: %d \n\n", total);
             break;
        case 4 :
             total= a - b;
             printf ("El resultado es: %d \n\n", total);
             break;
  }           
   system ("pause");
   return 0;
 }           
                        
 
