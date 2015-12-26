/* Programa para corregir los salarios de los empleados de un almacén según
   la antiguedad que tengan en la empresa.
   El programa corregirá o mostrará el salario de cada uno en función de la
   siguiente tabla:
   
      ANTIGUEDAD                            INCREMENTO
    Entre 5 y 10 años                         +5%
    Entre 10 y 20 años                        +10%
    Más de 20 años                            +20%                     */ 



#include <stdio.h>
#include <stdlib.h>
#define max 10


struct dir {
    char nombre[30];
    int salario;
    int antiguedad;
  }agenda[max];



  void inic_agenda(void);
  void intro(void);
  int busca_libre(void);
  void mostrar(void);
  void modi_salario(void);
  void copiar(struct dir *dest, struct dir *orig);
  int menu(void); 
 
  int cont= 0;
 
int main()
{
  int opcion;
  
  inic_agenda();
  for(;;)
  {
     opcion= menu(); 
     
     switch(opcion) {
     
             case 1: inic_agenda();
                     break;
                     
             case 2: intro();
                     break;
                     
             case 3: modi_salario();
                     break;
                     
             case 4: mostrar();
                     break;
             
             case 5: return 0;
             
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
     cont = 0;
   }     
   
               
   void intro(void)
   {
     int sitio;
     sitio= busca_libre();
     
     if (sitio==-1)
     {
       printf ("   La agenda esta llena.\n");
       system("pause");
       return;
     }
     else 
     {
       system ("cls");
       printf ("\n\n\n");
       printf ("   EMPLEADO %d \n", sitio+1);
       printf ("   Introduzca el nombre:  ");
       scanf  ("%s", agenda[sitio].nombre);
       fflush(stdin);
       printf ("\n");  
       printf ("   Introduzca el salario: ");
       scanf ("%d", &agenda[sitio].salario);
       fflush(stdin);
       printf ("\n");
       printf ("  Introduzca antiguedad: ");
       scanf  ("%d", &agenda[sitio].antiguedad);
       cont++;
       fflush(stdin);                      
     } 
       fflush(stdin);
   }               
   
                                  
     int busca_libre(void)
     {
       int i;
       for (i=0; agenda[i].nombre[0] && i < max; ++i)
       if (i== max) return -1;  // Agenda llena 
       return i;
     }                                  
     
     
 void mostrar(void)
 {
    struct dir aux;
    int sitio, sitio2;

    system ("cls");  // Limpia la pantalla.

    printf("           NOMBRE      SALARIO       INCREMENTO \n");
    printf("\n\n");

    for (sitio=0; sitio<cont-1; sitio++)
    {
       for(sitio2= sitio+1; sitio2<cont; sitio2++)
       {
        

         if(agenda[sitio].antiguedad < agenda[sitio2].antiguedad)
         {
           copiar(&aux,&agenda[sitio]);
           copiar(&agenda[sitio],&agenda[sitio2]);
           copiar(&agenda[sitio2],&aux);
       	 }
      }
    }


    for(sitio=0; sitio<cont; sitio++)
    {

      if (agenda[sitio].nombre[0])
      {
       
        if (agenda[sitio].antiguedad < 5)
        {
          printf("EMPLEADO: %d", (sitio+1));
          printf(" %s        %d euros      (+0%%)", agenda[sitio].nombre, agenda[sitio].salario);
          printf("\n\n");
        }


        else if (agenda[sitio].antiguedad >= 5 && agenda[sitio].antiguedad <=10)
        {
          printf("EMPLEADO: %d", (sitio+1));
          printf(" %s        %d euros      (+5%%)", 
          agenda[sitio].nombre, (agenda[sitio].salario + (agenda[sitio].salario * 5) /100));
          printf("\n\n");
        }

        else if (agenda[sitio].antiguedad >10 && agenda[sitio].antiguedad <=20)
        {
          printf("EMPLEADO: %d", (sitio+1));
          printf(" %s        %d euros      (+10%%)",
          agenda[sitio].nombre, (agenda[sitio].salario + (agenda[sitio].salario * 10) / 100));
          printf("\n\n");
        }

        else if(agenda[sitio].antiguedad > 20)
        {
          printf("EMPLEADO: %d", (sitio+1));
          printf(" %s        %d euros      (+20%%)",
          agenda[sitio].nombre, (agenda[sitio].salario + (agenda[sitio].salario * 20) / 100));
          printf("\n\n");
        }
        printf("\n");
        fflush(stdin);
      }
    }
 }


  void modi_salario(void)
  {
     int sitio, num;
     printf ("            Introduzca el numero de empleado que quiere modificar: \n");
     scanf ("%d", &num);
     sitio= num-1;

     if ((sitio >= 0) && (sitio < max))
     {

       system ("cls");
       printf ("\n\n\n");
       printf ("    EMPLEADO %d \n", sitio+1);
       printf ("    ========== \n\n");
       printf ("    SALARIO: %d\n", agenda[sitio].salario);
       printf ("    Introduzca el salario modificado:  ");
       scanf  ("%d", &agenda[sitio].salario);
       fflush(stdin);
     }
   }



   void copiar(struct dir *dest,struct dir*orig)
   {
     strcpy(dest->nombre,orig->nombre);
     dest->salario = orig->salario;
     dest->antiguedad = orig->antiguedad;
   }
        
   int menu(void)
   {
     int opc;
     printf (" AGENDA DE EMPLEADOS \n");
     printf ("\n");
     printf (" (1)- INICIAR AGENDA \n");
     printf (" (2)- INTRODUCIR EMPLEADOS \n");
     printf (" (3)- MODIFICAR EL SALARIO DE UN EMPLEADO \n");
     printf (" (4)- MOSTRAR EMPLEADOS \n");
     printf (" (5)- SALIR \n");
     
     scanf("%d", &opc);
     return opc;
   }      
