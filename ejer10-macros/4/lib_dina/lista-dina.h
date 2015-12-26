#ifndef LISTA
#define LISTA
#include <stdio.h>
#include <stdlib.h>

int contador;
int TAMANNO;

void InicializarLista(int *pt);
void VerLista(int *pt);
void InsertarElemento(int *pt, int elemento);
void BorrarElemento(int *pt, int posicion);

#endif
