/* Programa para calcular operaciones con numeros complejos (suma, resta
   multiplicación y división) mediante el uso de estructuras.
   (15-05-03) */



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
                   
           case 5: system ("pause");
                   return 0;
     }
   }
 }


 
