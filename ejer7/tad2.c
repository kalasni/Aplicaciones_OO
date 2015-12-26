/* Programa que gestiona mediante un menu las opciones que se pueden
   realizar con un array (inicializarlo, verlo, añadir elemento, borrar
   elemento y salir) utilizando un puntero al array lista y con 
   creación dinamica de memoria (19-03-04) */
   
   
#include <stdio.h>
#include <stdlib.h>

void inicializar (int *);
void mostrar (int *);
void insertar (int *);
void borrar (int *);
int *lista, indice, num, cont=0;

int main()
 {
   
   printf ("Introduzca el numero de elementos que va a tener la lista:\n");
   scanf ("%d", &num);
   lista= (int*) malloc (sizeof (int)* num);
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
  
   void inicializar(int * lista)
   {
     int i;
     for (i=0; i < num; i++)
     {
       *(lista+i)= 0;
     }
   }



 void mostrar (int * lista)
 {
   int i;
   for (i=0; i<cont; i++)
   {
     printf ("%d  ",*(lista+i));
   }
   printf("\n");
 }



 void insertar (int * lista)
 {
   int i, indice;
   if (cont < num)
   {
      printf ("Introduzca un dato: \n");
      scanf ("%d", &indice);
      *(lista+cont)= indice;
       cont++;
   }
   else
   {
     printf ("Error. No se pueden introducir mas datos. \n");
   }
 }


  void borrar (int * lista)
  {
    int i, indice;
    printf ("Introduzca el indice que quiere borrar: \n");
    scanf ("%d", &indice);
    *(lista+indice-1)=0;
    for (i=indice; i<cont; i++)
    {
       *(lista+i-1)= *(lista+i);
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













