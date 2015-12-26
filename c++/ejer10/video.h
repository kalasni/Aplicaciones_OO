#ifndef VIDEOH
#define VIDEOH
#include <iostream>
#include <string.h>

using namespace std; //  Usando espacio de nombres estandar.

class video
{
   private:
       char *nombre;
       char *director;
       char *genero;
       int cantidad;
       
       
   public:
       // constructores
       video();
       video(char *, char *, char *, int);
       video(const video &v); //constru. copia
       ~video();
       
       // modificadores (Cambian alguna propiedad u objeto de la clase).
       bool set(char *, char *, char*, int); 
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
       bool leer_teclado();
       bool guardar_fichero(char *);
       bool leer_fichero(char *, int n);
       
       // Operadores sobrecargados
       video & operator =(const video &v);
       video & operator ++ (); // operador ++ prefijo ----> ++v
       video & operator ++ (int); // operador ++ sufijo ---> v++
       friend bool operator == (const video &v1, const video &v2);
       friend ostream & operator << (ostream &s, const video &v);
       
};


#endif       
                       
