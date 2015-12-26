/* fichero fechas.cpp.
   Aqui se implementan las funciones o metodos de la clase fechas. */
   
#include "fechas.h" 
#include <iostream>
#include <string>

using namespace std; //  Usando espacio de nombres estandar.

/* Se utiliza el operador de ambito (::) porque estamos implementando las funciones
   fuera del archivo donde está la clase */


bool fecha:: comprobar(int d, int m, int a)
{
  if(a <=0) return false;
  if(m <=0 || m > 12)
  {
    return false;
  }
  if((m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12) && (d<=0 || d>31)) 
  {
    return false;
  }
  if((m==4 || m==6 || m==9 || m==11) && (d < 1 || d > 30))
  {
    return false;
  }
  if((m==2) && (a%4==0) && (d<1 || d>29))
  {
    return false;
  }
  if((m==2) && (d<1 || d>28)) 
  {
    return false;
  }
  return true;
}      


int fecha::convertir(string mes)
{
  string meses[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", 
                    "agosto", "septiembre", "octubre", "noviembre", "diciembre"};
  
  for(int i=0; i<12; i++)
  {
    if(mes==meses[i])
    return i+1;
  }
  return 0;
}   
   

/************************************************************************/ 
// Constructores  

fecha::fecha(int a, int b, int c)
{
  if(comprobar(a, b, c))
  {
    set(a, b, c);
  }
  else set (1, 1, 1900);
}


fecha::fecha(int a, char *m, int c)
{
  string mm= m;
  int b= convertir(mm);
  
  if(comprobar(a, b, c))
  {
    set(a, b, c);
  }
  else set (1, 1, 1900);
}     


    
/************************************************************************/
// Modificadores
   
bool fecha::set(int d, char *b, int a)
{
  string mm= b;
  int m= convertir(mm);
  if(comprobar(d, m, a))
  {
    dia= d;
    mes= m;
    anno= a;
    return true;
  }
  return false;      

}

bool fecha::set(int d, int m, int a)
{
  if(comprobar(d, m, a))
  {
    dia= d;
    mes= m;
    anno= a;
    return true;
  }
  return false;      

}


bool fecha::set_dia(int d)
{
  if(comprobar(d, mes, anno))
  {
    dia= d;
    return true;
  }
  return false;
}


bool fecha::set_mes(int m) 
{    
  if(comprobar(dia, m, anno))
  {
    mes= m;
    return true;
  }
  return false;
}

  
  
bool fecha::set_mes(char *a)
{
  string mm=a;
  int m= convertir(mm);
  if(comprobar(dia, m, anno))
  {
    mes= m;
    return true;
  }
  return false;
}


bool fecha::set_anno(int a)
{
  if(comprobar(dia, mes, a))
  {
    anno=a;
    return true;
  }
  return false;
}


bool fecha::leer()
{
  int dd, mm, aa;
  string m;
  cout << "Dia: ";
  cin >> dd;
  cout << "Mes (en nombre): ";
  cin >> m;
  cout << "Anno: ";
  cin >> aa;
  mm= convertir(m);
  return set(dd, mm, aa);
}

  
/***********************************************************************/
// Inspectores

inline int fecha:: get_dia(void)
{
  return dia;
}
  
inline int fecha:: get_mes(void)
{
  return mes;
}


inline int fecha::get_anno(void)
{
  return anno;
}        
    
    
string fecha::get_mes_nombre() 
{
  string meses[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio",
   "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre"};  
   
   return meses[mes-1];  
}   


void fecha::imprimir()
{
  cout << get_dia() << ' '
  << get_mes_nombre() << ' ' << get_anno();
}

  
/*************************************************************************/ 
// Operadores

bool fecha::operator < (const fecha &f)
{
  if(anno > f.anno)
  {
    return true;
  }
  else if(anno== f.anno && mes > f.mes) 
  {
    return true;
  }  
  else if((anno== f.anno) && (mes==f.mes) && (dia > f.dia)) 
  {
    return true;
  }
  return false;
}    


bool fecha::operator > (const fecha &f)
{
  if(anno < f.anno)
  {
    return true;
  }
  else if(anno== f.anno && mes < f.mes) 
  {
    return true;
  }  
  else if((anno== f.anno) && (mes==f.mes) && (dia < f.dia)) 
  {
    return true;
  }
  return false;
}    
 
bool operator >=(const fecha &f1, const fecha &f2)
{
  if(f1.anno <= f2.anno)
  {
    return true;
  }
  else if((f1.anno== f2.anno) && (f1.mes <= f2.mes))
  {
    return true;
  }  
  
  else if((f1.anno== f2.anno) &&  (f1.mes <= f2.mes) && (f1.dia <= f2.dia))  
  {
     return true;
  }
  return false;
}


fecha & fecha::operator= (const fecha &f)
{
  if (*this== f)
  {
    return *this;
  }
  dia= f.dia;
  mes= f.mes;
  anno=f.anno;
  return *this;
}
  
bool fecha::operator==(const fecha &f)
{
  if(dia==f.dia && mes==f.mes && anno==f.anno)
  {
    return true;
  }
  return false;
    
} 

      
