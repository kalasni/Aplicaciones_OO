//programa que guarda los primeros 20 numeros primos
// en un array y despues los muestra
//22-01-03
 
#include <iostream.h>

int primo(int x)
{
 int d=2;
 while(x % d != 0) d++;
 return (x==d);
}
const int v = 20;
int array[v], x;
main()
{
 while(v < 20)
 { 
  for(x=0; x<800; x++)
   {
    if (primo(x))
    {
     if (x==2)
     array[v] = x;
    } 
   } 
 } 
 cout << "Los 20 primeros numeros primos son:" << array[v] << " ";
return 0;
} 
