/* Programa que devuelve el tamaño en bits de los tipos primitivos 
   mediante sizeof. (09-04-03) */

#include <stdio.h>
#include <stdlib.h>
int main()
{
  char a, re, ri;
  unsigned char b;
  short int c;
  unsigned short int d;
  long int e;
  unsigned long int f;
  float g;
  double h;
  long double i;
  a=sizeof a*8; b=sizeof b*8; c=sizeof c*8; d=sizeof d*8; e=sizeof e*8;
  f=sizeof f*8; g=sizeof g*8; h=sizeof h*8; re=sizeof i*8;
  printf("El tamaño de char es: %d bits\n\n" , a);
  printf("El tamaño de unsigned char es: %d bits\n\n" , b);
  printf("El tamaño de short int es: %d bits\n\n" , c);
  printf("El tamaño de unsigned int es: %u bits\n\n" , d);
  printf("El tamaño de long int es: %ld bits\n\n" , e);
  printf("El tamaño de unsigned long int es: %u bits\n\n" , f);
  printf("El tamaño de float es: %f bits\n\n" , g);
  printf("El tamaño de double es: %f bits\n\n" , h);
  printf("El tamaño de long double es: %d bits\n\n" , re);
  system ("PAUSE");
  return 0;
 }
