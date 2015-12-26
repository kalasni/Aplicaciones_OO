#include "EnteroAleatorio.h"
#include <iostream>

#include <time.h>

using namespace std;

EnteroAleatorio::EnteroAleatorio(int a, int b) 
{
    unsigned int semilla;
    semilla= int(time(NULL));
    setSemilla(semilla);
    setIntervalo(a,b);
}

EnteroAleatorio::EnteroAleatorio(int a, int b, unsigned int semilla)
{
    setIntervalo(a,b);
    setSemilla(semilla);
}

void EnteroAleatorio::setSemilla(unsigned int s)
{
    srand(s);
}

void EnteroAleatorio::setIntervalo(int a, int b) 
{
    if (a > b)
    {
        cout << "Intervalo erroneo: " << a << "   " << b << endl;
    }
    else
    {
        inferior= a;
        superior= b;
    }
}

int EnteroAleatorio::getInferior()  
{
    return inferior;  
}

int EnteroAleatorio::getSuperior()  
{
    return superior;  
}

int EnteroAleatorio::GenerarAleatorio()
{
    int tamanno= getSuperior() - getInferior() + 1;
    int despAleatorio= rand() % tamanno;
    int numero= getInferior() + despAleatorio;
    return numero;
}
    


