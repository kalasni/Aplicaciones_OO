
#include "ficheros.h"

void guardar(palabra *diccionario, int contador)
{
   int i;
   char fin_c='\0', fin_l='\n';
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
   int i=0;
   char buffer[40], buffer2[40];
   char fin_c='\0', fin_l='\n';
   FILE *pf;
   
   pf= fopen("diccionario.txt", "rb");
   if (pf==NULL)
   {
     printf ("Error al abrir %s", "diccionario.txt");
     return;
   }
   fread(contador, sizeof(int), 1, pf);
   fgets(buffer, 40, pf);
   fgets(buffer2, 40, pf);
   diccionario[i].ingles= (char*)malloc(strlen(buffer)+1);
   diccionario[i].espanol= (char*)malloc(strlen(buffer2)+1);
   strcpy (diccionario[i].espanol, buffer2);
   strcpy (diccionario[i].ingles, buffer);
   
   while ((i < *contador) && !feof(pf))
   {
     if (!ferror(pf))
     {
       i++;
       fgets(buffer, 40, pf);
       fgets(buffer2, 40, pf);
       diccionario[i].espanol= (char*)malloc(strlen(buffer2)+1);
       diccionario[i].ingles= (char*)malloc(strlen(buffer)+1);
       strcpy (diccionario[i].espanol, buffer2);
       strcpy (diccionario[i].ingles, buffer);
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
    char fin_c='\0', fin_l='\0';
    
    if(opcion<=1)
    {
       pf= stdout;
              
       for(i=0; i<contador; i++)
       {
           if(!ferror(pf))
           {
             fwrite(diccionario[i].ingles, strlen(diccionario[i].ingles), 1, pf); 
             fwrite(&fin_c, sizeof(char), 1, pf);
             fwrite(&fin_l, sizeof(char), 1, pf);
             fwrite(diccionario[i].espanol, strlen(diccionario[i].espanol), 1, pf);
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
           fwrite(diccionario[i].ingles, strlen(diccionario[i].ingles), 1, pf); 
           fwrite(&fin_c, sizeof(char), 1, pf);
           fwrite(&fin_l, sizeof(char), 1, pf);    
           fwrite(diccionario[i].espanol, strlen(diccionario[i].espanol), 1, pf);
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
