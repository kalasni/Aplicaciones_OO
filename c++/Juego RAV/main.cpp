#include <iostream>
#include <stdlib.h>

#include "Control.h"

using namespace std;

int main(int argc, char *argv[])
{
  int intentos= 8;
  if (argc ==2)
  {
    intentos= atoi(argv[1]);
  }
  Control juego;
  juego.Jugar(intentos);
  system("PAUSE");	
  return 0;
}
