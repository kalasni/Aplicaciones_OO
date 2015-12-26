
#include <stdio.h>
#include <stdlib.h>


typedef struct s
{
  void *dato;
  struct s *siguiente; 
  
}elemento;

int tamano(elemento *lista);
void anadir(int posicion, void *valor, elemento **lista);
void anadir_alprincipio(elemento **lista, void *valor);
void anadir_alfinal(elemento **lista, void *valor);
void *obtener(elemento *lista, int posicion);
void *obtener_primero (elemento *lista);
void *obtener_ultimo(elemento *lista);
int borrar(elemento **lista, int posicion);
elemento *nuevo_elemento();
int *nuevo_dato();

int main()
{
  elemento *lista= NULL;
  int *valor= NULL;
  int opcion= 0;
  int posicion, i= 1; 
  while(1)
  {
    system("cls");
    opcion= menu();
    switch (opcion) {
    
             case 1: if((valor= nuevo_dato())!=NULL)
                     {
                       printf ("Introduzca la posicion en donde introducirlo: \n");
                       scanf ("%d", &posicion);
                       fflush (stdin);
                       anadir(posicion, valor, &lista);
                     }
                     break;
      
             case 2: if((valor= nuevo_dato())!=NULL)
                     {
                       anadir_alprincipio(&lista, valor);
                     }
                     break;
                     
             case 3: if((valor= nuevo_dato())!=NULL)
                     {
                       anadir_alfinal(&lista, valor);
                     } 
                     break;
                     
             case 4:
                       printf ("Introduzca la posicion a borrar: \n");
                       scanf ("%d", &posicion);
                       fflush (stdin);
                       
                       if (borrar (&lista, posicion))
                       {
                         printf ("Se ha borrado \n");
                       }  
                       else printf ("No se ha podido borrar \n"); 
                       break;
                      
             case 5:  if (borrar_primero(&lista))
                      {
                        printf ("Se ha borrado\n");
                      }
                      else 
                      {
                        printf ("No se ha podido borrar el primero \n");
                      }
                      break;
                      
             case 6:  if (borrar_ultimo(&lista))
                      {
                        printf ("Se ha borrado\n");
                      }
                      else 
                      {
                        printf ("No se ha podido borrar el ultimo \n");
                      }
                      break;      
                      
             case 7:  
                      while (borrar(&lista, i++)); //borrar todos
                      break;
                      
             case 8:  printf("Posicion: \n");
                      scanf ("%d", &posicion);
                      fflush(stdin);
                      
                      if((valor=(int*)obtener(lista, posicion))!=NULL)
                      {
                        printf ("El valor %d es: %d", posicion, *valor);
                      }
                      else 
                      {
                        printf("No existe el %d", posicion);
                      }    
                      break;
                      
             case 9:  if((valor=(int*)obtener_primero(lista))!=NULL)
                      {
                        printf ("El primero es %d\n", *valor);
                      }
                      else 
                      {
                        printf("No existe el primero \n");
                      }    
                      break;   
                      
             case 10: if((valor=(int*)obtener_ultimo(lista))!=NULL)
                      {
                        printf ("El ultimo es %d\n", *valor);
                      }
                      else 
                      {
                        printf("No existe el ultimo \n");
                      }    
                      break;    
                      
             case 11: for (i=1; i<=tamano(lista); i++)
                      {
                        if((valor= (int*)obtener(lista, i))!=NULL)
                        {
                          printf("Elemento %d : %d", i, *valor);
                        }
                        else 
                        {
                          printf ("ERROR \n");
                        }
                      }
                      break;
                      
             case 12: printf("El tamano es: %d \n", tamano(lista));
                      break;
                      
             case 0: exit(0);
                                                                
     }               
      system("pause");
  }
}                     



int tamano(elemento *lista)
{
   int i;
   for (i=0; lista!=NULL; i++)
   {
     lista= lista->siguiente;
   }  
   return i;
}  


void anadir(int posicion, void *valor, elemento **lista)
{ 

  elemento *ptro= *lista;  // s es un puntero auxiliar
  elemento *anterior= ptro;
  int i= 1;
  elemento *q= nuevo_elemento();
  q->dato= valor;
  
  if (posicion < 1 || posicion > (tamano(ptro)+i))
  {
    printf("No se puede insertar en %d\n", posicion);
    return;
  }  
  
  if(posicion==1)
  {
    q->siguiente= ptro;
    ptro= q;
  }
  else 
  {
     while(anterior!=NULL && i<posicion-1)
     {
       anterior= anterior->siguiente;
       i++;
     } 
     q->siguiente= anterior->siguiente;
     anterior->siguiente= q;
  }
  *lista= ptro;
  return;      
}          


void anadir_alprincipio(elemento **lista, void *valor)
{
  elemento *p= *lista;
  elemento *q= nuevo_elemento();
  q->dato= valor;
  q->siguiente= p;
  p= q;
  *lista= p;
}  


 void anadir_alfinal(elemento **lista, void *valor)
 {
   elemento *p= *lista;
   elemento *q= nuevo_elemento();
   q->dato= valor;
   q->siguiente= NULL;
   
   if (p==NULL)
   {
     *lista= q;
   }
   else 
   {
     while(p->siguiente!= NULL)
     {
       p=p->siguiente;
     }
     p->siguiente=  q;
   }
 }    
 
  

void *obtener(elemento *lista, int posicion)
{
   elemento *p= lista;
   int i= 1;
   
   if(p== NULL)
   {
     printf("lista vacia \n");
     return NULL; 
   }  
   
   for(i=1; i<posicion && p!= NULL; i++)
   {
     p= p->siguiente;
   }
   
   if(p==NULL)
   {
     printf ("Posicion incorrecta \n");
     return NULL;
   }    
   return p->dato;
}     



void *obtener_ultimo(elemento *lista)
{
   int i= 1;
   elemento *p= lista;
   if (p==NULL)
   {
     printf("Lista vacia \n");
     return NULL;
   }
   
   for (i=1; i<tamano(p) && p->siguiente!= NULL; i++)
   {
     p=p->siguiente;
   }
   
   if(p!=NULL) return p->dato;
   
   else 
   {
     printf ("ERROR");
     return NULL;
   }
 }
 
 
    
void *obtener_primero (elemento *lista)
{                                                              
   int i= 1;
   elemento *p= lista;
   
   if (p==NULL)
   {
     printf("Lista vacia \n");
     return NULL;
   }
   return p->dato;
}  


int borrar(elemento **lista, int posicion)
{
   elemento *p= *lista;
   elemento *actual= p;
   elemento *anterior= p;
   int i= 1;
   
   if(posicion < 1 || posicion > tamano(p) || p== NULL)
   {
     return 0;
   }  
   if(posicion==1)
   {
     p= p->siguiente;
   }
   else 
   {
     while(actual!= NULL && i < posicion)
     {
        anterior= actual;  
        actual= actual->siguiente;
     }   
     anterior->siguiente= actual->siguiente;
   }
   free(actual);
   *lista= p;
   return 1;
 }   


int borrar_primero(elemento **lista)
{
   return borrar(lista, tamano(*lista));
}   
     

int borrar_ultimo(elemento **lista)
{
   return borrar(lista, tamano(*lista));
}

          
/* Esta funcion es del main() */

int *nuevo_dato()
{
  int *dato;
  int valor;
  printf ("Introduzca un valor entero: \n");
  
  if(scanf("%d", &valor)!= 1)
  {
    printf ("No se ha leido entero\n");
    return NULL;
  }
  
  if ((dato=(int*) malloc(sizeof(int)))==NULL)
  {
    printf ("No hay memoria suficiente\n");
    return NULL;
  }
  *dato= valor;
  return dato;
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


int menu()
{
  int opc;
  printf (" MENU DE LISTA ENLAZADA \n");
  printf (" (1) - ANADIR ELEMENTO A LA LISTA \n");
  printf (" (2) - ANADIR ELEMENTO AL PRINCIPIO DE LA LISTA \n");
  printf (" (3) - ANADIR ELEMENTO AL FINAL DE LA LISTA \n");
  printf (" (4) - BORRAR UN ELEMENTO \n");
  printf (" (5) - BORRAR EL PRIMER ELEMENTO DE LA LISTA \n");
  printf (" (6) - BORRAR EL ULTIMO ELEMENTO DE LA LISTA \n");
  printf (" (7) - BORRAR TODA LA LISTA \n");
  printf (" (8) - OBTENER UN ELEMENTO DE LA LISTA \n");
  printf (" (9) - OBTENER EL PRIMER ELEMENTO DE LA LISTA \n");
  printf (" (10)- OBTENER EL ULTIMO ELEMENTO DE LA LISTA \n");
  printf (" (11)- MOSTRAR TODOS LOS ELEMENTOS DE LA LISTA \n");
  printf (" (12)- MOSTRAR EL TAMANO DE LA LISTA \n");
  printf (" (0) - SALIR DEL PROGRAMA \n");
  
  scanf ("%d", &opc);
  return opc;
}  
  
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
