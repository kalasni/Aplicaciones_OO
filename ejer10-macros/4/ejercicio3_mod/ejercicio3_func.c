#include <stdio.h>

int contador=0;
int TAMANNO=50;

void InicializarLista(int vector[])
{
    int i;
    for (i=0; i<TAMANNO; i++)
    {
        vector[i]=0;
    }
    contador=0;
}

void VerLista(int vector[])
{
    int i;
    for (i=0; i<contador; i++)
    {
        printf("%d\n",vector[i]);
    }
}

void InsertarElemento(int vector[], int elemento)
{
    int i;
    if (contador==TAMANNO-1)
    {
        printf("NO SE PUEDEN INSERTAR MAS ELEMENTOS\n");
    }
    else
    {
         vector[contador]= elemento;
         contador++;   
    }
}

void BorrarElemento(int vector[], int posicion)
{
    int i;
    if (posicion>TAMANNO-1 || posicion<1 || vector[posicion-1]==0)
    {
        printf("NO EXISTE ESE ELEMENTO\n");
    }
    else
    {
         vector[posicion-1]= 0;
         contador--;
         for(i=posicion; i<=contador; i++)
         {
                  vector[i-1]=vector[i];
         }   
         printf("Elemento numero %d borrado\n",posicion);
    }
}
