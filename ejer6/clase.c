#include <stdio.h>
#include <stdlib.h>
#define MAX_ALUMNOS 50
#define NOTAS 4


int main()
{
    int clase[MAX_ALUMNOS][NOTAS];
    int alumnos, i, j;
    float media_alum, media_clase;

    printf("Cuantos alumnos tiene la clase?: ");
    scanf("%d",&alumnos);

    if (alumnos > MAX_ALUMNOS) 
    {
       printf ("El limite de alumnos es 50\n");
       return 0;
    }

    for (i=0; i<alumnos; i++) 
    {
       printf("Introduzca las 4 notas del alumno %d separadas por espacio: ",i+1);
       for (j=0; j< NOTAS; j++) 
       {
         scanf ("%d",&clase[i][j]);
       }
         fflush (stdin);   /* esto limpia el buffer entre cada 4 lecturas */
     }

    puts ("\n"); 
    media_clase=0.0;

    for (i=0; i<alumnos; i++)  
    {

       media_alum=0.0;

       for (j=0; j< NOTAS; j++)  
       {
            media_alum += (clase[i][j]);
       }

       printf("La media del alumno %d es: %f \n ",i,media_alum/4);
       media_clase += (media_alum/4);
    }
       media_clase = media_clase/alumnos;
       printf("La media de la clase es: %f \n ",media_clase);
       system ("pause");
       return 0;
}
