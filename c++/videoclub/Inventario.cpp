#include "Inventario.h"
#include <iostream> 
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

Inventario::Inventario()
{
    InicializarInventario();
}

Inventario::Inventario(const Inventario& inv)
{
    for (int i=0; i<MAX; i++)
    {
        almacen[i]= inv.almacen[i];
        alquilados[i]= inv.alquilados[i];
    }
    totalVideos= inv.totalVideos;
    totalAlquilados= inv.totalAlquilados;
}

void Inventario::InicializarInventario()
{
    InicializarAlmacen();
    InicializarAlquilados();
    InicializarTotalVideos();
    InicializarTotalAlquilados();
}

void Inventario::InicializarAlmacen()
{
    for (int i=0; i<MAX; i++)
    {
        almacen[i].set("","","",0);
    }
}

void Inventario::InicializarAlquilados()
{
    for (int i=0; i<MAX; i++)
    {
        alquilados[i].set("","","",0);
    }
}

void Inventario::InicializarTotalVideos()
{
    totalVideos= 0;
}

void Inventario::InicializarTotalAlquilados()
{
    totalAlquilados= 0;
}

void Inventario::insertarVideo(const Video &v)
{
    int posicion= BuscarVideo(v);
    if ( posicion>0 && posicion<MAX)
    {
        almacen[posicion-1]++;
    }
    else if (!posicion && getNumVideos()<=MAX)
    {
        almacen[totalVideos]= v;
        totalVideos++;
    }
    else
        cout << "No se ha podido insertar";
}

int Inventario::borrarVideo(int i)
{
    if ( i>0 && i<MAX && almacen[i-1].getCantidad()>0)
    {
        almacen[i-1]--;
        return 1;    
    }
    return 0;
}

int Inventario::BuscarVideo(const char*nombre, int posicion)const
{
    for (int i=posicion; i<MAX; i++)
    {
        if (strcmp(almacen[i].getNombre(), nombre) == 0)
                return i+1;
    }
    return 0;
}

int Inventario::BuscarVideo(const Video &v, int posicion)const
{
    for (int i=posicion; i<MAX; i++)
    {
        if (v == almacen[i])
                return i+1;
    }
    return 0;
}

int Inventario::Disponible(int posicion)const
{
    if (almacen[posicion-1].getCantidad() > alquilados[posicion-1].getCantidad())
        return 1;
    else
        return 0;
}

int Inventario::Alquilar(const Video &v)
{    
    int posicion= BuscarVideo(v);
    
    if (posicion>0 && Disponible(posicion))
    {
        alquilados[posicion-1]++;
        return 1;
    }
    return 0;
}

int Inventario::Devolver(const Video &v)
{    
    int posicion= BuscarVideo(v);
    
    if (posicion>0 && (alquilados[posicion-1].getCantidad()>0))
    {
        alquilados[posicion-1]--;
        return 1;
    }
    return 0;
}

void Inventario::Imprimir() const
{
     
    cout.setf(ios::left);
    
    cout << setw(20) << "NOMBRE" <<  setw(20) 
    << "DIRECTOR" <<  setw(15)
    << "GENERO" <<  setw(10)
    << "CANTIDAD" << setw(10)
    << "DISPONIBLE" <<"\n"<< endl;
    for (int i=0; i<MAX; i++)
    {
        almacen[i].Imprimir();
        if (Disponible(i+1))
                cout << setw(10) << "SI" << endl;
        else
                cout << setw(10) << "NO" << endl;
    }
}
            
