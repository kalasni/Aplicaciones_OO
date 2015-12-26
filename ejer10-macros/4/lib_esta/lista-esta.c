#include "lista-esta.h"



void InicializarLista2(int vector[])
{
    int i;
    for (i=0; i<TAMANNO2; i++)
    {
        vector[i]=0;
    }
    contador2=0;
}

void VerLista2(int vector[])
{
    int i;
    for (i=0; i<contador2; i++)
    {
        printf("%d\n",vector[i]);
    }
}

void InsertarElemento2(int vector[], int elemento)
{
    int i;
    if (contador2>TAMANNO2-1)
    {
        printf("NO SE PUEDEN INSERTAR MAS ELEMENTOS\n");
    }
    else
    {
         vector[contador2]= elemento;
         contador2++;   
    }
}

void BorrarElemento2(int vector[], int posicion)
{
    int i;
    if (posicion>TAMANNO2-1 || posicion<1 || vector[posicion-1]==0)
    {
        printf("NO EXISTE ESE ELEMENTO\n");
    }
    else
    {
         vector[posicion-1]= 0;
         contador2--;
         for(i=posicion; i<=contador2; i++)
         {
                  vector[i-1]=vector[i];
         }   
         printf("Elemento numero %d borrado\n",posicion);
    }
}
