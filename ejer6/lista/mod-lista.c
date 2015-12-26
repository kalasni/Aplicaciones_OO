#include <stdio.h>
#include <stdlib.h>
int cont= 0;

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
  
    void borrar (int lista[50])
    {
      int i, indice;
      if (cont < 50)
      {
        printf ("Introduzca el dato que quiere eliminar: \n");
        scanf ("%d", &indice);
        
      }
      else 
      {
         printf ("Error. No se pueden introducir mas datos. \n");
      }   
    } 
