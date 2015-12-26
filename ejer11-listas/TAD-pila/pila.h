#ifndef PILA
#define PILA
#include <stdio.h>
#include <stdlib.h>

typedef struct tpila
{
  void *dato;
  struct tpila *siguiente;

}datopila;

void iniciar_pila(datopila **pila);
void apilar(datopila **pila, void *valor);
void *desapilar(datopila **pila);
int pilavacia(datopila *pila);

#endif
  

