/* Programa al que se le introduce un numero y comprueba si se 
   trata de un numero perfecto. (25-04-03)
   NOTA: Un numero perfecto es aquel que es igual a la suma de 
   todos sus divisores. EJ: 6= 3+2+1 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
 int j, num, resto, suma=0;
 printf ("Introduzca un numero entero: \n");
 scanf ("%d", &num);
 
 for (j=1; j<num; j++)
 {
   resto= num % j;
   if (resto==0)
   {
     suma+= j; // Siempre que el resto sea cero hay un nuevo divisor
   }
 }
 if (num==suma)
 {
   printf ("El numero %d es un numero perfecto \n", num);
 }
 else 
 {
   printf ("El numero %d no es un numero perfecto \n", num);
 }
 system ("pause");
 return 0;
} 
   
      
