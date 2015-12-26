#include <mod-string.h>

char car, cadena[30];
char cadena2[30];
int main()
{
  char opci;
  
   for (;;)
     {
       opci= menu();
       switch (opci) {
       
       
              case 1:  printf ("Introduzca cadena: \n");
                       scanf ("%s", cadena); 
                       system ("cls");
                       printf ("\n\n");
                       printf ("La cadena tiene una longuitud de %d \n\n", long_cad(cadena));
                       system("pause");
                       break;
           
              case 2:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       printf("%s \n\n", copiar_cad (cadena, cadena2));
                       system ("pause");
                       break;
           
              case 3:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       system ("cls");
                       printf ("\n\n");
                       printf("%s \n\n", concate_cad (cadena, cadena2));
                       system ("pause");
                       break;
           
              case 4:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       fflush (stdin);
                       printf ("Introduzca caracter a buscar:\n");
                       scanf ("%c", &car);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n\n", punt_cad (cadena, car));
                       system ("pause");
                       break;
                    
              case 5:  printf ("Introduzca primera cadena: \n");
                       scanf ("%s", cadena);
                       fflush (stdin);
                       printf ("Introduzca segunda cadena:\n");
                       scanf ("%s", cadena2);
                       system ("cls");
                       printf ("\n\n");
                       fflush (stdin);
                       printf ("%d", comp (cadena, cadena2));
                       break;         
           
              case 6:  printf ("Introduzca cadena a convertir: \n");
                       scanf ("%s", cadena);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n", cad_minus (cadena));
                       system ("pause");
                       break;
                    
              case 7:  printf ("Introduzca cadena a convertir: \n");
                       scanf ("%s", cadena);
                       system ("cls");
                       printf ("\n\n");
                       printf ("%s \n", cad_mayus (cadena));
                       system ("pause");
                       break;
              
              case 8:  return 0;
       }
     } 
  }
  
