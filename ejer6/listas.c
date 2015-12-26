#include <stdio.h>
#include <stdlib.h>
void inicializar (int lista[50]);
void mostrar (int lista[50]);
void insertar (int lista[50]);
void borrar (int lista[50], int indice);
int cont= 0;
int indice;


int main()
{
  int lista[50];
  int num;
  do
  {
  printf ("Elija una de las 5 opciones: \n");
  printf ("\n");
  printf ("(1)- Inicializar array \n");
  printf ("\n");
  printf ("(2)- Ver el array \n");
  printf ("\n");
  printf ("(3)- Insertar un elemento \n");
  printf ("\n");
  printf ("(4)- Borrar un elemento \n");
  printf ("\n");
  printf ("(5)- Salir \n");
  printf ("\n");
  printf ("Introduzca la opcion: \n");
  scanf ("%d", &num);
  printf ("\n");

  switch (num) {
          case 1:
                inicializar (lista);
                break;
          case 2:
                mostrar (lista);
                printf ("\n");
                break;
          case 3:
                insertar (lista);
                break;
          case 4:
                printf ("Introduzca el indice del elemento a borrar:\n"); 
                scanf ("%d", &indice);
                borrar (lista, indice);               
                break;
          case 5:
                exit(1);
   }
  }while (num < 6);
 }


   void inicializar (int lista[50])
   {
      int i;
      for (i=0; i<50; i++)
      {
        lista[i]= 0;
      }
    }


    void mostrar (int lista[50])
    {
      int i;
      for (i=0; i<cont; i++)
      {
        printf ("%d \t", lista[i]);
      }
    }

    void insertar (int lista[50])
    {
      int i;
      if (cont < 50)
      {
        printf ("Introduzca un dato: \n");
        scanf ("%d", &lista[cont]);
        cont++;
      }
      else
      {
         printf ("Error. No se pueden introducir mas datos. \n");
      }
    }

    void borrar (int lista[50], int indice)
    {
      int i;
      for (i=(indice-1); i<cont; i++)
      {
        lista[i]= lista[i+1];
      }
      cont--;
    } 
