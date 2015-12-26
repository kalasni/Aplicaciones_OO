/*  Programa de lista dinamica enlazada (estructura dinamica) que almacena 
    numeros enteros y que cuenta con las funciones insertar elemento, 
    obtener, borrar un elemento y borrar todos los elementos y mostrar 
    la lista completa.  (23-06-03) */


#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
  int dato;
  struct s *siguiente; 
  
}elemento;

void anadir_elemento(elemento **lista, int v);
int menu(void);
void mostrar_lista(elemento *p);
int borrar_elemento(elemento **lista, int n);
elemento *obtener_elemento(elemento *q, int n);
void borrar_todos(elemento **lista);

int main()
{
 elemento *lista= NULL;
 elemento *aux;
 int opcion, v, n;
 
 for (;;)
 {
   opcion= menu();

    switch(opcion) {
                    
                    
            case 1: printf ("Introduzca el valor a introducir: \n");
                    scanf("%d", &v);
                    anadir_elemento(&lista, v);
                    break;
                    
            case 2: printf ("Introduzca el indice del elemento a obtener\n");
                    scanf ("%d", &n);
                    aux= obtener_elemento(lista, n);
                    printf ("El elemento es el %d \n", *aux);  
                    break; 
     
            case 3: printf ("Introduzca el indice del elemento a eliminar\n");
                    scanf ("%d", &n);
                    borrar_elemento(&lista, n);
                    break;
                    
            case 4: borrar_todos(&lista);  
                    break;
                    
            case 5: mostrar_lista(lista);
                    break;
                    
            case 6: return 0;
            
   } 
  } 
 }            
 

elemento *nuevo_elemento()
{
   elemento *q= (elemento*)malloc(sizeof(elemento));
   if(!q)
   {
     printf("No hay suficiente espacio \n");
     exit(1);
   }
   return q;
 }
 
     
void anadir_elemento(elemento **lis, int v)
{ 
  
  elemento *s= *lis;  // s es un puntero auxiliar
  elemento *p= nuevo_elemento(); 
  p->dato= v;
  p->siguiente= s;
  s= p;  
  *lis= s; 
}          



int menu(void)
{
  int resp;
  printf("     MENU DE LISTA DINAMICA \n");
  printf ("\n");
  printf("(1)- INSERTAR ELEMENTO EN LA LISTA \n");
  printf("(2)- OBTENER UN ELEMENTO \n");
  printf("(3)- BORRAR UN ELEMENTO \n");
  printf("(4)- BORRAR TODOS LOS ELEMENTOS DE LA LISTA \n");
  printf("(5)- MOSTRAR TODOS LOS ELEMENTOS DE LA LISTA \n");
  printf("(6)- SALIR \n");
  scanf("%d", &resp);
  
  return resp;
}  



 
 
 void mostrar_lista(elemento *p)
 {
   int i;
   elemento *q= p;
   
   for(i=1; q!=NULL; i++)
   {
     printf("Elemento %d : %d \n", i, q->dato);
     q= q->siguiente;
   }
 }   
 
 
 int borrar_elemento(elemento **lista, int n)
 {
   int i= 1;
   elemento *p= *lista;
   elemento *anterior= p;
   elemento *actual= p;
   
   if(p==NULL)
   {
     printf("Lista vacia \n");
     return 0;
   }
   
   if(n < 0)
   {
     printf("Elemento no valido \n");
     return 0;
   }  
   
   for(i=1; actual!=NULL && i<n; i++)
   {
     anterior= actual;
     actual= actual->siguiente; 
   }         
   
   if(!actual)
   {
     printf("Elemento no valido \n");
     return 0;
   }     
   
   if(actual==p)  // Si es el primer elemento
   {
     p=actual->siguiente;
   }  
   else 
   {
     anterior->siguiente= actual->siguiente;
   }  
     free(actual);
     *lista= p;
     return 1;
 }    
 
 
 elemento *obtener_elemento(elemento *q, int n)
 {
   int i= 1;
   if(q==NULL)
   {
     printf("Lista vacia\n");
     return NULL;
   }
   if(n < 0)
   { 
     printf("Elemento no valido \n");
     return NULL;
   } 
     while(q!= NULL && i < n)
     {
       q= q->siguiente;
       i++;
     }  
     return q;
   
}       


void borrar_todos(elemento **lista)
{
  elemento *q= *lista;
  elemento *p= q;
  
  while(q!=NULL)
  {
    q= q->siguiente;
    free(p);
    p= q;
  }
  *lista= NULL;
}    
