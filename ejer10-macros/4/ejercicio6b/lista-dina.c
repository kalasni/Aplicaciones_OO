
#include <lista-dina.h>
#include <stdio.h>

void InicializarLista(int *pt)
{
    int i;
    for (i=0; i<TAMANNO; i++)
    {
        pt[i]=0;
    }
    contador=0;
}

void VerLista(int *pt)
{
    int i;
    for (i=0; i<contador; i++)
    {
        printf("%d\n",*(pt+i));
    }
}

void InsertarElemento(int *pt, int elemento)
{
    int i;
    if (contador==TAMANNO)
    {
        printf("NO SE PUEDEN INSERTAR MAS ELEMENTOS\n");
    }
    else
    {
         *(pt+contador)= elemento;
         contador++;   
    }
}

void BorrarElemento(int *pt, int posicion)
{
    int i;
    if (posicion>TAMANNO-1 || posicion<1 || *(pt+posicion-1)==0)
    {
        printf("NO EXISTE ESE ELEMENTO\n");
    }
    else
    {
         *(pt+posicion-1)= 0;
         contador--;
         for(i=posicion; i<=contador; i++)
         {
                  *(pt+i-1)=*(pt+i);
         }   
         printf("Elemento numero %d borrado\n",posicion);
    }
}
