#include <stdio.h>
#include <stdlib.h>



int main()
{
  int i=0;
  char buffer[100];
  FILE *pf;
  
  if ((pf =fopen ("texto.txt", "wb"))== NULL)
  {
    perror ("No se ha podido abrir");
    exit(1);
  }
      
  printf ("Introducir texto: \n");
  scanf ("%s", buffer);
  
  while (!ferror(pf) && buffer[i]!= '\0')
  {
     fputc (buffer[i], pf);
     i++;
  
   if (ferror(pf))
   {
    perror ("Problema al escribir texto");
    exit(1);
   }
  }
  
  fclose (pf);
  system ("pause");
  return 0;
}                                  
