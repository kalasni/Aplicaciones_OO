/* Programa para calcular la suma, resta y producto de dos matrices del mismo orden,
   (las dos tienen que tener el mismo numero de filas y columnas). También muestra
   la traspuesta de la primera matriz. (02-05-03) */
   

#ifndef MATRICES
#define MATRICES
#include <stdio.h>
#include <stdlib.h>
#define MAX 12


void entr_datos(void);
void entr_datos2(void);
void suma (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void resta (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void multip (int f1, int c1, int f2, int c2, float mat1[][MAX],
 float mat2[][MAX], float resul[][MAX]);
void traspues (int f1, int c1, float[][MAX]);

int i, j, f1, f2, c1, c2, num;
float mat1[MAX][MAX], mat2[MAX][MAX], resul[MAX][MAX];


#endif
