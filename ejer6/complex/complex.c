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



int main()
{
  
  char opc;

  for(;;)
  {
    opc= menu();
    switch (opc) {
           case 1: entr_datos();
                   imprimir (sumar (a, b));
                   break;
                   
           case 2: entr_datos();
                   imprimir (restar (a, b));       
                   break;
                   
           case 3: entr_datos();
                   imprimir (multi (a, b));        
                   break;
                   
           case 4: entr_datos();
                   impri_divi (dividir (a, b));
                   break;
                   
           case 5: return 0;
     }
   }
 }


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


void entr_datos (void)
{
  puts ("Primer numero complejo \n");
  puts ("Introduzca parte real e imaginaria separadas por espacios: \n");
  scanf ("%f %f", &a.r, &a.i);
  puts ("Segundo numero complejo \n");
  scanf ("%f %f", &b.r, &b.i);
}

struct comple sumar(struct comple a, struct comple b)
{
   c.r= a.r + b.r;
   c.i= a.i + b.i;
   return c;
}


struct comple restar (struct comple a, struct comple b)
{
   c.r= a.r - b.r;
   c.i= a.i - b.i;
   return c;
}   


struct comple multi (struct comple a, struct comple b)
{
   c.r= (a.r * b.r);
   c.i= a.i * b.i;
   return c;
}   


 void imprimir (struct comple c)
 {
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









            
