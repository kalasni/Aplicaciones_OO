#include "fechas.h"
#include <iostream>
#include <string>
 
using namespace std;


int main()
{
  fecha misfechas(1, 1, 1990);
  misfechas.imprimir();
  system("pause");
  misfechas.leer();
  system("pause");
  misfechas.imprimir();
  system("pause");
  return 0;
}


// Faltaria implementar más el main.  
