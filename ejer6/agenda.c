#include <stdio.h>
#include <stdlib.h>
#define max 100

struct dir {
    char nombre[30];
    char direccion[40];
    char edad[3];
    char sexo[7];
    char telefono[12];
 } agenda[100];

 void inic_agenda(void), intro(void);
 void borrar(void), mostrar(void);
 int menu(void), busca_libre(void);
 int cont=0;
 
 int main()
 {
   char opci;
   inic_agenda();     // Inicializa el array de estructura.
   
   
     for (;;)
     {
     opci= menu();
     switch (opci) {
           case 1: intro();
           break;
           case 2: borrar();
           break;
           case 3: mostrar();
           break;
           case 4: 
                   return 0;
     }
    } 
    return 0;
  }
  
                                 
  /* Inicializar agenda */
  
   void inic_agenda(void)
   {
     int i;
     for (i=0; i < max; i++)
     {
       agenda[i].nombre[0]= '\0';
     }
   }
   
   
  /* Seleccionamos operacion a realizar */
  
  
  int menu (void)
  {
    int c;
    printf ("(1) - INTRODUCIR UN NOMBRE \n");
    printf ("(2) - BORRAR UN NOMBRE \n");
    printf ("(3) - LISTAR AGENDA \n");
    printf ("(4) - SALIR \n");
    printf ("\n\n");
    printf ("INTRODUZCA OPCION: \n");
    scanf ("%d", &c);
    return c;   
   }      
              
   
   /* Función para leer los datos del teclado */
   
   void intro(void)
   {
     int sitio;

     sitio= busca_libre();

     if (sitio== -1)
     {
       printf ("Agenda llena\n");
       return;
     }

     printf ("Introduzca el nombre: \n");
     scanf ("%s", agenda[sitio].nombre);
     fflush(stdin);

     printf ("Introduzca la direccion: \n");
     scanf ("%s", agenda[sitio].direccion);
     fflush(stdin);

     printf ("Introduzca la edad: \n");
     scanf ("%s", agenda[sitio].edad);
     fflush(stdin);

     printf ("Introduzca sexo: \n");
     scanf ("%s", agenda[sitio].sexo);
     fflush(stdin);

     printf ("Introduzca telefono: \n");
     scanf ("%s", agenda[sitio].telefono);
     fflush(stdin);
     
   }
   
   
   
   /* Funcion para buscar una estructura no usada */
   
    int busca_libre(void)
    {
      register int i;
      
      for (i=0; agenda[i].nombre[0] && i<max; i++);
      
      if (i==max) 
      return -1;  // La agenda está llena.

      
      return i;
    }
     
   /* Funcion para borrar alguno de los datos */
   
         
    void borrar(void)
    {
      register int sitio;
      char num[5];

      printf ("Introduzca el numero de registro que desea borrar: \n");
      gets (num);
      sitio= atoi(num);
      
      if ((sitio >= 0) && (sitio < max))
      
      {
        agenda[sitio].nombre== '\0';
      }
    }      
    
    /* Funcion para mostrar todos los registros */
                                 
     void mostrar(void)
     {
       register int i;

       for (i=0; i<=max; ++i)
       {
         if (agenda[i].nombre[0])
         {
            printf ("%s\n", agenda[i].nombre); 
            printf ("%s\n", agenda[i].direccion);
            printf ("%s\n", agenda[i].edad);
            printf ("%s\n", agenda[i].sexo);
            printf ("%s\n", agenda[i].telefono);
	    printf ("\n");
          }  
       }
        printf ("\n\n");
      }                                                                                            
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
