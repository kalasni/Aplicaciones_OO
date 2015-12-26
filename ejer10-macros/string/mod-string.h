#ifndef CADENAS
#define CADENAS
#include <stdio.h>
#include <stdlib.h>



int menu (void);
int long_cad (char *cadena);
char *copiar_cad (char *cadena, char *cadena2);
char *concate_cad (char *cadena, char *cadena2);
char *punt_cad (char *cadena, char car);
int comp (char *cadena, char *cadena2);
char *cad_minus (char *cadena);
char *cad_mayus (char *cadena);

char car, cadena[30];
char cadena2[30];

#endif 

