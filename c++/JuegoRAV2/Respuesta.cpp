
#include "Respuesta.h"

Respuesta::Respuesta(int r, int a, int v)
{
    FijarRojo(r);
    FijarAmarillo(a);
    FijarVerde(v);
}

int Respuesta::obtenerRojo() const
{
    return contadores.obtenerX();
}

int Respuesta::obtenerAmarillo() const
{
    return contadores.obtenerY();
}

int Respuesta::obtenerVerde() const
{
    return contadores.obtenerZ();
}

void Respuesta::FijarRojo(int r)
{
     contadores.FijarX(r);
}

void Respuesta::FijarAmarillo(int a)
{
     contadores.FijarY(a);
}

void Respuesta::FijarVerde(int v)
{
    contadores.FijarZ(v);
}
