
#include "mod-string.h"


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
              
  
  
    
                      
    int long_cad (char* cadena)
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
                                                                                                    
