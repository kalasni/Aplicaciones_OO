#include <iostream.h>

bool perfecto(int n)
{
 int i, acu;
 for(i=1; i<n; i++)
  if( n % i == 0)
   acu+=i;
  return(acu==n);
}
int main()
{

int array[20];
int n, b, a, con, aux;

cout << "Introduzca un numero:";
cin >> n;
aux= n;
a=0;

  for(con=1; con<=aux; con++)
   {
     if(perfecto(n))
      {

        array[a] =n;
	a++;

      }
   }
        for(b=0; b<aux; b++)

	   cout << "los numeros perfectos son:" << array[b] << " ";

    return 0;
 }




  
