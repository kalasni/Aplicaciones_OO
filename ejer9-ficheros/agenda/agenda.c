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
 
 void inic_agenda(void), intro(void), modi_nombre(void);
 void borrar(void), mostrar(void), busca_regis(void), muestra_contacto(int j);
 int menu(void), menu_buscar(void);
 int busca_libre(void);
 void abrir(void);
 void guardar(void);
 int sitio;
 
 int main()
 {
   char opci;
   inic_agenda();     // Inicializa el array de estructura.
   
   
     for (;;)
     {
     opci= menu();
     switch (opci) {
           case 1:  intro();
                    break;
           
           case 2:  borrar();
                    break;
           
           case 3:  mostrar();
                    break;
           
           case 4:  inic_agenda();
                    break;
                    
           case 5:  modi_nombre();
                    break;         
           
           case 6:  busca_regis();
                    break;
                    
           case 7:  abrir();
	                break;
		    
           case 8:  guardar();
	                break;

           case 9:  return 0;

    } 
  }
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
    printf ("          ==================================\n");
    printf ("         | (1) - INTRODUCIR UN NOMBRE       |\n");
    printf ("         |                                  |\n");
    printf ("         | (2) - BORRAR UN NOMBRE           |\n");
    printf ("         |                                  |\n");
    printf ("         | (3) - MOSTRAR AGENDA             |\n");
    printf ("         |                                  |\n");
    printf ("         | (4) - BORRAR AGENDA              |\n");
    printf ("         |                                  |\n");
    printf ("         | (5) - MODIFICAR UN NOMBRE        |\n");
    printf ("         |                                  |\n");
    printf ("         | (6) - BUSCAR UN REGISTRO         |\n");
    printf ("         |                                  |\n");
    printf ("         | (7) - LEER ARCHIVO AGENDA        |\n");
    printf ("         |                                  |\n");
    printf ("         | (8) - GUARDAR ARCHIVO AGENDA     |\n");
    printf ("         |                                  |\n");
    printf ("         | (9) - SALIR                      |\n");
    printf ("          ==================================\n");
    printf ("\n\n");
    printf ("         =====================\n");
    printf ("           INTRODUZCA OPCION: \n");
    printf ("         =====================\n");
    scanf ("%d", &c);
    return c;
   }


   /* Función para leer los datos del teclado */

   void intro(void)
   {
     int sitio;
     sitio= busca_libre();
     
     if (sitio==-1)
     {
       printf ("           La agenda esta llena.\n");
       system("pause");
       return;
     }
     else
     {
       system ("cls");
       printf ("\n\n\n");
       printf ("         CONTACTO %d \n", sitio+1);
       printf ("         Introduzca el nombre:  ");
       scanf  ("%s", agenda[sitio].nombre);
       fflush(stdin);
       printf ("\n");
       printf ("         Introduzca la direccion:  ");
       scanf  ("%s", agenda[sitio].direccion);
       fflush(stdin);
       printf ("\n");
       printf ("         Introduzca la edad:  ");
       scanf  ("%s", agenda[sitio].edad);
       fflush(stdin);
       printf ("\n");
       printf ("         Introduzca sexo:  ");
       scanf  ("%s", agenda[sitio].sexo);
       fflush(stdin);
       printf ("\n");
       printf ("         Introduzca telefono:  ");
       scanf ( "%s", agenda[sitio].telefono);
       fflush(stdin);
       printf ("\n\n");
     }
   }
   
   /* Función que busca espacio libre en la estructura */
   
   int busca_libre(void)
   {
     int i;
     for (i=0; agenda[i].nombre[0] && i < max; ++i)
     if (i== max) return -1;  // Agenda llena
     return i;
   }
   

     
   /* Funcion para borrar alguno de los datos */
                    
    void borrar(void)
    {
      int sitio, num;
      printf ("            Introduzca el numero de registro que desea borrar: \n");
      scanf ("%d", &num);
      sitio= num-1;

      if ((sitio >= 0) && (sitio < max))
      {
        agenda[sitio].nombre[0]= '\0';
      }
      sitio--;
    }      

    /* Funcion para modificar un nombre */

    void modi_nombre(void)
    {
      int sitio, num;
      printf ("            Introduzca el numero de contacto que quiere modificar: \n");
      scanf ("%d", &num);
      sitio= num-1;
      
      if ((sitio >= 0) && (sitio < max))
      {
         
         system ("cls");
         printf ("\n\n\n");
         printf ("    CONTACTO %d \n", sitio+1);
         printf ("    ========== \n\n");
         printf ("    NOMBRE: %s\n", agenda[sitio].nombre);
         printf ("    Introduzca nombre:  "); 
         scanf  ("%s", agenda[sitio].nombre);
         fflush(stdin);
         printf ("\n");
         printf ("    DIRECCION: %s\n", agenda[sitio].direccion); 
         printf ("    Introduzca la direccion:  ");
         scanf  ("%s", agenda[sitio].direccion); 
         fflush(stdin);
         printf ("\n");
         printf ("    EDAD: %s\n", agenda[sitio].edad);
         printf ("    Introduzca la edad:  ");
         scanf  ("%s", agenda[sitio].edad);
         fflush(stdin);
         printf ("\n");
         printf ("    SEXO: %s\n", agenda[sitio].sexo);
         printf ("    Introduzca sexo:  ");
         scanf  ("%s", agenda[sitio].sexo);
         fflush(stdin);
         printf ("\n");
         printf ("    TELEFONO: %s\n", agenda[sitio].telefono);
         printf ("    Introduzca telefono:  ");
         scanf ( "%s", agenda[sitio].telefono);
         fflush(stdin);
         printf ("\n\n");
         
     }
    } 
    /* Funcion para mostrar todos los registros */
                                 
     void mostrar(void)
     { 
       int sitio;
       system ("cls");  // Limpia la pantalla.
       for (sitio=0; sitio<=max; sitio++)
       {
         if (agenda[sitio].nombre[0])
         {
            printf ("    CONTACTO %d \n", sitio+1);
            printf ("    ========== \n");
            printf ("    NOMBRE: %s\n", agenda[sitio].nombre);
            printf ("\n"); 
            printf ("    DIRECCION: %s\n", agenda[sitio].direccion);
            printf ("\n"); 
            printf ("    EDAD: %s\n", agenda[sitio].edad);
            printf ("\n"); 
            printf ("    SEXO: %s\n", agenda[sitio].sexo);
            printf ("\n"); 
            printf ("    TELEFONO: %s\n", agenda[sitio].telefono);
            
            printf ("\n\n");
          }  
       }
      }                                                                                            

    
     /* Funcion para buscar algun registro */

     void busca_regis(void)
     {
       char registro[30];
       int seleccion, j;
       
        for (;;)
        {
          seleccion= menu_buscar();
          switch (seleccion) {
                   
                   case 1:  puts ("Introduzca el nombre que quiere buscar: \n");
                            scanf ("%s", &registro);
                            for (j=0; j<max; j++)
                            {
                              if(strcmp(agenda[j].nombre, registro)==0)
                              {
                                muestra_contacto(j);
                                system("pause");
                              }
                            }
                            break;

			    
		  case 2:  puts ("Introduzca la direccion que quiere buscar: \n");
		           scanf ("%s", &registro);
			   for (j=0; j<max; j++)
                           {
                              if(strcmp(agenda[j].direccion, registro)==0)
                              {
                                muestra_contacto(j);
                                system("pause");
                              }
                           }
                           break;

	          case 3:  puts ("Introduzca la edad que quiere buscar: \n");
                           scanf ("%s", &registro);
			   for (j=0; j<max; j++)
                           {
                              if(strcmp(agenda[j].edad, registro)==0)
                              {
                                muestra_contacto(j);
                                system("pause");
                              }
                           }
                           break;

                  case 4: puts ("Introduzca el telefono que quiere buscar: \n");
                          scanf ("%s", &registro);
			  for (j=0; j<max; j++)
                          {
                              if(strcmp(agenda[j].telefono, registro)==0)
                              {
                                muestra_contacto(j);
                                system("pause");
                              }
                          }
                          break;

	          case 5: return;

         } 
       }
     }  

       
    void muestra_contacto (int j)
    { 
        system ("cls");
        printf ("\n\n\n");
        printf ("    CONTACTO %d \n", j);
        printf ("    ========== \n");
        printf ("    NOMBRE: %s\n", agenda[j].nombre);
        printf ("\n"); 
        printf ("    DIRECCION: %s\n", agenda[j].direccion);
        printf ("\n"); 
        printf ("    EDAD: %s\n", agenda[j].edad);
        printf ("\n"); 
        printf ("    SEXO: %s\n", agenda[j].sexo);
        printf ("\n"); 
        printf ("    TELEFONO: %s\n", agenda[j].telefono);
        printf ("\n\n");

    }                 

    
    int menu_buscar (void)
    {
      int opc;
      system("cls");

      do {
           puts ("ELIJA CRITERIO DE BUSQUEDA: \n");
	   puts ("============================\n");
           puts ("(1)- BUSQUEDA POR NOMBRE \n");
           puts ("(2)- BUSQUEDA POR DIRECCION \n");
           puts ("(3)- BUSQUEDA POR EDAD \n");
           puts ("(4)- BUSQUEDA POR TELEFONO. \n");
           puts ("(5)- VOLVER A MENU PRINCIPAL \n");
           puts ("\n");
           puts ("Introduzca opcion: \n");
           scanf ("%d", &opc);
         } while (opc < 1 && opc > 7);
           
           return opc;
      }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                                                         


      
  /* Funcion para abrir (leer) el archivo agenda */
  
   
  void abrir(void)
  {
    FILE *fp;
    int i;
    
    if ((fp=fopen("agen.txt", "rb"))==NULL)
    {
      perror("No se puede abrir el archivo \n");
      return;
    }
    
    inic_agenda();
    for (i=0; i<max; i++)
    
     if (fread(&agenda[i], sizeof(struct dir), 1, fp)!=1)
     {
       if(feof(fp))
       {
         break;
       }
       perror ("Error en la lectura del archivo \n");
     }
     fclose(fp);
  }


                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  /* Funcion para guardar (escribir) la agenda */
  
  
  void guardar(void)
  {
    FILE *fp;
    int i;
    
    if((fp=fopen("agen.txt", "wb"))==NULL)
    {
       perror ("No se puede abrir el archivo.\n");
       return;
    }
    
      for (i=0; i<max; i++)

      if (*agenda[i].nombre)
      if (fwrite(&agenda[i], sizeof (struct dir), 1, fp)!=1)
      {
         perror ("Error de escritura en el archivo agenda \n");
	 return;
      }
    
    
    fclose(fp);
  }
