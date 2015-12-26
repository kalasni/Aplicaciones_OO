#ifndef FICHEROS
#define FICHEROS
#include <stdio.h>
#include <stdlib.h>
#ifndef PALABRA
#define PALABRA

typedef struct
{
  char *espanol;
  char *ingles;

}palabra;  
#endif

void guardar(palabra *diccionario, int contador);
 void cargar(palabra *diccionario, int *contador);
 void imprimir(palabra *diccionario, int contador, int opcion);

#endif

