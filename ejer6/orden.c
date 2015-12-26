#include <stdio.h>
#include <stdlib.h>
#define maxfil 100
#define maxcol 80

char nombres[maxfil][maxcol];
void ordenar (char matriz[maxfil][maxcol], int f);
char * fin, opci, filas=0;
main()
{
  int i=0;
  printf ("Introduce nombres hasta EOF:\n");
  do {
       fin= gets (nombres[i]);
       i++;
       filas++;
       if (fin== NULL)
       break;
     }while (i < maxfil);
     
     do{
         printf ("Desea ver la lista ordenada? \n");
         scanf ("%c", &opci);
         fflush (stdin);
       }while (toupper(opci) !='S' && tolower(opci)!= 'n');
       
    if (tolower(opci)=='s')
    {
      ordenar (nombres, filas);
      for (i=0; i<filas; i++)
      {
        puts (nombres[i]);
      } system ("pause");
    } 
    else 
       system ("pause");
       return 0;
 }      
      
   void ordenar (char matriz[maxfil][maxcol], int filas)
   {
      int intercambio=0, i;
      char aux[maxcol];
      do {
           for (i=0; i< filas -1; i++)
           {
             if (strcmp(matriz[i], matriz[i+1]) > 0)
             {
               strcpy (aux, matriz[i]);
               strcpy (matriz[i], matriz[i+1]);
               strcpy (matriz[i+1], aux);
               intercambio=1;
              }
            }filas--;
          } while (intercambio==1 && filas > 1);
   }     
       
      
   
