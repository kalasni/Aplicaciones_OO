#include "tiempo.h"

int main()
{
  int i; 
  double j;
  INICIO(Bucle de enteros);
  for (i=0; i<30000000; i++);
  FINAL;
  INICIO(Bucle de reales);
  for (j=0; j<30000000; j++);
  FINAL;
  
  system("pause");
  return 0;
}     
