#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *matriz1[]= {"almacen", "canario", "marea", "variable", "zapato"};
char *matriz2[]= { "camaleon", "chusquero", "viento"};
char **matrizfus;
int tmatriz1;
int tmatriz2;

void fusionar (char *matriz1[], int a, char *matriz2[], int b, char **matrizfus);

int main()
{

  tmatriz1= (sizeof (matriz1) / sizeof (char *));
  tmatriz2= (sizeof (matriz2) / sizeof (char *));
  matrizfus= (char**) malloc((tmatriz1 + tmatriz2)* sizeof (char));
    
  fusionar (matriz1, tmatriz1, matriz2, tmatriz2, matrizfus);
  system ("pause");
  return 0;
  
}  


void fusionar (char *matriz1[], int a, char *matriz2[], int b, char **matrizfus)
{

  int i= 0, j= 0, f= 0, indice, h;

  while (i < a && j < b)
  {
     if (strcmp (matriz1[i], matriz2[j]) < 0)
     {
        matrizfus[f]= (char*) malloc (strlen(matriz1[i])+1); 
        
        /* Primero hace la copia y despues incrementa los indices */
        
        strcpy (matrizfus[f++], matriz1[i++]);
     }
     else 
     {
       matrizfus[f]= (char*) malloc (strlen (matriz2[j])+1);   
       strcpy (matrizfus[f++], matriz2[j++]);
     }  
  }
  
  
     for (indice= i; indice < a; indice++)
     {
        matrizfus[f]= (char*) malloc (strlen(matriz1[indice])+1);
        strcpy (matrizfus[f++], matriz1[indice]);
     }   

     
     for (indice= j; indice < b; indice++)
     {
        matrizfus[f]= (char*) malloc (strlen(matriz2[indice])+1);
        strcpy (matrizfus[f++], matriz2[indice]);
     }
        
     

    for (h=0; h<f; h++)
    {
      printf ("%s", matrizfus[h]);
      printf ("\n");
    }
    printf ("\n\n");   
} 
   
   



  
