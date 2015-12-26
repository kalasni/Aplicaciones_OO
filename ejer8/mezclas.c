#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void iniciar_lista (char **lista, int num);
void insertar (char **lista, char *buffer, int num);
void crear_lista (char **lista, int num);
void mostrar_lista (char **lista, int num);
void liberar_lista (char **lista, int num);

char **lista1= NULL;
char **lista2;
int num1, num2;

int main()
{
   
   printf ("Introduzca el tamaño de la primera matriz \n");
   scanf ("%d", &num1);
   fflush (stdin);
   
   lista1= (char**) malloc (num1 * sizeof (char*));
   iniciar_lista (lista1, num1);
   crear_lista (lista1, num1);
   
   printf ("Introduzca el tamaño de la segunda cadena: \n");
   scanf  ("%d", &num2);
   fflush (stdin);
   
   lista2= (char**) malloc (num2 * sizeof (char*));
   iniciar_lista (lista2, num2);
   crear_lista (lista2, num2);
   
   printf ("Contenido de lista 1: \n\n");  
   mostrar_lista (lista1, num1);
   
   printf ("Contenido de lista 2: \n\n");
   mostrar_lista (lista2, num2);
   
   system ("pause");
   return 0;
 }  
     
  
     
        
           
              
                 
 
                       
                                             
 void iniciar_lista (char **lista, int num)
 {
    int i= 0;
    while (i < num)
    {
       lista[i]= NULL;
       i++;
    }
 }      
  
      
                         
 void crear_lista (char **lista, int num)
 {
    char buffer[40];
    char car;
    int i=0;
    
    do
    {
      printf ("Introduzca cadena: \n");
      scanf ("%s", buffer);
      fflush (stdin);
      insertar (lista, buffer, num);
      printf ("Desea continuar? \n");
      car= getchar();
      i++;
                                                                                                                                                         
     } while (i < num && car== 's');    
     
  }
  
  
                                                                                                                                                                                                                                                                                                                                                
 void insertar (char **lista, char *buffer, int num)
 {
     int i, j;
   
     for (i=0; i<num; i++)
     {
        if (lista[i]== NULL || strcmp (lista[i], buffer) >= 0)
        break;
     }
     
     for (j=i; j<num-1; j++)
     {
        lista[j+1]= lista[j];
     }
     
     lista[i]= (char*) malloc (strlen(buffer)+1);
     strcpy (lista[i], buffer);
     
  }                                   
  
  
  
  void mostrar_lista (char **lista, int num)
  {
    int i;
    for (i=0; i<num; i++)
    {
      if (lista[i]!= NULL)
      {
        printf ("%s", lista[i]);
        printf ("\n");
      }
    }
    printf ("\n\n");
  }
  
  
  
  void liberar_lista (char **lista, int num)
  {
     int i;
     
     for (i=0; i<num; i++)
     {
       free (lista[i]);
     }
  }                 
      
                                                                                                                                                                                                                                                                                                                              
