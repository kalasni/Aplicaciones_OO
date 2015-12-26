#include <iostream>
#include <stdlib.h>
#include <string>

#include "EnteroAleatorio.h"
#include "Control.h"

using namespace std;

Control::Control()
{
    EnteroAleatorio x(1,9);
    EnteroAleatorio y(0,9);
    EnteroAleatorio z(0,9);
    numeroSecreto.FijarX(x.GenerarAleatorio());
    numeroSecreto.FijarY(y.GenerarAleatorio());
    numeroSecreto.FijarZ(z.GenerarAleatorio());
}

void Control::Jugar(int intentos)
{
    int contador= 0;
    Bienvenida(intentos);
    Aviso();
    while (entrada.Actualizar() || contador<intentos)    // bucle entrada - respuesta
    {
        salida= Evaluar(entrada);
        Mostrar(entrada, salida);
        if (Ganador(salida))
        {
                Felicidades();
                return;
        }
        else
                Aviso();
    }
    Adios();
}

void Control::Bienvenida(int i) const
{
    cout << "\n\n\tJUEGO ROJO AMARILLO VERDE\n\n"
    << "El juego consiste en adivinar un numero entre 100 y 999 en "<< i << " intentos\n" << endl;
}

void Control::Aviso() const
{
    cout << "\n¿que numero es? ";
}

void Control::Felicidades() const
{
    cout << "\n\nENHORABUENA,  has acertado el numero\n" << endl;
    cout << "Numero secreto: "<< numeroSecreto.obtenerX()
    << numeroSecreto.obtenerY() << numeroSecreto.obtenerZ() << endl;
}

void Control::Adios() const
{
    cout << "\n\nMALA SUERTE\n\n"
    << "El numero era el " << numeroSecreto.obtenerX()
    << numeroSecreto.obtenerY() << numeroSecreto.obtenerZ() << endl;
}

bool Control::Ganador(const Respuesta &r) const
{
    return r.obtenerVerde() == 3;
}

void Control::Mostrar(const Conjetura &c, const Respuesta &r) const
{
    int rojos= r.obtenerRojo();
    int amarillos= r.obtenerAmarillo();
    int verdes= r.obtenerVerde();
    
    // imprimo la respuesta
    cout << "\n\nNUMERO: " << c.obtenerDigito(1) << c.obtenerDigito(2) << c.obtenerDigito(3)
     << "\tROJOS: " << rojos << "\tAMARILLOS: "<< amarillos 
     << "\tVERDES: " << verdes << endl;
}

int Control::obtenerVerde(const Conjetura &c) const
{
    int verdes= 0;    //numero de verdes
    
    if (c.obtenerDigito(1) == numeroSecreto.obtenerX())
        ++verdes;
    if (c.obtenerDigito(2) == numeroSecreto.obtenerY())
        ++verdes;
    if (c.obtenerDigito(3) == numeroSecreto.obtenerZ())
        ++verdes;
    return verdes;
}

int Control::obtenerRojo(const Conjetura &c) const
{
    int centena= numeroSecreto.obtenerX();
    int decena= numeroSecreto.obtenerY();
    int unidad= numeroSecreto.obtenerZ();
    
    int x= c.obtenerDigito(1);
    int y= c.obtenerDigito(2);
    int z= c.obtenerDigito(3);
    
    int rojos= 0;    //numero de rojos
    
    if ((centena!=x) && (centena!=y) && (centena!=z))
        ++rojos;
    if ((decena!=x) && (decena!=y) && (decena!=z))
        ++rojos;
    if ((unidad!=x) && (unidad!=y) && (unidad!=z))
        ++rojos;
    return rojos;
}

int Control::obtenerAmarillo(const Conjetura &c) const
{
    return (3 - obtenerVerde(c) - obtenerRojo(c));
}

Respuesta Control::Evaluar(const Conjetura &c) const
{
    return Respuesta(obtenerRojo(c), obtenerAmarillo(c), obtenerVerde(c));
}




    


