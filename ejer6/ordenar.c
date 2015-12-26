#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu (void);
void insert(void);
void mostrar (char nombres[10][15], int num);
char nombres[10][15]; 
int num;

int main()
{
char opci;
    for (;;)
    {
     opci= menu();
     switch (opci) {
                case 1: 
                    insert();
                    break;
                case 2: 
                    mostrar(nombres, num);
                    break;  
            
                case 3:
                    system ("pause");
                    return 0;                
    } 
   }                   
   system ("pause");
   return 0;
  }      


int menu(void)
{
  int c;
  printf ("Introduzca opcion: \n");
  printf ("1 - Insertar nombres en la lista \n");
  printf ("2 - Mostrar lista de nombres \n");
  printf ("3 - Salir \n");
  scanf ("%d", &c);
  return c;
} 
  
void insert(void)
{
  int i= 0, s; 
  char resp;
  printf ("cuantos nombres quiere introducir? \n");
  scanf ("%d", &num);
  do
   {
     printf ("Introduzca nombre: \n");
     scanf("%s", nombres[i]);
     fflush (stdin);
     i++;
   } while (i<num); 
   
     printf ("Quiere mostrar la lista? \n");
     scanf ("%c", &resp); 
     if (resp=='s')
     {
       mostrar(nombres, num);
     }
     else 
     system ("pause");
     
} 
 


void mostrar( char nombres[10][15], int num)
{
  int i, j, intercambio=0;
  char aux[10];
  do {
       for (i=0; i < num-1; i++)
       {
         if (strcmp (nombres[i], nombres[i+1] > 0)
         {
           strcpy (aux, nombres[i]);
           strcpy (nombres[i], nombres[i+1]);
           strcpy (nombres[i+1], aux);
           intercambio= 1;
         }
       }num--;    
    }while (intercambio ==1 && num > 1);
    
     for (i=0 i < num; i++=
     {
       puts (nombres[i]);
     }
     system ("pause");  
}      
