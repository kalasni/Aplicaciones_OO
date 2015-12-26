#include <stdio.h>
#include <stdlib.h>
int main()
{
 enum array1 {ma, ba, bi, de, at};
 enum array2 {hu=5, es=6, sa=7, be=8, se=9};
 int a, b;
 for (a=ma; a<=at; a++)
 {
   
   for(b=hu; b<=se; b++)
   {
     printf ("%d juega contra %d\n", a, b);
   }
 }
 system ("pause");
 return 0;
}     
