#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

 struct clientes
 {
   char *nombre;
   char *direccion;
   char dni[15];
   int potencia;
   float consumo;
 };

 int entr_datos (struct clientes **, int num);
 void mostrar_datos (char *aux, struct clientes*);
 void borrar_cliente (struct clientes *);
     
 int num;
 char aux;
 
 int main()
 {
   
    struct clientes *p = NULL;
    
    for (;;)
    {
    
      char opci;
      opci = menu();
           
           switch (opci) {
               case 1: printf ("Introduzca numero de clientes: \n");
                       scanf ("%d", &num);
                       entr_datos (&p, num);
                       break;    
                   
               case 2: printf ("Introduzca el dni del cliente a mostrar: \n");
                       scanf ("%c", &aux);
                       mostrar_datos (aux, p);
                       break;
                                                                                                                                                                                                                                                                                                      
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
               case 3: borrar_cliente (p);
	               break;
		       
	       
	       case 4: system ("pause");
                       return 0;
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
          }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                

                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    }  
  }      
  


    int entr_datos (struct clientes **ptro, int num)
    {
       int i;
       char aux[80];

       struct clientes *pt;
       pt= (struct clientes*)malloc(num* sizeof (struct clientes));

       printf ("Entrada datos del cliente: \n"); 

       for (i=0; i<num; i++)
       {
          printf ("Nombre del cliente: \n");
          gets (aux);
          (pt+i)->nombre= malloc(strlen(aux)+1);
          strcpy ((pt+i)->nombre, aux);
          
          printf ("Direccion del cliente: \n");
          gets (aux);
          (pt+i)->direccion= malloc(strlen(aux)+1);
          strcpy ((pt+i)->direccion, aux);
           
          printf ("numero de DNI: \n");
          gets ((pt+i)->dni);

          printf ("Introduzca potencia contratada: \n");
          gets (aux);
          (pt+i)->potencia = atoi(aux);
	  
          printf ("Introduzca cantidad consumida: \n");
          gets (aux);
          (pt+i)->consumo = atoi(aux);
	  
	  printf ("\n\n");

       }
        *ptro=pt;
     }  

                   
     

     
     int menu(void)
     {
       int a;
       
       printf ("(1) - INTRODUCIR CLIENTES \n");
       printf ("(2) - MOSTRAR FACTURA DE CLIENTE \n");
       printf ("(3) - ELIMINAR CLIENTE \n");
       printf ("(4) - SALIR \n");
       
       scanf ("%d", &a);
       return a;
     }  
     
     
     
     

     void borrar_cliente (struct clientes *p)
     { 
       int n;
       printf ("Introduzca el dni del cliente que desea eliminar: \n");
       scanf ("%d", &n);
       (p+n)->nombre= NULL;
       num--;
     }  

     
     

     
     void mostrar_datos (char *aux, struct clientes *p)
     { 
        float consu_total;
	int i;
	
      for (i=0; i<num; i++)
      {
      
        if (!strcmp (aux, (p+i)->dni))
	{
        printf ("%s \n", (p+i)->nombre);
        printf ("%s \n", (p+i)->direccion);
        printf ("%s \n", (p+i)->dni);
        printf ("%d \n", (p+i)->potencia);
        consu_total= (p+i)->consumo;
        printf ("El consumo es igual a: %f ", (consu_total* 8.04));
        printf ("\n\n");
       }

     }
    }
        
       
