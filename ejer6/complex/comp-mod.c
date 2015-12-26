#include <stdio.h>
#include <stdlib.h>

struct comple
{
  float r;
  float i;
};

struct comple sumar (struct comple a, struct comple b);
struct comple restar (struct comple a, struct comple b);
struct comple multi (struct comple a, struct comple b);
struct comple dividir (struct comple a, struct comple b);
int menu (void);
void entr_datos (void);
void imprimir (struct comple c);
void impri_divi (struct comple c);

struct comple a, b, c;
float denomina;




 int menu(void)
 {
   int c;

   printf ("======================================\n");
   printf ("Elija el calculo que quiere realizar: \n");
   printf ("======================================\n");
   printf ("\n");
   printf ("(1) - SUMA \n");
   printf ("(2) - RESTA \n");
   printf ("(3) - MULTIPLICACION \n");
   printf ("(4) - DIVISION  \n");
   printf ("(5) - SALIR \n");
   printf ("\n");

   scanf ("%d", &c);

   return c;
 }


  /* Función para introducir los datos */
  
void entr_datos (void)
{
  puts ("Primer numero complejo \n");
  puts ("Introduzca parte real e imaginaria separadas por espacios: ");
  scanf ("%f %f", &a.r, &a.i);
  puts ("Segundo numero complejo  ");
  scanf ("%f %f", &b.r, &b.i);
}


  /* Calcula suma */

struct comple sumar(struct comple a, struct comple b)
{
   c.r= a.r + b.r;
   c.i= a.i + b.i;
   return c;
}

  /* Calcula resta */

struct comple restar (struct comple a, struct comple b)
{
   c.r= a.r - b.r;
   c.i= a.i - b.i;
   return c;
}   

 /* Calcula multiplicación */ 

struct comple multi (struct comple a, struct comple b)
{
   float tem1, tem2, tem3, tem4;

   tem1= a.r * b.r;   tem3= a.r * b.i;
   tem2= a.i * b.i;   tem4= a.i * b.r;

   c.r= tem1 - tem2;
   c.i= tem3 + tem4;

   return c;
}   


 /* Calcula división */

struct comple dividir (struct comple a, struct comple b)
{
  
   float tem1, tem2, tem3, tem4;
   
   denomina= (b.r * b.r) + (b.i * b.i);

   tem1= a.r * b.r;   tem3= a.i * b.r;
   tem2= a.i * b.i;   tem4= a.r * b.i;
   
   c.r= tem1 + tem2;
   c.i= tem3 - tem4;
   
   return c;
 }


 /* Función para imprimir resultados (suma, resta, multiplicación) */

 void imprimir (struct comple c)
 {  
    system ("cls");
    printf ("\n\n\n"); 
    printf ("Parte real: %f \n", c.r);
    printf ("Parte imaginaria: %fi \n\n", c.i);
 }   
 
 
 /* Función para imprimir resultado de la división */
 
 void impri_divi (struct comple c)
 {
    system ("cls");
    printf ("\n\n\n"); 
    printf ("%f     %fi \n", c.r, c.i);
    printf ("---------  +  --------- \n");
    printf ("%f     %f", denomina, denomina);
    printf ("\n\n");
 }









            
