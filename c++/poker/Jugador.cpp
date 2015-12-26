#include "Jugador.h"
#include <string.h>
#include <iostream>

using namespace std;

Jugador::Jugador()
{
    nombre= new char[strlen("")+1];
    strcpy(nombre,"");
    dinero= 0;
    activo= true;
    apostado= 0;
    for (int i=0; i<5; i++)
    {
        descartes[i]= false;
    }
}

Jugador::Jugador(char *nomb, int d, const Jugada &j)
{
    nombre= new char[strlen(nomb)+1];
    strcpy(nombre,nomb);
    if (d>=0) 
        dinero= d;
    else
        dinero= 0;
    jugada= j;
    apostado= 0;
    activo= true;
    for (int i=0; i<5; i++)
    {
        descartes[i]= false;
    }
}

Jugador::Jugador(const Jugador &j)
{
    nombre= new char[strlen(j.nombre)+1];
    strcpy(nombre,j.nombre);   
    dinero= j.dinero;
    jugada= j.jugada;
    apostado= 0;
    activo= j.activo;
    for (int i=0; i<5; i++)
    {
        descartes[i]= j.descartes[i];
    }
}

Jugador::~Jugador()
{
    delete[]nombre;
}

void Jugador::Actualizar()
{
    jugada.ValorarJugada();
}

void Jugador::setNombre(char *nomb)
{
    if (strlen(nomb)>0)
    {
        delete[] nombre;
        nombre= new char[strlen(nomb)+1];
        strcpy(nombre,nomb);
    }
}

void Jugador::setDinero(int d)
{
    if (d>=0) 
        dinero= d;
    else
        dinero= 0;
}

void Jugador::setJugada(const Jugada &j)
{
    jugada= j;
    apostado= 0;
    activo= true;
    for (int i=0; i<5; i++)
    {
        descartes[i]= false;
    }
}

void Jugador::Descartar(int posicion)
{
    descartes[posicion]= true;
}

void Jugador::Imprimir()
{
    cout.setf(ios::left);
    cout << "NOMBRE: ";
    cout.width(20);
    cout << nombre;
    cout << "\nDINERO: ";
    cout.width(5);
    cout << dinero << "euros\n" << endl;
    jugada.Imprimir();
}

bool Jugador::operator==(const Jugador &j)
{
    if ( !strcmp(nombre,j.nombre) && dinero == j.dinero 
         && jugada == j.jugada && activo == j.activo)
         return true;
    else
         return false;
}

Jugador& Jugador::operator=(const Jugador &j)
{
    if (*this == j)
        return *this;
    else
    {
        delete[] nombre;
        nombre= new char[strlen(j.nombre)+1];
        strcpy(nombre, j.nombre);
        dinero= j.dinero;
        jugada= j.jugada;
        activo= j.activo;
        for (int i=0; i<5; i++)
        {
                descartes[i]= j.descartes[i];
        }
        return *this;
    }
}
     
