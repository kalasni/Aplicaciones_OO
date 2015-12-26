
#include "Carta.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

Carta::Carta(TipoValor v, TipoPalo p)
{
    setPalo(p);
    setValor(v);
}

void Carta::setPalo(TipoPalo p)
{
    palo= p;
}

void Carta::setValor(TipoValor v)
{
    valor= v;
}

void Carta::Imprimir()
{
    cout.setf(ios::right);
    cout.width(5);
    switch(valor)
    {
        case 1: cout << "AS"; break;
        case 2: cout << "REY"; break;
        case 3: cout << "REINA"; break;
        case 4: cout << "JACK"; break;
        case 5: cout << 10; break;
        case 6: cout << 9; break;
        case 7: cout << 8; break;
        case 8: cout << 7; break;
        case 9: cout << 6; break;
        case 10: cout << 5; break;
        case 11: cout << 4; break;
        case 12: cout << 3; break;
        case 13: cout << 2; break;
        default: cout << "ERROR Carta ilegal"; 
    }
    cout.setf(ios::left, ios::adjustfield);
    cout.width(11);    
    switch(palo)
    {
        case 1: cout << " CORAZONES" ;
                break;
        case 2: cout << " DIAMANTES" ;
                break;
        case 3: cout << " PICAS" ;
                break;
        case 4: cout << " TREBOLES" ;
                break;
        default: cout << "ERROR Carta ilegal";
    }
}

bool Carta::operator==(const Carta &c)
{
    if (palo == c.palo && valor == c.valor)
        return true; 
    else
    return false;
}

bool Carta::operator!=(const Carta &c)
{
    if (palo == c.palo && valor == c.valor)
        return false; 
    else
    return true;
}

bool Carta::operator<(const Carta &c)
{
    if (valor > c.valor)    // estan ordenados de menor a mayor desde el as, rey, reina ...
        return true;
    else if (valor == c.valor && palo > c.palo)
        return true;
    return false;
}

bool Carta::operator>(const Carta &c)
{
    if (valor < c.valor)    // estan ordenados de menor a mayor desde el as, rey, reina ...
        return true;
    else if (valor == c.valor && palo < c.palo) 
        return true;
    return false;
}

bool Carta::operator<=(const Carta &c)
{
    if (valor > c.valor)    // estan ordenados de menor a mayor desde el as, rey, reina ...
        return true;
    else if (valor == c.valor && palo > c.palo)
        return true;
    else if (palo == c.palo && valor == c.valor)
        return true; 
    return false;
}

bool Carta::operator>=(const Carta &c)
{
    if (valor < c.valor)    // estan ordenados de menor a mayor desde el as, rey, reina ...
        return true;
    else if (valor == c.valor && palo < c.palo)
        return true;
    else if (palo == c.palo && valor == c.valor)
        return true; 
    return false;
}
    
