
/* fichero video.cpp.
   Aqui se implementan las funciones o metodos de la clase video. */

#include "video.h"
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std; //  Usando espacio de nombres estandar.

/* Se utiliza el operador de ambito (::) porque estamos implementando las funciones
   fuera del archivo donde está la clase */

   
 void video::set_nombre(char *nom) 
 {                                 
    if(strlen(nom) > 0 && strlen(nom) < 40)
    {
      strcpy(nombre, nom);
    }
    else cout << "Error. Nombre demasiado largo" << endl;
 }  
 
 
 void video::set_director(char *dire) 
 {
   if(strlen(dire) > 0 && strlen(dire) < 40)
   {
      strcpy(director, dire);
   }
   else cout << "Error: Nombre demasiado largo" << endl;
 }                
 
 
 void video::set_genero(char *gene)
 {
   if(strlen(gene) > 0 && strlen(gene) < 40)
   {
      strcpy(genero, gene);
   }
   else cout << "Error. Nombre demasiado largo" << endl;
 }
 
 
 void video::set_cantidad(int a)
 {
   cantidad= a;
 }            
 

   
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
 
 /* static int get_total()
 {
   return total;
 }  */
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       
                     
 // Funcionales 
 
 void video::leer_teclado()
 {
    char nomb[80], dir[80], gen[80];
    int cant;
    cout << "Nombre: ";
    cin.getline(nomb, 80, '\n');
    cout << "Director: ";  
    cin.getline(dir, 80, '\n');
    cout << "Genero: ";
    cin.getline(gen, 80, '\n');
    cout << "Cantidad: ";
    cin >> cant;
    set_nombre(nomb);
    set_director(dir);
    set_genero(gen);
    set_cantidad(cant);
    //set(nomb, dir, gen, cant);   
 }                              
 
 
 void video::imprimir()
 {
    cout << "Nombre: " << nombre << endl;   
    cout << "Director: " << director << endl; 
    cout << "Genero: " << genero << endl;
    cout << "Cantidad: " << cantidad << endl;
 }                    
 
 
  bool video::guardar_fichero(char *nomb)
  {
    fstream fichero;
    fichero.open(nomb, ios::out | ios::app );
    
    if(!fichero)
    {
      return false;
    }  
    fichero.write((char *) this, sizeof(*this));
    
    if(fichero.fail())
    {
      cerr << "No se ha podido escribir";
      return false;  
    } 
    fichero.close();
    return true;
  }  
          
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
  bool video::leer_fichero(char *nomb, int n)
  {
    fstream fichero;
    fichero.open(nomb, ios::in );
    
    if(!fichero)
    {
      return false;
    }  
    fichero.seekg((n-1)* sizeof(*this), ios::beg);
    fichero.read((char *) this, sizeof(*this));
    
    if(fichero.fail())
    {
      cerr << "No se ha podido leer";
      return false;  
    }   
    fichero.close();
    return true;
 }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
