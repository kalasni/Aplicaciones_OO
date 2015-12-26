#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct
{
  char *nombre;
  char *direccion;
  int dni;
  int potencia;
  float consumo; 
  
} clientes; 

void iniciar_cliente (clientes *lista, int elementos);
int menu(void);
int intro_cliente (clientes *lista, int elementos, int posicion);
void eliminar_cliente (clientes *lista, int dni, int elementos);
void mostrar_cliente (clientes *lista, int elementos);
int buscar_cliente ( clientes *lista, int elementos, int dni);
void buscar_cliente2 (clientes *lista, int elementos, int dni);
void facturar (clientes *lista, int elementos);
int buscar_dni(void);

clientes *lista;
int elementos, posicion= 0;


int main()
{
lista= NULL;
printf ("numero de clientes? \n");
scanf ("%d", &elementos);

lista= (clientes*) malloc (sizeof(clientes)*elementos);

for (;;)
{
    int dni, i;
    char opci, car;
    opci = menu();
           
	   switch (opci) {
           
		  case 1:  iniciar_cliente (lista, elementos);
			   break;
                           
                  case 2:  do
		           {

			     for (i=0; i<elementos; i++)
                             {
			       if ((lista+i)->dni==0)
                               {
				 intro_cliente (lista, elementos, posicion);
				 posicion++;
				 break;
                               }
                             }
			     if (i==elementos)
                             {
                               printf ("Lista llena \n");
                               break;
			     }
			     fflush (stdin);
			       printf ("Desea continuar? \n");
			       scanf ("%c", &car);
			       fflush (stdin);

			   }while (car=='s');
			    break;



		  case 3: buscar_cliente (lista, elementos, dni);
			  break;

		  case 4: facturar (lista,  elementos);
			  break;

		  case 5: eliminar_cliente (lista, buscar_dni(), elementos);
			  break;


		  case 6: exit(0);
	    }
   }
 }


int menu(void)
{
  int a;
     printf ("(1) - INICIALIZAR LISTA \n");
     printf ("(2) - INTRODUCIR CLIENTES \n");
     printf ("(3) - BUSCAR CLIENTE \n");
     printf ("(4) - MOSTRAR FACTURA DE CLIENTE \n");
     printf ("(5) - ELIMINAR CLIENTE \n");
     printf ("(6) - SALIR \n");

     scanf ("%d", &a);
     fflush (stdin);
     return a;
}


int intro_cliente (clientes *lista, int elementos, int posicion)
{
  clientes c;

  float ant, act;
  char buffer[80];

  printf ("nombre  :");
  scanf ("%s", &buffer);
  fflush (stdin);
  c.nombre= (char*)malloc (strlen(buffer)+1);
  strcpy (c.nombre, buffer);
  printf ("Direccion :");
  scanf ("%s", &buffer);
  fflush (stdin);
  c.direccion= (char*)malloc (strlen(buffer)+1);
  strcpy (c.direccion, buffer);


  do
  {
    printf ("DNI :" );
    scanf ("%d", &c.dni);
    fflush (stdin);

  } while (c.dni <= 0 || buscar_cliente (lista, elementos, c.dni)!= -1);

  printf ("Contador anterior :");
  scanf ("%f", &ant);
  fflush (stdin);
  printf ("Contador actual :");
  scanf ("%f", &act);
  fflush (stdin);
  c.consumo=  act - ant;

  do
  {
    printf ("Potencia contratada: ");
    scanf ("%d", &c.potencia);
    fflush (stdin);

  }while (c.potencia!= 1500 && c.potencia!= 3300 && c.potencia!= 4500);


  lista[posicion]=c;


  printf ("\n\n");

}


void eliminar_cliente (clientes *lista, int dni, int elementos)
{
   int posicion;
   posicion= buscar_cliente (lista, elementos, dni);

   if (posicion >= 0)
   {
     (lista + posicion)->dni=0;
     (lista + posicion)->consumo=0;
     (lista + posicion)->potencia=0;

     if (posicion > 0)
     {
       free (&(lista + posicion)->nombre);
       (lista + posicion)->nombre=NULL;

       free (&(lista + posicion)->direccion);
       (lista + posicion)->direccion=NULL;

     }
       printf ("Se ha eliminado el cliente \n");
   }
   else printf ("No se puede eliminar cliente \n");
}

void iniciar_cliente (clientes *lista, int elementos)
{
  int i=0;

    while (i<elementos)
    {
      (lista+i)->nombre=NULL;  (lista+i)->consumo=0;
      (lista+i)->direccion=NULL; (lista+i)->potencia=0;
      (lista+i)->dni=0;
      i++;
    }
}



int buscar_cliente (clientes *lista, int elementos, int dni)
{

    int i=0;

    while (i<elementos)
    {
      if (dni== (lista+i)->dni)
      {
	return i;
      }
      i++;
    }
     return -1;

  }


void facturar (clientes *lista, int elementos)
{
   int posicion ;
   char car='n';
   float consumo, potencia, alquiler= 0.57, total, subtotal, impuesto, iva;


   do
   {
     posicion= buscar_cliente (lista, elementos, buscar_dni());

     if (posicion < 0)
     {
       printf ("ERROR \n");
       printf ("Desea continuar? (s/n) \n\n");
       car= getchar();
       fflush (stdin);
      }

    } while (car=='s' || posicion < 0);


     if (posicion >= 0)
     {
	printf ("           DATOS PERSONALES \n\n");

	consumo= 2.0 * (0.084 * (lista + posicion)->consumo);
	potencia= 2.0 * (0.014 * (lista + posicion)->potencia);
	impuesto= ((consumo + potencia) * 4.4864) / 100.0;
	alquiler= (0.57 * 2.0) / 100.0;
	subtotal= consumo + potencia + impuesto + alquiler;
	iva= (subtotal * 16.0) / 100.0;
	total = consumo + potencia + impuesto + alquiler + iva;


        printf ("nombre:   %s \n", (lista + posicion)->nombre);
        printf ("direccion:   %s \n",  (lista + posicion)->direccion);
        printf ("dni:   %d \n", (lista + posicion)->dni);
        printf ("consumo:   %f \n", (lista+ posicion)->consumo);
        printf ("potencia:   %d \n", (lista + posicion)->potencia);
        printf ("\n\n");

        printf ("          DATOS ECONOMICOS \n\n");
        printf ("CONCEPTO         PRECIO              TOTAL \n\n");
        printf ("Consumo         0.084 ?/KWH            %f euros            \n", consumo);
        printf ("Potencia        0.014 ?/KW mes         %f euros            \n", potencia);
   
        printf ("Subtotal                               %f euros\n", subtotal);
        printf ("Iva             16                     %f euros\n", iva);
        printf ("Alquiler        0.57 ? (mes)           %f euros\n", alquiler);
	printf ("\n\n");
	printf ("Total (iva incluido)                       %f euros\n", total);
	printf ("\n\n");
  }                   
}                                                                      
   
  int buscar_dni(void)
  {
    int dni;
    printf ("Introduzca el dni: \n");
    scanf ("%d", &dni);
    fflush (stdin);
    return dni;
  }
  
 
