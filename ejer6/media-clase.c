#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 50

typedef float matriznotas[3][4];
typedef char matriznombres[3][30];
void leernotas (int * alumnos, matriznotas m, matriznombres n);
float media (int alumnos, matriznotas m);
int main()
{
  matriznotas notas;
  matriznombres nombres;
  int i, j, alumnos;
  float suma;
  leernotas (&alumnos, notas, nombres);
  media (alumnos, notas);
  
  for (i=0; i<alumnos; i++)
  {
    suma= 0;
    for (j=0; j<4; j++)
    {
      suma += notas[i][j];
    } 
    printf ("La nota media de %s es: " , nombres[i]);  
    printf ("%f", suma / 4);
    printf ("\n");
  }
    printf ("La nota media de la clase es %f \n\n", media (alumnos, notas));  
    system ("pause");
    return 0;
 }   

void leernotas (int * alumnos, matriznotas m, matriznombres n)
{
  int i, j;
  do {
       printf ("Introduce numero de alumnos: \n");
       scanf ("%d", alumnos);
     } while ((* alumnos < 0) || (* alumnos >50));  
     
     
     for (i=0; i <* alumnos; i++)
     {
        printf ("Nombre de alumno: ");
        scanf ("%s", &n[i]);
        for (j=0; j<4; j++)
        {
           printf ("Nota del trimestre: %d:", j+1);
           scanf ("%f", &m[i][j]);
           fflush (stdin);
        } 
      }     
 }     
 float media (int alumnos, matriznotas m)
 {
   int i, j;
   float sumanotas= 0; 
   for (i=0; i<alumnos; i++)
   {
     for (j=0; j<4; j++)
     {
       sumanotas+= m[i][j];
     }
   }
   return sumanotas / (alumnos*4);
 }         
