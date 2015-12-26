#ifndef DICCIONARIO
#define DICCIONARIO
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ficheros.h>
#define FALLO "No esta en el diccionario"
#define max 100
#ifndef PALABRA
#define PALABRA

typedef struct
{
  char *espanol;
  char *ingles;

}palabra;  

#endif

palabra diccionario[max];
int contador=0;

void introducir(void);
char *traducir (char *termino, int modo);
void traduct(void);
int menutraduccion(void);
char buffer[80], buffer2[80];

#endif
