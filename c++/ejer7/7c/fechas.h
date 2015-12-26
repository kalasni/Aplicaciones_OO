#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include <string>

using namespace std;

class fecha
{
  private:
      int dia, mes, anno;
      bool comprobar(int, int, int);
      int convertir(string mes);
      
  public:
  //constructores
      fecha();
      fecha(int, int, int);
      fecha(int, char*, int);
      
              
  //modificadores (Cambian alguna propiedad u objeto de la clase).
      bool set(int, int, int);
      bool set(int, char*, int);
      bool set_dia(int);
      bool set_mes(int);
      bool set_mes(char *);
      bool set_anno(int);
      bool leer();
      
  //inspectores (Devuelven alguna propiedad de la clase).
      int get_dia();
      int get_mes();
      int get_anno();
      string get_mes_nombre();
      void imprimir();
      
  // Funcionales
      bool guardar_fichero(char *);
      bool leer_fichero(char *, int);
      
  // Operadores sobrecargados
      bool operator < (const fecha &f);
      bool operator > (const fecha &f);
      bool operator == (const fecha &f);
      friend bool operator >= (const fecha &f1, const fecha &f2); // friend para que pueda
      // acceder a todos los metodos.
      fecha & operator= (const fecha &f);
};      
                                                          
#endif          
