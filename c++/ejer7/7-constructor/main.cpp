#include "fechas.h"
#include <iostream>
#include <string.h>
 
using namespace std;


int main()
{
  // Inicialización del constructor y a la vez se crea el objet misfechas.
  fechas misfechas(1, 1, 1900); 
  misfechas.imprimir();
  system("pause");
  misfechas.leer_teclado();
  system("pause");
  misfechas.imprimir();
  system("pause");
  return 0;
}  
