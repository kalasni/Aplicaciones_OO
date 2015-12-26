#ifndef EJERCICIOS3
#define EJERCICIOS3
#include <lista.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{

  char *nombre;
  int notas[4];
  
} alumno;

alumno *nuevo_alumno();
int menu();
float media(elemento *clase);
void mostrar(alumno a);
elemento *lista;

#endif  
