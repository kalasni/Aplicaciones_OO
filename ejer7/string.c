/* Programa que simula algunas de las funciones incluidas en la libreria
   string.h y que pueden ser elegidas mediante un menu. Las funciones 
   utilizan punteros para realizar su función. (23-05-03) */


#include <stdio.h>
#include <stdlib.h>

int long_cad (char *cadena);
char *copiar_cad (char *cadena, char *cadena2);
char *concate_cad (char *cadena, char *cadena2);
char *punt_cad (char *cadena, char car);
int comp (char *cadena, char *cadena2);
char *cad_minus (char *cadena);
char *cad_mayus (char *cadena);

char car, cadena[30];
char cadena2[30];
int main()
{
  char opci;
  
   for (;;)
     {
       opci= menu();
       switch (opci) {
       
       
              case 1:  printf ("Introduzca cadena: \n");
                       scanf ("%s", cadena); 
                       system ("cls");
                       printf ("\n\n");
                       printf ("La cadena tiene una longuitud de %d \n\n", long_cad(cadena));
                       system("pause");
                       break;
           
              case 2:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       printf("%s \n\n", copiar_cad (cadena, cadena2));
                       system ("pause");
                       break;
           
              case 3:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       system ("cls");
                       printf ("\n\n");
                       printf("%s \n\n", concate_cad (cadena, cadena2));
                       system ("pause");
                       break;
           
              case 4:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       fflush (stdin);
                       printf ("Introduzca caracter a buscar:\n");
                       scanf ("%c", &car);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n\n", punt_cad (cadena, car));
                       system ("pause");
                       break;
                    
              case 5:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       fflush (stdin);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       system ("cls");
                       printf ("\n\n");
                       fflush (stdin);
                       printf ("%d", comp (cadena, cadena2));
                       break;         
           
              case 6:  printf ("Introduzca cadena a convertir: \n");
                       scanf ("%s", cadena);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n", cad_minus (cadena));
                       system ("pause");
                       break;
                    
              case 7:  printf ("Introduzca cadena a convertir: \n");
                       scanf ("%s", cadena);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n", cad_mayus (cadena));
                       system ("pause");
                       break;
              
              case 8:  return 0;
       }
     } 
  }
  
  
  /* Seleccionamos operacion a realizar */
  
  
  int menu (void)
  {
    int c;
    printf ("          =======================================\n");
    printf ("         | (1) - COMPROBAR LONGUITUD DE CADENA   |\n");
    printf ("         |                                       |\n");
    printf ("         | (2) - COPIAR CADENA EN OTRA           |\n");
    printf ("         |                                       |\n");
    printf ("         | (3) - CONCATENAR CADENAS              |\n"); 
    printf ("         |                                       |\n");
    printf ("         | (4) - DEVOLVER PUNTERO A CADENA       |\n");
    printf ("         |                                       |\n");
    printf ("         | (5) - COMPARAR DOS CADENAS            |\n");
    printf ("         |                                       |\n");
    printf ("         | (6) - CONVERTIR CADENA EN MINUSCULAS  |\n");
    printf ("         |                                       |\n");
    printf ("         | (7) - CONVERTIR CADENA EN MAYUSCULAS  |\n");
    printf ("         |                                       |\n");
    printf ("         | (8) - SALIR                           |\n");
    printf ("          =======================================\n");
    printf ("\n\n");
    printf ("         =====================\n");
    printf ("           INTRODUZCA OPCION: \n");
    printf ("         =====================\n");  
    scanf ("%d", &c);
    return c;   
   }      
              
              
   
    
   
                      
    int long_cad (char *cadena)
    {
      int a=0;
      for (; cadena[a]!='\0'; a++);
      return a; 
    }        
    
    
    
    
    char *copiar_cad (char *cadena, char *cadena2)
    {
      char *resultado= cadena;
      int i=0;
      while (*cadena2 !='\0')
      {
        *cadena= *cadena2;
         cadena++;
         cadena2++;
      } *cadena= '\0';
        return resultado;
    }       
       
       
    char *concate_cad (char *cadena, char *cadena2)
    {   
       char *resultado= cadena;
       while (*cadena!= '\0') cadena++;
       while (*cadena2!= '\0')
       { 
         *cadena = *cadena2;  
          cadena++; cadena2++;
       }
       *cadena= '\0';
        return resultado;
    }
    
    
    char *punt_cad (char *cadena, char car)
    {
      while (*cadena!= '\0')
      {
        if (*cadena== car)
        return cadena;
        cadena++;
      }
      return NULL;
    }    
     
     
     
                                                           
    int comp (char *cadena, char *cadena2)  
    {
       
       for (; *cadena== *cadena2; cadena++, cadena2++);
       if (*cadena =='\0') return 0;
       return *cadena - *cadena2;
    }   
   
     
       
     
     char *cad_minus (char *cadena)
     { 
       char *inicio= cadena;
       while (*cadena!= '\0')
       {
          if (*cadena >= 'A' && *cadena <= 'Z')
          *cadena += (char)32;
          cadena++;
       }
       return inicio;
     }                                   
                 
   
     char *cad_mayus (char *cadena)
     {
       char *inicio= cadena;
       while (*cadena!= '\0')
       {
          if (*cadena >= 'a' && *cadena <= 'z')
          *cadena -= (char)32;
          cadena++;
       }
       return inicio;
     }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
