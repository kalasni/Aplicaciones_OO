/* Programa que lee una palabra y la busca en un fichero de texto (la palabra
   y el fichero se introducen como parametros del programa).
   El programa debe ser capaz de encontrar la palabra en el fichero de texto
   y mostrar si la ha encontrado o no. Si la encuentra deberá poner la palabra
   en mayusculas en el fichero de texto. (27-06-03) 
   
   El programa se comprobará con:   Ejercicio1 texto.txt coincidencia
                                    Ejercicio1 texto.txt prueba
                                    Ejercicio1 texto.txt palabra
   
   
   
   */
   

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void poner_mayuscu (FILE *fichero, char *cad);


int main(int numero, char *argumento[])
{
  FILE *pf= NULL;
  char cadena[80], car;
  int i=0;
  int encontrado= 0; 
  
  if(numero!=3)
  {
    printf("No se ha llamado correctamente al programa \n");
    system("pause");
    return 0;
  } 
  
  pf= fopen(argumento[1], "r+b");
  
  if((pf=fopen(argumento[1], "r+b"))==NULL)
  {
    printf("No se ha encontrado el fichero\n");
    system("pause");
    return 0;
  }
  
  strcpy(cadena, argumento[2]);
  
  while(!feof(pf) && !ferror(pf))
  {
    car= fgetc(pf);
    i= 0;
    
    while(car==cadena[i] && !ferror(pf) && !feof(pf))
    {
      i++;
      if(!cadena[i])
      {
        encontrado=1;                                                                  
        fseek (pf, - (sizeof(char)*i), SEEK_CUR);
        poner_mayuscu(pf, cadena);
        break;
      }
       else
         {
           car= fgetc(pf);
         }
     }  
     if(i > 0)
     {
        fseek(pf, - (sizeof(char)*i), SEEK_CUR);
     }
  }  
     
     if(encontrado==1)
     {
        printf("La cadena está en el texto \n");
     }
     else 
     {
        printf("La cadena %s no se encuentra en el texto\n", cadena);
          
     }  
     fclose(pf);
     system("pause");
     return 0;
        
 }
 
 void poner_mayuscu (FILE *fichero, char *cad)
 {
   int cont= 0;
   while(cad[cont] && !ferror(fichero))
   {
     fputc (toupper(cad[cont]), fichero);
     cont++;
   }
   
   if(ferror(fichero))
   {
     printf ("No se ha podido escribrir \n"); 
   }
 }     
                                            
