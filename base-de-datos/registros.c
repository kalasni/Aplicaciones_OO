#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición del tipo registro
typedef struct
{
  char referencia[20];
  char nombre[20];
  double precio;
} registro;


/*          Definición de las funciones basicas de los registros:
*********************************************************************************
   1. IniciarRegistro = Pone todos los campos a 0 o valor nulo.
   2. PedirRegistro = Lee del teclado los campos de un regisdtro y lo devuelve 
   3. VerRegistro = Imprime por pantalla todos los campos de un registro      */

void IniciarRegistro(registro *reg);
registro PedirRegistro();
void VerRegistro(registro reg);

/**************************** FUNCIONES BASICAS DE LOS REGISTROS ***********************
***************************************************************************************/

void IniciarRegistro(registro *reg)
{
  strcpy(reg->referencia,"borrar");
  *(reg->nombre) = 0;
  reg->precio = 0.0;
}

registro PedirRegistro()
{
    registro reg;
    IniciarRegistro(&reg);
    system("cls");
    do
    {
        printf("\nREFERNCIA: ");
        gets(reg.referencia);
    }
    while (strcmp(reg.referencia,"borrar") == 0);
    printf("\nNOMBRE: ");
    gets(reg.nombre);
    printf("\nPRECIO: ");
    scanf("%lf",&reg.precio);
    return reg;
}

void VerRegistro(registro reg)
{
    if (strcmp(reg.referencia, "borrar"))
    {
        printf("REFERNCIA: %s\n", reg.referencia);
        printf("NOMBRE: %s\n", reg.nombre);
        printf("PRECIO: %lf\n", reg.precio);
    }
    else
        printf("ELIMINADO");
}

    



  







