#ifndef DICCIONARIO
#define DICCIONARIO
#include <stdio.h>
#include <stdlib.h>
#include <ficheros.h>
#define FALLO "No esta en el diccionario"
#define max 100
#ifndef PALABRA
#define PALABRA

typedef struct
{
  char *espanol;
  char *ingles;

}palabra;  

#endif

palabra diccionario[max];
int contador=0;



void guardar(palabra *diccionario, int contador)
{
   int i;
   char fin_c='\0', fin_l='\0';
   FILE *pf;
   
   pf= fopen("diccionario.txt", "wb");
   if (pf==NULL)
   {
     printf ("Error al guardar %s", "diccionario.txt");
     exit(1);
   }
   
   fwrite(&contador, sizeof(int), 1, pf);
   
   for(i=0; i<contador && !ferror(pf); i++)
   {
     if(!ferror(pf))
     {
       fwrite(diccionario[i].espanol, strlen(diccionario[i].espanol), 1, pf);
       fwrite(&fin_c, sizeof(char), 1, pf);
       fwrite(&fin_l, sizeof(char), 1, pf);
       fwrite(diccionario[i].ingles, strlen(diccionario[i].ingles), 1, pf); 
       fwrite(&fin_c, sizeof(char), 1, pf);
       fwrite(&fin_l, sizeof(char), 1, pf);
     }
     else 
     {
       perror("ERROR");
       exit(1);
     }
   }
   fclose(pf);    
 }           
 
 
 
 void cargar(palabra *diccionario, int *contador)
 {
   int i=0;;
   char fin_c='\0', fin_l='\n', buffer[40];
   FILE *pf;
   
   pf= fopen("diccionario.txt", "rb");
   if (pf==NULL)
   {
     printf ("Error al abrir %s", "diccionario.txt");
     exit(1);
   }
   
   fread(contador, sizeof(int), 1, pf);
   fgets(buffer, 40, pf);
   fgets(buffer2, 40, pf);
   strcpy (diccionario[i].espanol, esp);
   strcpy (diccionario[i].ingles, ing);
   
   while (i < contador && !feof(pf))
   {
     if (!ferror(pf))
     {
       i++;
       fgets(buffer, 40, pf);
       fgets(buffer2, 40, pf);
       
     }
     
     else 
     {
       perror("ERROR");
       exit(1);
     }
         
   }
 }  
  
   
    
 void imprimir(palabra *diccionario, int contador, int opcion)
 {
    FILE *pf;
    int i;
    
    if(opcion<=1)
    {
       pf= stdout;
              
       for(i=0; i<contador; i++)
       {
           if(!ferror(pf))
           {
             fwrite(diccionario[i].espanol, strlen(diccionario[i].espanol), 1, pf);
             fwrite(&fin_c, sizeof(char), 1, pf);
             fwrite(&fin_l, sizeof(char), 1, pf);
             fwrite(diccionario[i].ingles, strlen(diccionario[i].ingles), 1, pf); 
             fwrite(&fin_c, sizeof(char), 1, pf);
             fwrite(&fin_l, sizeof(char), 1, pf);
           }
           else 
           {
             perror("ERROR");
             exit(1);
           }
       }    
    } 
      
    else
    {
        pf= fopen("lpt1", "wb");  
       
       for(i=0; i<contador; i++)
       {
         if(!ferror(pf))
         {
               
           fwrite(diccionario[i].espanol, strlen(diccionario[i].espanol), 1, pf);
           fwrite(&fin_c, sizeof(char), 1, pf);
           fwrite(&fin_l, sizeof(char), 1, pf);
           fwrite(diccionario[i].ingles, strlen(diccionario[i].ingles), 1, pf); 
           fwrite(&fin_c, sizeof(char), 1, pf);
           fwrite(&fin_l, sizeof(char), 1, pf);
         }
         else 
         {
           perror("ERROR");
           exit(1);
         }
       }   
     }  
       fclose(pf); 
 }                                                              
