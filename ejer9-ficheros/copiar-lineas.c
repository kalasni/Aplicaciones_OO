#include <stdio.h>
#include <stdlib.h>

int main (int numero, char *fichero[])
{
   int i= 0;
   char buffer[100];
   FILE *pf= NULL;
   
   if (numero!=2)
   {
     perror ("No se ha podido realizar operacion \n");
     exit(1);
   } 
   
   if ((pf= fopen(fichero[1], "wb"))== NULL)
   {
    perror ("no se ha podido abrir el fichero \n");
    exit (1);
   }
   
   printf ("Fichero %s abierto \n", fichero[i]);
   printf ("Introducir texto hasta EOF (Ctrl-z): \n");
   
   while (fgets (buffer, 81, stdin)!= NULL) // 81 numero de caracteres pantalla
   {
      fputs (buffer, pf);
      if (ferror(pf))
      { 
        perror ("error al escribir"); 
        exit(1);
      }  
   }
   
   rewind (pf);
   
   while ((fgets (buffer, 81, pf)!= NULL && !ferror(pf)))
   {
     fputs (buffer , stdout); 
     
     if (ferror(pf) || ferror(stdout))
     {
       perror ("Problema al escribir texto");
       exit(1);
     }
   }  
   
   fclose (pf);
   system ("pause");
   return 0;
 }  
