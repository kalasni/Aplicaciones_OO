/* Programa que guarda los datos de los pacientes de un hospital mediante
   una estructura y despues opcionalmente se puede mostrar los paciente
   que tengan que pasar consulta un determinado dia. (28-05-03) */
   

#include <stdio.h>
#include <stdlib.h>
#define max 100


struct paciente
{
  char *nombre;
  char *direccion;
  char fecha[15];
  char sexo[2];
  char diavisi[15];
  char *historial;
};

int entr_datos (struct paciente **);
void mostrar_datos (char *dia, struct paciente*);

int main()
{
  char dia[10];
  struct paciente *p= NULL;
  entr_datos(&p);
  puts ("Introduzca la fecha de la consulta (dia/mes/anno) ");
  gets (dia);
  mostrar_datos(dia, p); 
  system ("pause");
  return 0;
 }
 
  int entr_datos (struct paciente **ptro)
  {
   int i;
   char aux[80], a;
   struct paciente *pt;
   pt= (struct paciente*) malloc(max*sizeof(struct paciente));
   printf ("ENTRADA DE DATOS  \n\n\n");
   for (i=0; i<max; i++)
   {
      printf ("Nombre del paciente: \n");
      gets (aux);
      fflush (stdin);
      (pt+i)->nombre= malloc(strlen(aux)+1);
      strcpy ((pt+i)->nombre, aux);
      puts ("Direccion del paciente: \n");
      gets (aux);
      fflush (stdin);
      (pt+i)->direccion= malloc(strlen(aux)+1);
      strcpy (pt->direccion, aux);
      puts ("Fecha de nacimiento (dia/mes/anno) \n");
      gets (pt->fecha);
      fflush (stdin);
      puts ("Sexo del paciente: \n");
      gets (pt->sexo);
      fflush (stdin);
      puts ("Dia de la visita (dia/mes/anno) \n");
      gets (pt->diavisi);
      fflush (stdin);
      puts ("Historial medico del paciente: \n");
      gets (aux);
      fflush (stdin);
      (pt+i)->historial= malloc(strlen(aux)+1);
      strcpy ((pt+i)->historial, aux);
      puts ("Desea introducir mas pacientes? (s/n) \n");
      scanf ("%c", &a);
      fflush (stdin);
      if (a=='n') break;
     }
     *ptro=pt;
 }
 
  void mostrar_datos (char *dia, struct paciente *pt)
  {
    int j;
    printf ("Pacientes con visita el dia %s \n\n", dia);
    printf ("\n\n");
    for (j=0; j<max; j++)
    {
      if (!strcmp (dia, (pt+j)->diavisi))
      {
        printf ("%s \n", (pt+j)->nombre);
      }
    }
  }      
           
        
  
