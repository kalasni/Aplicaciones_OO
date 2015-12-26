#include <stdio.h>
#include <stdlib.h>
#define max 100

struct dir {
    char nombre[30];
    char direccion[40];
    char edad[3];
    char sexo[7];
    char telefono[12];
 } agenda[100];
 
 void inic_agenda(void), intro(void), modi_nombre(void);
 void borrar(void), mostrar(void), busca_regis(void), muestra_contacto(int j);
 int menu(void), menu_buscar(void);
 int busca_libre(void);
 int sitio;
 
 int main()
 {
   char opci;
   inic_agenda();     // Inicializa el array de estructura.
   
   
     for (;;)
     {
     opci= menu();
     switch (opci) {
           case 1:  intro();
                    break;
           
           case 2:  borrar();
                    break;
           
           case 3:  mostrar();
                    break;
           
           case 4:  inic_agenda();
                    break;
                    
           case 5:  modi_nombre();
                    break;         
           
           case 6:  busca_regis();
                    break;
                    
           case 7:  
                    return 0;
     }
    } 
  }
  
