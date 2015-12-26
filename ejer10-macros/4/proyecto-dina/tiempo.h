#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifndef TIEMPO
#define TIEMPO
#if defined(TEMP_COMP)  //con otro compilador comenzar delante de #if un */
clock_t inicio, final;  // y terminarlo al comienzo del 1º #endif 
#define INICIO(parametro) inicio=clock(); \
        printf("Inicio tiempo de %s \n", #parametro);

#define FINAL final=clock(); \
        printf("\n\n tiempo empleado = %ld miliseg \n", (final-inicio));
  #endif   // cierra if defined(TEMP_COMP)
#endif
