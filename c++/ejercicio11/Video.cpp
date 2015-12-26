#include "Video.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

Video::Video()
{
    nombre= new char[strlen("")+1];
    strcpy(nombre,"");
    director= new char[strlen("")+1];
    strcpy(director,"");
    genero= new char[strlen("")+1];
    strcpy(genero,"");
    cantidad= 0;
}

Video::Video(char *nom, char *dir, char *gen, short num):
    nombre(nom), director(dir), genero(gen), cantidad(num)
{
}

Video::Video(const Video& unvideo)
{
    nombre= new char[strlen(unvideo.getNombre())+1];
    strcpy(nombre, unvideo.getNombre());
    director= new char[strlen(unvideo.getDirector())+1];
    strcpy(director, unvideo.getDirector());
    genero= new char[strlen(unvideo.getGenero())+1];
    strcpy(genero, unvideo.getGenero());
    cantidad= unvideo.getCantidad();
}

Video::~Video()
{
    delete []nombre;
    delete []director;
    delete []genero;   
    cout << "\n llamando al destructor \n"; 
}
 
bool Video::set(char *nom, char *dir, char *gen, short num)     
{
    if (strlen(nom)>0 && strlen(dir)>0 && strlen(gen)>0 && num>0)
    {
           delete []nombre;
           delete []director;
           delete []genero;
           nombre= new char[strlen(nom)+1];
           strcpy(nombre,nom);
           director= new char[strlen(dir)+1];
           strcpy(director,dir);
           genero= new char[strlen(gen)+1];
           strcpy(genero,gen);
           cantidad= num;
           return true;
    }
    else
           return false;
}

bool Video::setNombre(char *nom)
{
    if (strlen(nom)>0 )
    {
           delete []nombre;
           nombre= new char[strlen(nom)+1];
           strcpy(nombre,nom);
           return true;
    }
    else
           return false;
}

bool Video::setDirector(char *dir)
{
    if (strlen(dir)>0 )
    {
           delete []director;
           director= new char[strlen(dir)+1]; 
           strcpy(director,dir);
           return true;
    }
   else
           return false;
}

bool Video::setGenero(char *gen)
{
    if (strlen(gen)>0 )
    {
           delete []genero;
           genero= new char[strlen(gen)+1]; 
           strcpy(genero,gen);
           return true;
    }
    else
           return false;
}

bool Video::setCantidad(short can)
{
    if (can>0 )
    {
           cantidad= can;
           return true;
    }
    else
           return false;
}

bool Video::Leer()
{
    char nombre[80], director[80], genero[80];
    int cantidad;
    cout << "Nombre: " << flush;
    cin.getline(nombre,80,'\n');
    cout << "Director: " << flush;
    cin.getline(director,80,'\n');
    cout << "Genero: " << flush;
    cin.getline(genero,80,'\n');
    cout << "Cantidad: " << flush; 
    cin >> cantidad ;
    return set(nombre, director, genero, cantidad);
}

void Video::Imprimir()
{
    cout.setf(ios::left);
    cout.width(30);
    cout << getNombre();
    cout.width(20);
    cout << getDirector();
    cout.width(10);
    cout << getGenero();
    cout.width(4);
    cout << getCantidad();
}

bool Video::GuardarFichero(char *nombre)
{
    fstream fichero;
    fichero.open(nombre, ios::out | ios::app);
    if (!fichero)
    {
        cerr << "No se puede escribir el fichero" << endl;
        return false;
    }
    fichero << getNombre() << '/' << getDirector() << '/' <<getGenero() 
    << '/' << getCantidad() << endl;
    if (!fichero.fail())
    {
        fichero.close();
        return true;
    }
    return false;    
}

bool Video::LeerFichero(char *nomb, int num)
{
    char nombre[100], director[100], genero[100];
    int cantidad;
    fstream fichero;
    fichero.open(nomb, ios::in);
    if (!fichero)
    {
        cerr << "No se puede leer el fichero" << endl;
        return false;
    }
     for (int i= 0; i<num && !fichero.eof(); i++)
    {
        fichero.ignore(100,'\n');
        if (fichero.eof())
        {
            return false;
        }
    }
    if  (!fichero.eof() && !fichero.fail()) 
    {
        fichero.getline(nombre,100,'/'); 
        fichero.getline(director,100,'/');
        fichero.getline(genero,100,'/');
        fichero >> cantidad ;
        fichero.close();
        return set(nombre, director, genero, cantidad);
    }
     
    return false;    
}

// operadores

int Video::operator== (const Video &v)
{
    if ( !strcmp(nombre,v.getNombre()) && !strcmp(director,v.getDirector())
         && !strcmp(genero,v.getGenero()) && cantidad== getCantidad())
         return 1;
    else
         return 0;
}

Video & Video::operator= (const Video &v)
{
    if (*this == v)
        return *this;
    else
    {
        delete []nombre;
        delete []director;
        delete []genero;
        nombre= new char[strlen(v.getNombre())+1];
        strcpy(nombre,v.getNombre());
        director= new char[strlen(v.getDirector())+1];
        strcpy(director,v.getDirector());
        genero= new char[strlen(v.getGenero())+1];
        strcpy(genero,v.getGenero());
        cantidad= v.getCantidad();
        return *this;
    }
}

Video& Video::operator++()
{
    cantidad++;
    return *this;
}

Video& Video::operator++(int)
{
    ++cantidad;
    return *this;
}

Video& Video::operator--()
{
    if (cantidad>0)
    {
        --cantidad;
    }
    return *this;
}

Video& Video::operator--(int)
{
    if (cantidad>0)
    {
        cantidad--;
    }
    return *this;
}



