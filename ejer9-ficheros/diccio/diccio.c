#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FALLO "No esta en el diccionario"
#define max 100


typedef struct
{
   char espanol[40];
   char ingles[40]; 
    
}palabra;

palabra diccionario[max];
int contador= 0;   

void introducir(void);
char *traducir (char *termino, int modo);
void traduct(void);
int menutraduccion(void);
void guardar(void);
void cargar(void);
char buffer[80], buffer2[80];
int i;
int main()
{
   cargar();
   for (i=0; i<contador; i++)
   {
      printf("ingles : %s", diccionario[i].ingles);
      printf("ingles : %s", diccionario[i].espanol);
   }
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
           
           case 4: guardar(); break;
                   
           case 5: cargar();
                   break;
                              
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
    printf ("         | (4) - GUARDAR EN FICHERO              |\n");
    printf ("         |                                       |\n");
    printf ("         | (5) - ABRIR FICHERO                   |\n");
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
    strcpy (diccionario[contador].espanol, buffer);
    strcpy (diccionario[contador].ingles, buffer2);
    contador++;
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
         if (strcmp (termino, diccionario[i].espanol)== 0)
         {
            return diccionario[i].ingles;
         }       
       } printf ("\n");
      } 
      else if (modo==2)
      {
        for (i=0; i<contador; i++)
        {
          if (strcmp (termino, diccionario[i].ingles)== 0)
          {
            return diccionario[i].espanol;
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
                   printf ("%s \t %s", buffer, traducir(buffer, 2));
                   printf ("\n\n");
                   break;
                   
           case 2: printf ("Introduzca palabra en ingles: \n");
                   gets (buffer);
                   fflush(stdin);
                   printf ("\n\n");
                   system ("cls");
                   printf ("%s \t %s", buffer, traducir(buffer, 1));
                   printf ("\n\n");
                   break;
                   
           case 3: return;
    }
  }                 
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
 
 
 void guardar(void)
 {
   int i;
   FILE *pf;
 
   if ((pf=fopen("diccionario.txt", "wb"))==NULL)
   {
      perror("ERROR");
      exit(1);
   }   
   
    for(i=0; i<contador && !ferror(pf); i++)
    fwrite(&diccionario[i], sizeof(palabra), 1, pf);
    if(ferror(pf))
    {
      perror("ERROR");
      exit(1);
    }
     fclose(pf);
  }      
   
     
 
  void cargar(void)
  {
    int i;
    FILE *pf;
    
    if ((pf= fopen("diccionario.txt", "rb"))==NULL)
    {
     perror ("ERROR");
     exit(1);
    }     
    
    contador= 0;
    fread (&diccionario[contador], sizeof(palabra), 1, pf);
    
    while (!feof(pf) && contador < max && !ferror(pf))
    {
      if (!feof(pf) && !ferror(pf))
      {
        contador++;
        fread(&diccionario[contador], sizeof(palabra), 1, pf);
      }
      
      else printf ("No se puede leer\n");
    }      
    
    fclose(pf);
  }  
    
    
    
    
