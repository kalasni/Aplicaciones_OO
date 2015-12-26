/* Programa que gestiona mediante un menu las opciones que se pueden
   realizar con un array (inicializarlo, verlo, añadir elemento, borrar
   elemento y salir) utilizando un puntero a la lista. (19-03-04) */
   
   
#include <stdio.h>
#include <stdlib.h>
#define max 50

void inicializar (int *);
void mostrar (int *);
void insertar (int *);
void borrar (int *);
int *pt;
int lista[max], indice, cont=0;

int main()
 {
   char opci;

     for (;;)
     {
     opci= menu();
     switch (opci) {
           case 1: inicializar(lista);
           break;
           case 2: insertar(lista);
           break;
           case 3: borrar(lista);
           break;
           case 4: mostrar(lista);
           break;
           case 5: system ("pause");
                   return 0;
     }
    } 
  }


/* Inicializar agenda */
  
   void inicializar(int *pt)
   {
     int i;
     for (i=0; i < max; i++)
     {
       *(pt+i)= 0;
     }
   }



 void mostrar (int *pt)
 {
   int i;
   for (i=0; i<cont; i++)
   {
     printf ("%d  ",*(pt+i));
   }
   printf("\n");
 }



 void insertar (int *pt)
 {
   int i, indice;
   if (cont < max)
   {
      printf ("Introduzca un dato: \n");
      scanf ("%d", &indice);
      *(pt+cont)= indice;
       cont++;
   }
   else
   {
     printf ("Error. No se pueden introducir mas datos. \n");
   }
 }


  void borrar (int *pt)
  {
    int i, indice;
    printf ("Introduzca el indice que quiere borrar: \n");
    scanf ("%d", &indice);
    *(pt+indice-1)=0;
    for (i=indice; i<cont; i++)
    {
       *(pt+i-1)= *(pt+i);
    }
    cont--;
  } 


 /* Seleccionamos operacion a realizar */
  
  
  int menu (void)
  {
    int c;
    printf ("(1) - INICIALIZAR LA LISTA \n");
    printf ("(2) - INTRODUCIR UN ELEMENTO \n");
    printf ("(3) - BORRAR UN ELEMTO \n");
    printf ("(4) - MOSTRAR LISTA \n");
    printf ("(5) - SALIR \n");
    printf ("\n\n");
    printf ("INTRODUZCA OPCION: \n");
    scanf ("%d", &c);
    fflush(stdin);
    return c;   
   }      













