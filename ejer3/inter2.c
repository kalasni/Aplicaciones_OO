
/* Programa que ejemplifica el uso del paso de parametros a una  
   función por referencia y por valor mediante el intercambio de
   dos variables. (15-04-03) */


#include <stdio.h>
#include <stdlib.h>

void intercambio1(int, int);  // Se pasan los parametros por valor.
void intercambio2(int&, int&);  // Aqui se pasan por referencia.
int main()
{
  int a, b;
  a=8; b=20;
  intercambio1(a, b);
   puts ("Antes de intercambiar las variables:\n");
   printf ("%d %d \t\n\n", a, b);
  intercambio2(a, b);
   puts ("Despues de intercambiar las variables:\n");
   printf ("%d %d \n\n", a, b);
   system("pause");
   return 0;
 }
   void intercambio1(int a, int b)
   {
     int aux;
     aux = a;
     a = b;
     b = aux;
   }
   void intercambio2(int& a, int& b)
   {
    int aux;
    aux = a;
    a = b;
    b = aux;
   }     


