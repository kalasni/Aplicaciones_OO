#ifndef VIDEOH
#define VIDEOH
#include <iostream>
#include <string.h>

const int tam= 40;

class video
{
   private:
       char nombre[tam];
       char director[tam];
       char genero[tam];
       int cantidad;
    // static int total;
       
   public:
       // modificadores (Cambian alguna propiedad u objeto de la clase).
       /* void set(char *, char *, char*, int); */
       void set_nombre(char *);
       void set_director(char *);
       void set_genero(char *);
       void set_cantidad(int);
       
       // Inspectores. (Devuelven alguna propiedad de la clase).
       char *get_nombre();
       char *get_director();
       char *get_genero();
       int get_cantidad();
       //int get_total();
       
       // Funcionales
       void imprimir();
       void leer_teclado();
       bool guardar_fichero(char *);
       bool leer_fichero(char *, int n);
       
};

// total=0;

#endif       
                       
