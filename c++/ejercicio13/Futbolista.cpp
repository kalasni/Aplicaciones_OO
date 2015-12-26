#include <iostream>
#include <string>

#include "Futbolista.h"

using namespace std;

Futbolista::Futbolista()
{
    Inicializar();
}

void Futbolista::Inicializar()
{
    nombre= "";
    fecha.set(1,1,1900);
}

void Futbolista::setNombre(const string &s)
{
    nombre= s;
}

void Futbolista::setFecha(const Fecha &f)
{
    fecha= f;
}


void Futbolista::Leer()
{
    char linea[80];
    char car= 'n';
    do
    {
        cout << "Nombre: " << flush;
        cin >> linea;
        nombre= linea ;
        cout << "\nFecha de nacimiento" << endl;
        if (!fecha.Leer())
        {
            cout << "Desea continuar (s/n): ";
            cin >> car;
        }
    }
    while (toupper(car) == 'S');
}

void Futbolista::Mostrar()
{
    cout.setf(ios::left);
    cout.width(20);
    cout << nombre << fecha << endl;
}

bool Futbolista::operator<= (const Futbolista &f)
{
    if (fecha <= f.fecha)   return true;
    return false;
}

bool Futbolista::operator>= (const Futbolista &f)
{
    if (fecha >= f.fecha)   return true;
    return false;
}

bool Futbolista::operator< (const Futbolista &f)
{
    if (fecha < f.fecha)   return true;
    return false;
}

bool Futbolista::operator> (const Futbolista &f)
{
    if (fecha > f.fecha)   return true;
    return false;
}

bool Futbolista::operator== (const Futbolista &f)
{
    if (fecha == f.fecha)   return true;
    return false;
}

    
    
        
