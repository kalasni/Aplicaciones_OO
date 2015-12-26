/* Programa de copia de ficheros. Lee un fichero lo copia en otro y muestra
   el numero de caracteres copiados (05-06-03) */

#include <stdio.h>
#include <stdlib.h>

int main(int numero, char *datos[])
{

  FILE *origen= NULL; 
  FILE *destino= NULL;
  char aux;
  int cont=0;
  
  if (numero!=3)
  {
    perror ("No se ha podido abrir");
    exit(1);
  } 
  
  if ((origen= fopen (datos[1], "rb"))== NULL)
  {
    perror ("No se ha podido abrir el fichero 1 \n");
    exit (1);
  } 
  
  if ((destino= fopen(datos[2], "wb"))== NULL)
  {
    perror ("no se ha podido abrir el fichero 2 \n");
    exit (1);
  }
  
  while(!feof(origen) && !ferror(origen) && !ferror(destino))
  {
     aux= fgetc(origen);
     
     if (!feof(origen))
     {
       fputc (aux, destino);
       cont++;
     }
  }       
  
  if (ferror (origen) || ferror (destino))
  {
     perror ("No se ha podido copiar \n");
  }
  else 
  {
    printf ("Se ha realizado la copia del fichero a fichero \n");
    printf ("La cantidad de caracteres copiados es: %d \n", cont);
  }
  
  fclose (origen); fclose (destino); 
  
  system ("pause");
  return 0;

}           
  
          
