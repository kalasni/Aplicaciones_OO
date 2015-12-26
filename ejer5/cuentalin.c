#include <stdio.h>
#include <stdlib.h>

int caracteres=0,palabras=0,lineas=0;  /* contadores de caracteres palabras y líneas */

int main()
{
    const int SI = 1;
    const int NO = 0;
    int palabra= NO;
    char car;
    printf("\nEscribir un texto con el teclado") ;
    printf("\nPara finalizar introducir la marca EOF (ctrl + Z) :\n");
    while ((car = getchar()) != EOF)
    {
        caracteres++;
        if (car == ' ' || car == '\t' || car == '\n')
        {
                palabra = NO;
        }
        else if (palabra == NO)
        {
                ++palabras;
                palabra= SI; 
        }
        if (car == '\n')
        ++lineas;
    }
    printf("\n\nEl numero de caracteres del texto es: %d", caracteres);
    printf("\nEl numero de palabras del texto es: %d", palabras);
    printf("\nEl numero de lineas del texto es: %d\n\n", lineas);
    system("pause");
    return 0;
}
    
    
    
