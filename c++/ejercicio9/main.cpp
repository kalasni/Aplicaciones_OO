#include <iostream>
#include <stdlib.h>
#include "EnteroAleatorio.h"

using namespace std;

int main(int argc, char *argv[])
{
  EnteroAleatorio prueba(10,20);
  for (int i=0; i<5 ; i++)
  cout << prueba.GenerarAleatorio() << endl ;
  system("PAUSE");	
  return 0;
}
