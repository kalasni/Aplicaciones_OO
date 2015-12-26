
/* fichero video.cpp.
   Aqui se implementan las funciones o metodos de la clase video. */

#include "video.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std; //  Usando espacio de nombres estandar.

/* Se utiliza el operador de ambito (::) porque estamos implementando las funciones
   fuera del archivo donde está la clase */

/*****************************************************************************/
// constructores y destructor

 video::video()
 {
   nombre= new char[strlen(" ")+1];
   strcpy(nombre, " ");
   director= new char[strlen(" ")+1];
   strcpy(director, " ");
   genero= new char[strlen(" ")+1];
   strcpy(genero, " ");
   cantidad= 0;
 }  
   
 
 video::video(char *nom, char *dire, char *gene, int a): nombre(nom),
 director(dire), genero(gene), cantidad(a)
 {
 }  
 
 video::video(const video &v)
 {
   nombre= new char[strlen(v.nombre)+1];
   director= new char[strlen(v.director)+1];
   genero= new char[strlen(v.genero)+1];
   strcpy(nombre, v.nombre);
   strcpy(director, v.director);
   strcpy(genero, v.genero);
 }
 
 video::~video()  // Destructor
 {
   delete[]nombre;
   delete[]director;
   delete[]genero;
 } 
   

/*****************************************************************************/
// Modificadores
 
 bool video::set(char *nom, char *dire, char *gene, int a)
 {
    if(strlen(nom)>0 && strlen(dire)>0 && strlen(gene)>0 && a>=0)
    {
      delete[]nombre;
      delete[]director;
      delete[]genero;
      nombre= new char[strlen(nom)+1];
      director= new char[strlen(dire)+1];
      genero= new char[strlen(gene)+1];
      strcpy(nombre, nom);
      strcpy(director, dire);
      strcpy(genero, gene);
      cantidad= a;
      return true;
    }
    return false;
  } 
       
 void video::set_nombre(char *nom) 
 {                                 
    if(strlen(nom)>0)
    {
      delete[]nombre;
      nombre= new char[strlen(nom)];
      strcpy(nombre,nom);
    }
    else cout << "Error. Nombre demasiado largo" << endl;
 }  
 
 
 void video::set_director(char *dire) 
 {
   if(strlen(dire)>0)
   {
      delete[]director;
      director= new char[strlen(dire)];
      strcpy(director,dire);
   }
   else cout << "Error: Nombre demasiado largo" << endl;
 }                
 
 
 void video::set_genero(char *gene)
 {
   if(strlen(gene)>0)
   {
      delete[]genero;
      genero= new char[strlen(gene)];
      strcpy(genero,gene);
   }
   else cout << "Error. Nombre demasiado largo" << endl;
 }
 
 
 void video::set_cantidad(int a)
 {
   cantidad= a;
 }            
 
/*******************************************************************************/
 // Inspectores. (Devuelven alguna propiedad de la clase).  

   
 char *video::get_nombre()
 { 
   return nombre;
 }  
  
            
 char *video::get_director()
 {
   return director;
 }
 
 
 char *video::get_genero()
 {
   return genero;
 }
 
 
 int video::get_cantidad()
 {
   return cantidad;
 }
 
/*******************************************************************************/                   
 // Funcionales 
 
 bool video::leer_teclado()
 {
    char nom[150], dir[150], gen[150];
    int cant;
    cout << "Nombre: ";
    cin.getline(nom, 150, '\n');
    cout << "Director: ";  
    cin.getline(dir, 150, '\n');
    cout << "Genero: ";
    cin.getline(gen, 150, '\n');
    cout << "Cantidad: ";
    cin >> cant;
    set_nombre(nom);
    set_director(dir);
    set_genero(gen);
    set_cantidad(cant);
    //set(nomb, dir, gen, cant);   
 }                              
 
 
 void video::imprimir()
 {
    
    cout.setf(ios::left);
    cout.width(30);
    cout << nombre;
    cout.width(20);
    cout << director;
    cout.width(10);
    cout << genero << cantidad << endl;
 }                    
 
 
  bool video::guardar_fichero(char *nomb)
  {
    fstream fichero;
    fichero.open(nomb, ios::out | ios::app );
    
    if(!fichero)
    {
      return false;
    }  
    fichero << nombre <<'#' << director << '#'
    << genero << '#'<< cantidad << endl;
    
    if(fichero.fail())
    {
      cerr << "No se ha podido escribir";
      return false;  
    } 
    fichero.close();
    return true;
  }	 

	 
  bool video::leer_fichero(char *nom, int n)
  {
    char b[150], b2[150], b3[150], b4[80];
    fstream fichero;
    int cant;
    fichero.open(nom, ios::in );
    for (int i=0; i<n && !fichero.eof(); i++)
    {
        fichero.ignore(300,'\n');
        if (fichero.fail() || fichero.eof())
                return false;
    }
    
    if(!fichero.fail() && !fichero.eof())
    {
      fichero.getline(b, 150, '#');
      fichero.getline(b2, 150, '#');
      fichero.getline(b2, 150, '#');
      fichero.getline(b4, 80, '\n');
      cant= atoi(b4);
      fichero.close();
      return set(b, b2, b3, cant);
    }  
    else
    {
      return false;  
    }
    
  }       

/********************************************************************************/
// Operadores sobrecargados. 
  
  video & video::operator=(const video &v)
  {
    if(*this==v)
    {
      return *this;
    }
    set(v.nombre, v.director, v.genero, v.cantidad);  
  }
  
  
  video & video::operator ++ ()
  {
     ++cantidad;    
     return *this;    
  }
 
 
  video & video::operator ++ (int)
  {
     cantidad++;    
     return *this;  
  }
   
   
  bool operator==(const video &v1, const video &v2)
  {
     if(!strcmp(v1.nombre, v2.nombre) && !strcmp(v1.director, v2.director)
         && !strcmp(v1.genero, v2.genero) && v1.cantidad== v2.cantidad)
     {
        return true;
     }
     else
     {
        return false;
     }                        
  }
  
  
  ostream & operator << (ostream &s, const video &v)
  {
     s.setf(ios::left);
	 s.width(30); s << v.nombre;
	 s.width(20); s << v.director;
	 return s;
  }	 

