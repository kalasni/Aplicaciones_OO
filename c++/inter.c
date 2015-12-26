#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void intercambio1(int, int);
void intercambio2(int&, int&);
int main()
{
  int a, b;
  a=8; b=20;
  intercambio1(a, b);
   cout << a << b << endl;
  intercambio2(a, b);
   cout << a << b << endl;
  }
   void intercambio1(int a, int b)
   {
     int aux;
     aux = primero;
     primero = segundo;
     segundo = aux;
   }
   void intercambio2(int& a, int& b)
   {
    int aux;
    aux = primero;
    primero = segundo;
    segundo = aux;
   }     


