
#include "diccio.h"

int main()
{
   int i, opcion;
   cargar(diccionario, &contador);
   printf("contador %d", contador);
   system("pause");
   for (i=0; i<contador; i++)
   {
      printf("ingles : %s\n", diccionario[i].ingles);
      printf("espanol : %s\n\n", diccionario[i].espanol);
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
           
           case 4: guardar(diccionario, contador);
                   break;
                   
           case 5: cargar(diccionario, &contador);
                   break;
                   
           case 6: printf ("Introduzca opcion: \n");
                   printf ("(1)- Salida por pantalla \n");
                   printf ("(2)- Salida por impresora \n");
                   scanf ("%d", &opcion);
                   imprimir(diccionario, contador, opcion);
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
    printf ("         | (6) - IMPRIMIR DICCIONARIO            |\n");
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
    diccionario[contador].espanol= (char*)malloc(strlen(buffer2)+1);
    diccionario[contador].ingles= (char*)malloc(strlen(buffer)+1);
    strcpy (diccionario[contador].espanol, buffer2);
    strcpy (diccionario[contador].ingles, buffer);
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
 
 

    
    
    
