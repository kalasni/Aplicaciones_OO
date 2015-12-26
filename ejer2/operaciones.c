/* Programa que realiza las siguientes operaciones y 
   las muestra mediante printf. (10-04-03) */
   
#include <stdlib.h>
#include <stdio.h>
int main()
{
 int a=10, b=2, c=1, d, e;
 float x,y;
 x= a/b;
 printf("x vale: %f\n", x);
 c= (a<b)&& c;
 printf("c vale: %d\n", c);
 d= a+b++;
 printf("d vale: %d\n", d);
 e= ++a-b;
 printf("e vale: %d\n", e);
 y= (float)a/b;
 printf("y vale: %f\n\n", y);
 system("PAUSE");
 return 0;
}


