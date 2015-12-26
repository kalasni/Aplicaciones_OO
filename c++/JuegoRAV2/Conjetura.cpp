#include <iostream>
#include <stdlib.h>
#include <string>

#include "Conjetura.h"

using namespace std;

Conjetura::Conjetura()
{
    numero.FijarX(0);
    numero.FijarY(0);
    numero.FijarZ(0);
}

int Conjetura::obtenerDigito(int i) const
{
    int valor;
    
    switch(i)
    {
        case 1: valor= numero.obtenerX(); break;
        case 2: valor= numero.obtenerY(); break;
        case 3: valor= numero.obtenerZ(); break;
        default:
                cerr << "Error= digito incorrecto:  " << i << endl;
                exit(1);
    }
    return valor;
}

void Conjetura::FijarDigito(int i, int v)
{
    switch(i)
    {
        case 1: numero.FijarX(v); break;
        case 2: numero.FijarY(v); break;
        case 3: numero.FijarZ(v); break;
        default:
                cerr << "Error= digito incorrecto:  " << i << endl;
                exit(1);
    }
}

bool Conjetura::Actualizar()
{
    int valor;
    if (cin >> valor)
    {
        if (valor >= 100 && valor <=999)
        {
                int centena= valor/100;
                int decena= (valor - (centena*100)) / 10;
                int unidad= valor % 10;
                FijarDigito(1, centena);
                FijarDigito(2, decena);
                FijarDigito(3, unidad);
        }
        else
                cerr << " Prueba ilegal (ignorada). " << endl;
        return true;
    }
    else
        return false;
}
