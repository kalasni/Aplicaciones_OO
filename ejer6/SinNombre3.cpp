#include <stdio.h>
#include <stdlib.h>
#define maxfil 100
#define maxcol 80

char nombres[maxfi][maxcol];
char * fin, opci, filas=0;
main()
{
  i=0;
  printf ("Introduce nombres hasta EOF:\n");
  do {
       fin= gets (nombres[i])
       i++;
     }while (fin !=EOF || i < maxfil);
     
     do{
         printf ("Desea ver la lista ordenada? \n");
         scanf ("%c", &opci);
       }while (toupper(opci) !='s'&& tolower(opci) !='n');
       
    if (tolower(opci)='s')
    {
      ordenar (nombres, filas);
      for (i=0; i<filas; i++)
      {
        puts (nombres[i])
      }
    }
    else 
       system ("pause");
       return 0;
       
      
        
