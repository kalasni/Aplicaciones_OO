#ifndef FECHAS_H
#define FECHAS_H
#include <iostream>
#include <string.h>


class fechas
{
  private:
      int dia;
      int mes;
      int anno;
      
    
  public:   
      // Modificadores (Cambian alguna propiedad u objeto de la clase).
      void set_dia(int);
      void set_mes(int);
      void set_anno(int);
   
  
      // Inspectores (Devuelven alguna propiedad de la clase).
      int get_dia();
      int get_mes();
      int get_anno();
      
     // Funcionales
      void imprimir();
      void leer_teclado();
      //void diferencia(
     
};

#endif                   
