#include "Video.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

//constructores

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

Video::Video(char *nom)
{
    nombre= new char[strlen(nom)+1];
    strcpy(nombre,nom);
    director= new char[strlen("")+1];
    strcpy(director,"");
    genero= new char[strlen("")+1];
    strcpy(genero,"");
    cantidad= 0;
}

Video::Video(char *nom, char *dir)
{
    nombre= new char[strlen(nom)+1];
    strcpy(nombre,nom);
    director= new char[strlen(dir)+1];
    strcpy(director,dir);
    genero= new char[strlen("")+1];
    strcpy(genero,"");
    cantidad= 0;
}

Video::Video(char *nom, char *dir, char *gen)
{
    nombre= new char[strlen(nom)+1];
    strcpy(nombre,nom);
    director= new char[strlen(dir)+1];
    strcpy(director,dir);
    genero= new char[strlen(gen)+1];
    strcpy(genero,gen);
    cantidad= 0;
}

Video::Video(char *nom, char *dir, char *gen, short num):
    nombre(nom), director(dir), genero(gen), cantidad(num)
{
}

Video::Video(const Video& unvideo)    // constructor copia
{
    nombre= new char[strlen(unvideo.getNombre())+1];
    strcpy(nombre, unvideo.getNombre());
    director= new char[strlen(unvideo.getDirector())+1];
    strcpy(director, unvideo.getDirector());
    genero= new char[strlen(unvideo.getGenero())+1];
    strcpy(genero, unvideo.getGenero());
    cantidad= unvideo.getCantidad();
}

Video::~Video()    // destructor
{
    delete []nombre;
    delete []director;
    delete []genero;   
    cout << "\n llamando al destructor \n"; 
}
 
// modificadores
 
void Video::set(char *nom, char *dir, char *gen, short num)     
{
    if (strlen(nom)>=0 && strlen(dir)>=0 && strlen(gen)>=0 && num>=0)
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
    }
    else
           cout << "¡¡¡ Asignacion incorrecta !!!" << endl;
}

void Video::setNombre(char *nom)
{
    if (strlen(nom)>=0 )
    {
           delete []nombre;
           nombre= new char[strlen(nom)+1];
           strcpy(nombre,nom);
    }
    else
           cout << "¡¡¡ Asignacion incorrecta !!!" << endl;
}

void Video::setDirector(char *dir)
{
    if (strlen(dir)>=0 )
    {
           delete []director;
           director= new char[strlen(dir)+1]; 
           strcpy(director,dir);
    }
    else
           cout << "¡¡¡ Asignacion incorrecta !!!" << endl;
}

void Video::setGenero(char *gen)
{
    if (strlen(gen)>=0 )
    {
           delete []genero;
           genero= new char[strlen(gen)+1]; 
           strcpy(genero,gen);
    }
    else
           cout << "¡¡¡ Asignacion incorrecta !!!" << endl;
}

void Video::setCantidad(short can)
{
    if (can>=0 )
    {
           cantidad= can;
    }
    else
           cout << "¡¡¡ Asignacion incorrecta !!!" << endl;
}

// operadores

int Video::operator== (const Video &v)const
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


void Video::Imprimir()const
{
    cout.setf(ios::left);
    cout.width(20);
    cout << getNombre() << flush;
    cout.width(20);
    cout << getDirector() << flush;
    cout.width(15);
    cout << getGenero()  << flush;
    cout.width(10);
    cout << getCantidad() << flush;
}
     
