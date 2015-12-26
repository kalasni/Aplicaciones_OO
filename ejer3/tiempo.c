#include <stdio.h>
#include <stdlib.h>
int sem, dias, horas, min, seg, valor, segun;
int main()
{
 printf("Introduzca los segundos:");
 scanf("%d", &valor);
 segun = valor;
 seg= valor % 60;
 valor= valor / 60;
 min= valor % 60;
 valor = valor / 60;
 horas= valor % 24;
 valor = valor / 24;
 dias= valor % 7;
 sem= valor / 7;
 printf("las semanas son %d\n" , sem);
 printf("dias %d\n" , dias);
 printf("horas %d\n" , horas);
 printf("minutos %d\n", min);
 printf("segundos %d\n", seg);
 system("PAUSE");
 return 0;
 }

