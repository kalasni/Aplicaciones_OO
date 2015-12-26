/* Programa que lee los nombres de los integrantes de un equipo de futbol
   y las fechas de nacimiento de cada uno de ellos (la fecha la lee en 
   una sola entrada) y guarda la fecha en un objeto string.
   Despues muestra los nombres y el año de cada uno. (02-07-03) */
   

#include <iostream>
#include <string>
#include <cstdlib>
#define max 11

using namespace std;

struct futbolista
{
  string nombre;
  int dia, mes, anno;
  
};

futbolista equipo[max];

int calcular_mes(const string &m);
futbolista leer_futbolista();

string meses[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                  "julio", "agosto", "septiembre","octubre","noviembre","diciembre"};

int main()
{

  cout << "Introduce jugadores \n" << endl;
  for(int i=0; i<max; i++)
  {
    equipo[i]= leer_futbolista();
    cout << endl;
  } 
  /* Falta mostrar los futbolistas de la estructura */
  
  system("pause");
  return 0;
}  
  
  
  
 futbolista leer_futbolista()  
 {
   bool correcto= false;
   futbolista f;
   char linea[80];
   cout << "Nombre: " << flush;
   cin >> linea;
   f.nombre= linea;
   cin.ignore(100, '\n');
   
   while (!correcto)
   {
     correcto= true;
     cout << "Fecha de nacimiento:";
     cin.getline(linea, 80, '\n');
     string fecha(linea);
     int i= fecha.find(' ');
   
     if(i < 0 || i > fecha.size())
     {
       cout << "Error. Fecha incorrecta" << endl;
       correcto= false;
       continue;
     }
     else 
     {
       string dia= fecha.substr(0, i);
       f.dia= atoi(dia.c_str());
       
       if(f.dia < 0 || f.dia > 31)
       {
         cout << "Dia incorrecto \n";
         correcto= false; 
         continue;
       }  
     }
     int j= fecha.find(',');
     
     if(j<0 || j>fecha.size())
     {  
       cout << "Mes incorrecto \n" << endl;
       correcto= false;
       continue;
     }
     else 
     {
       string mes= fecha.substr(i+1, j-i-1); 
       f.mes= calcular_mes(mes);
       
       if(f.mes==0)
       {
         cout << "Mes incorrecto \n";
         correcto= false;
         continue;
       }   
     }
     string anno= fecha.substr(j+2, fecha.size() - j-2);  
     f.anno= atoi(anno.c_str());
     
     if(f.anno <=0)
     {
       cout << "Anno incorrecto" << endl;
       correcto= false;
     }
   } // cierra el while    
   
   return f;
 }  
 
 
 int calcular_mes(const string &m)
 {
   for(int i=0; i<12; i++)
   {
     if(meses[i]==m)
     {
       return i+1;
     }
   }
   return 0;
 }      
