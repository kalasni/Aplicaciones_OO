
#include <lista-dina.h>
#include <lista-esta.h>
#include "tiempo.h"

int main()
{
  int *listadin, i, j;
  int listaesta[TAMANNO2];
  
  /* printf ("Tamano lista dinamica: \n");
  scanf ("%d", &TAMANNO);
  
  listadin= (int*)malloc(sizeof(int)* TAMANNO); */
  
  /* Si queremos usar las librerias de las dinamicas deberiamos cambiar
     el nombre de las funciones al de las dinamicas y descomentar el 
     codigo anterior. */
     
  InicializarLista2(listaesta);
  INICIO(Insertar);
  for(i=0; i<TAMANNO2; i++)
  {
    InsertarElemento2(listaesta, 9);
    printf("insertado %d\n", i);
  }

    BorrarElemento2(listaesta,  8);
    
  FINAL;


  system("PAUSE");	
  return 0;
}
