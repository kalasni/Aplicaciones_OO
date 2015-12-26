#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALLO "No esta en el diccionario"
#define max 100


typedef struct
{
   char *espanol;
   char *ingles; 
    
}palabra;

palabra diccionario[max];
int contador= 0;   

void introducir(void);
char *traducir (char *termino, int modo);
void traduct(void);
int menutraduccion(void);
char buffer[80], buffer2[80];

int main()
{
   char opci;
   
     for (;;)
     {
       opci= menu();
       switch (opci) {
           case 1: introducir();
           break;
           case 2: traduct();
           break;
           case 3: return 0;
     }
    } 
  }



 int menu (void)
  {
    int c;
    printf ("          =======================================\n");
    printf ("         |                                       |\n");
    printf ("         | (1) - INTRODUCIR PALABRA              |\n");
    printf ("         |                                       |\n");
    printf ("         | (2) - TRADUCIR                        |\n");
    printf ("         |                                       |\n");
    printf ("         | (3) - SALIR DEL PROGRAMA              |\n");
    printf ("         |                                       |\n");
    printf ("          =======================================\n");
    printf ("\n\n");
    printf ("         =====================\n");
    printf ("           INTRODUZCA OPCION: \n");
    printf ("         =====================\n");  
    scanf ("%d", &c);
    fflush (stdin);
    return c;   
   }      
   
   
   
 void introducir(void)
 {

   printf("Introduzca palabra primero en ingles y luego en espanol: \n");
   if (contador < max)
   {
     gets (buffer);
     fflush(stdin);
     gets (buffer2);
     fflush(stdin);
   }


  if (traducir(buffer, 1)== FALLO && traducir(buffer2, 2)== FALLO)
  {
    if (meterpalabra(contador, buffer, buffer2))
    {
      printf ("La palabra se ha introducido en el diccionario\n");
      contador++;
    } 
    else printf ("No se ha podido introducir \n");
  }
  
  else printf ("Diccionario lleno\n");  
  
}                                              
         

 char *traducir (char *termino, int modo)
 {
     int i;

     if (modo==1)
     {
       for (i=0; i<contador; i++)
       {
         if (strcmp (buffer, diccionario[i].espanol)== 0)
         {
            return diccionario[i].espanol;
         }       
       } printf ("\n");
      } 
      else if (modo==2)
      {
        for (i=0; i<contador; i++)
        {
          if (strcmp (buffer2, diccionario[i].ingles)== 0)
          {
            return diccionario[i].ingles;
          }
        }
      } 
      return FALLO;
  }



void traduct()
{
  char opcion, buffer[80];
 
 while(1)
 {
   opcion= menutraduccion();
   fflush(stdin);
   switch (opcion) {
   
           case 1: printf ("Introduzca palabra en espanol: \n");
                   gets (buffer);
                   fflush(stdin);
                   printf ("\n\n");
                   system ("cls");
                   printf ("%s \t %s", buffer, traducir(buffer, 1));
                   printf ("\n\n");
                   break;
                   
           case 2: printf ("Introduzca palabra en ingles: \n");
                   gets (buffer);
                   fflush(stdin);
                   printf ("\n\n");
                   system ("cls");
                   printf ("%s \t %s", buffer, traducir(buffer, 2));
                   printf ("\n\n");
                   break;
                   
           case 3: return;
    }
  }                 
 }              
 
 
 int meterpalabra (int i, char* esp, char *ing)
 {
   if (!(diccionario[i].espanol= (char*)malloc(strlen(esp)+1)))
   return 0;
   else 
   {
     strcpy (diccionario[i].espanol, esp);
   }
   
   if (!(diccionario[i].ingles= (char*)malloc(strlen(ing)+1)))
   return 0;
   else  
   {
     strcpy (diccionario[i].ingles, ing);
   }
    return 1;
 }  


 int menutraduccion(void)
 {
   int c;
   
   printf ("(1) - Traduccir en ingles \n");
   printf ("\n");
   printf ("(2) - Traducir en Espanol \n");
   printf ("\n");
   printf ("(3) - Salir \n");
   scanf ("%d", &c);
   fflush(stdin);
   return c;
 }  
