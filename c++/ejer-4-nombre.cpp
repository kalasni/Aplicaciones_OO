/**************************************************************************
   Programa que lee los nombres de los integrantes de un equipo de futbol
   y las fechas de nacimiento de cada uno de ellos (la fecha la lee en 
   una sola entrada) y guarda la fecha en un objeto string.
   Despues muestra los nombres y el año de cada uno. 
   El programa tambien tiene una opción de ordenar los jugadores por edad
   de más joven a más mayor. (02-07-03) 
**************************************************************************/   


#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#define max 22

using namespace std;

struct futbolista
{
  string nombre;
  int dia, mes, anno;
  
};

int numero= 11;
int cont= 0; // contador de jugadores introducidos.
futbolista *equipo;

int calcular_mes(const string &m);
futbolista leer_futbolista();
int leer_archivo(futbolista *equipo, char *);
void guardar_fichero(futbolista *equipo, char *);
void mostrar_futbolista(futbolista f);
int menor(const futbolista &a, const futbolista &b);
void intercambiar(futbolista &a, futbolista &b);
void ordenar(futbolista *e);
int menu(void);

string meses[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio",
                  "julio", "agosto", "septiembre","octubre","noviembre","diciembre"};

int main()
{
  equipo= new futbolista[numero];
  for(;;)
  {
     int opcion= menu();
     
     switch (opcion) {
      
               case 1:  cont=leer_archivo(equipo, "equipo.dat");
                        break;
               
               
               case 2:  system("cls");
                        cout << "\n\t jugadores del equipo \n" << endl;
  
                        cout.setf(ios::left);
                        cout.width(20);
                        cout << "NOMBRE";
                        cout.width(5);
                        cout << "DIA";
                        cout.width(5);
                        cout << "MES";
                        cout << "ANNO\n" << endl;
  
                        for(int i=0; i<cont; i++)
                        {
                           mostrar_futbolista(equipo[i]);
                        }
                        cout << endl;
                        cout << endl;
                        break;            
               
               
               case 3:  guardar_fichero(equipo,  "equipo.dat");
                        for(int i=0; i<cont; i++)
                        {
                           cout << equipo[i].nombre << endl;
                        }   
                        break;
               
               case 4:  cout << "Introduzca el numero de jugadores:" << endl;
                        cin >> numero;
                        delete []equipo;
                        equipo= new futbolista[numero];
                        cont= 0;
                        cout << "Introduce jugadores" << endl;
                        for(int i=0; i<numero; i++)
                        {
                          equipo[i]= leer_futbolista();
                          cont++;
                          cout << endl;
                        }   
                        break;
                       
                       
               case 5:  cout << "Introduzca el nuevo num de jugadores:" << endl;
                        cin >> numero;
                        guardar_fichero(equipo, "temp");
                        delete []equipo;
                        equipo= new futbolista[numero];
                        cout << "Introduce jugadores" << endl;
                        cont=leer_archivo(equipo, "temp");
                        for(int i=cont; i<numero; i++)
                        {
                           equipo[i]= leer_futbolista();
                           cont++;
                           cout << endl;
                        }  
                        break;
  
               
               case 6:  ordenar(equipo);
                        break;
                        
               case 7:  exit(0);         
                       
     }           
   }
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
  
  
   void guardar_fichero(futbolista *equipo, char *nom)
   {                                        
     ofstream fsalida (nom, ios::app); // ios::app añade en vez de sobreescribir
     for(int i= 0; i<cont && !fsalida.fail(); i++)
     {
       fsalida << equipo[i].nombre << endl;
       fsalida << equipo[i].dia << ' '
       << equipo[i].mes << ' ' << equipo[i].anno << endl;
     }
     fsalida.close();
   }    
  
  
  
   int leer_archivo(futbolista *equipo, char *nom)
   {
     int i=0;
     char buffer[80];
     ifstream fin (nom);
     if(!fin) return 0;
   
     for (i=0; i<numero && !fin.fail(); i++)
     {
        fin.getline(buffer, 80, '\n');
        equipo[i].nombre= buffer;
        fin >> equipo[i].dia >> equipo[i].mes >> equipo[i].anno;
        fin.getline(buffer, 80, '\n');
     }
   
     fin.close();
   
     return i-1;
   }          
  
 
    void mostrar_futbolista(futbolista f)
    {
      cout.setf(ios::left);
      cout.width(20);
      cout << f.nombre;
      cout.width(5);
      cout << f.dia;
      cout.width(5);
      cout << f.mes;
      cout << f.anno << endl;
    }  
   
  
   void ordenar(futbolista e[])
   {
      bool intercambiado= true;
      int n= cont-1;
      cout << cont << endl;
      int i= 0;
      
      while(n > 0 && intercambiado)
      {
        intercambiado= false;
        while(i < n)
        { 
          if(menor(e[i], e[i+1])== -1)
          {
             intercambiar(e[i], e[i+1]);
             intercambiado= true;
          }
          i++;
        }
        i=0;
        n--;
      }
    }         
    
    void intercambiar(futbolista &a, futbolista &b)
    {   
      futbolista aux = a;
                   a= b;
                   b= aux;
    }                     
                      
    
    int menor(const futbolista &a, const futbolista &b)
    {  
      if(a.anno > b.anno) return 1;
      if((a.anno == b.anno) && (a.mes > b.mes))
      {
        return 1;
      }
      if((a.anno == b.anno) && (a.mes==b.mes) && (a.dia > b.dia))  
      {
        return 1;
      }
      if((a.anno==b.anno) && (a.mes==b.mes) && (a.dia==b.dia))
      {
        return 0;
      }
      return -1; 
    }
    
              
        
    int menu(void)
    {
      cout << "(1)- LEER EL FICHERO" << endl;
      cout << "(2)- MOSTRAR EL FICHERO" << endl;
      cout << "(3)- GUARDAR EL FICHERO" << endl;
      cout << "(4)- INTRODUCIR JUGADORES" << endl;
      cout << "(5)- CAMBIAR EL NUMERO DE JUGADORES" << endl;
      cout << "(6)- ORDENAR LOS JUGADORES POR FECHA" << endl;
      cout << "(7)- SALIR DEL PROGRAMA" << endl;
   
      int opc;
      cin >> opc;
   
      return opc;
    }   
 
 
 
 
