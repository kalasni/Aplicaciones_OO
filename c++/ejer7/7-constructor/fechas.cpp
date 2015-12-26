/* fichero fechas.cpp.
   Aqui se implementan las funciones o metodos de la clase fechas. */
   
#include "fechas.h" 
#include <iostream>
#include <string.h>

using namespace std; //  Usando espacio de nombres estandar.

/* Se utiliza el operador de ambito (::) porque estamos implementando las funciones
   fuera del archivo donde está la clase */


// Constructor (deber tener siempre el mismo de nombre de la clase).
fechas::fechas(int d, int m, int a)
{
  set_dia(d); //tambien se podria asignar: dia=d;
  set_mes(m);
  set_anno(a);
}  

void fechas::set_dia(int d)
{
  if(d > 0 && d <= 31)
  {
     dia=d;
  }
  else 
  {
     cout << "Error. Dia del mes no valido" << endl; 
  }
}

void fechas::set_mes(int m)
{

enum meses {enero= 1,febrero,marzo, abril, mayo, junio, julio, agosto,
                septiembre, octubre, noviembre, diciembre};

  // Esta función no está bien inplementada (sin terminar).
  if((m > 0 && m <= 12) || (m >= 1 && m <= 12))
  {
     mes=m;
  }
  else 
  {
     cout << "Error. Mes no valido" << endl;
  }
}

void fechas::set_anno(int a)
{
  if(a > 0 && a <= 9999)
  {
     anno=a;
  }
  else 
  {
     cout << "Error. Anno no valido" << endl;
  }
}


 // Inspectores. (Devuelven alguna propiedad de la clase).  
          
              
int fechas::get_dia()
{
  return dia;
}                

int fechas::get_mes()
{
  return mes;
}

int fechas::get_anno()
{
  return anno;
}


// Funcionales

void fechas::leer_teclado()
{
  int d, m, a;
  cout << "Dia: ";
  cin >> d;
  cout << "Mes: ";
  cin >> m;
  cout << "Anno: ";
  cin >> a;
  set_dia(d);
  set_mes(m);
  set_anno(a);
  
}

void fechas::imprimir()
{
  cout << "Dia: " << dia << endl;
  cout << "Mes: " << mes << endl;
  cout << "Anno: " << anno << endl;
}  
  
      
      
