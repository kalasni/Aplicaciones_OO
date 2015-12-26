
#include "Jugada.h"

#include <iostream>
#include <stdlib.h>

using namespace std;

Jugada::Jugada()
{
    valor= carta ;
    recibidas= 0;
}

void Jugada::ValorarJugada()
{
    Ordenar();
    if (Escalera() && Color())
    {
        valor= escalera_color;
        cartaAlta= mano[0];
        return;
    }
    
    if (Pocker())
    {
        valor= pocker;
        if (mano[0].getValor() == mano[1].getValor())
        {
                cartaAlta= mano[0];
                cartaBaja= mano[4];
                return;
        } 
        cartaAlta= mano[1];
        cartaBaja= mano[0];
        return; 
    }
    
    if (Full())
    {
        valor= full;
        if ( (mano[0].getValor() == mano[1].getValor()) && (mano[0].getValor() == mano[2].getValor()) )
        {
                cartaAlta= mano[0];
                cartaBaja= mano[4];
                return;
        } 
        if ( (mano[2].getValor() == mano[3].getValor()) && (mano[2].getValor() == mano[4].getValor()) )
        {
                cartaAlta= mano[2];
                cartaBaja= mano[0];
                return;
        } 
    }
    
    if (Color())
    {
        valor= color;
        cartaAlta= mano[0];
        cartaBaja= mano[4];
        return;
    }
    
    if (Escalera())
    {
        valor= escalera;
        cartaAlta= mano[0];
        cartaBaja= mano[4];
        return;
    }
    
    if (Trio())
    {
        valor= trio;
        if ( (mano[0].getValor() == mano[1].getValor()) && (mano[0].getValor() == mano[2].getValor()) )
        {
                cartaAlta= mano[0];
                cartaBaja= mano[3];
                return;
        } 
        if ( (mano[1].getValor() == mano[2].getValor()) && (mano[1].getValor() == mano[3].getValor()) )
        {
                cartaAlta= mano[1];
                cartaBaja= mano[0];
                return;
        } 
        if ( (mano[2].getValor() == mano[3].getValor()) && (mano[2].getValor() == mano[4].getValor()) )
        {
                cartaAlta= mano[2];
                cartaBaja= mano[0];
                return;
        } 
    }
    
    if (Doble())
    {
        valor= doble;
        if (mano[0].getValor() == mano[1].getValor()) 
        {
                cartaAlta= mano[0];
                cartaBaja= mano[3];
                cartaDoble= mano[4];
                return;
        } 
        if (mano[1].getValor() == mano[2].getValor()) 
        {
                cartaAlta= mano[1];
                cartaBaja= mano[3];
                cartaDoble= mano[0];
                return;
        } 
        
    }
    
    if (Pareja())
    {
        valor= pareja;        
        if  (mano[0].getValor() == mano[1].getValor())   
        {
                cartaAlta= mano[0];
                cartaBaja= mano[2];
                return;
        }   
        if  (mano[1].getValor() == mano[2].getValor())   
        {
                cartaAlta= mano[1];
                cartaBaja= mano[0];
                return;
        }         
    
        if  (mano[2].getValor() == mano[3].getValor())   
        {
                cartaAlta= mano[2];
                cartaBaja= mano[0];
                return;
        }     
        if  (mano[3].getValor() == mano[4].getValor())   
        {
                cartaAlta= mano[3];
                cartaBaja= mano[0];
                return;
        }
    }      
    valor= carta;        // si no tengo nada
    cartaAlta= mano[0];
    cartaBaja= mano[1];
    
}   

bool Jugada::Pocker()const
{
    if ( (mano[0].getValor() == mano[1].getValor()) && (mano[0].getValor() == mano[2].getValor())
        && (mano[0].getValor() == mano[3].getValor()) )
        return true; 
    if ( (mano[1].getValor() == mano[2].getValor()) && (mano[1].getValor() == mano[3].getValor())
        && (mano[1].getValor() == mano[4].getValor()) )
        return true; 
    return false;
}

bool Jugada::Trio()const
{
    if ( (mano[0].getValor() == mano[1].getValor()) && (mano[0].getValor() == mano[2].getValor()) )
        return true; 
    if ( (mano[1].getValor() == mano[2].getValor()) && (mano[1].getValor() == mano[3].getValor()) )
        return true; 
    if ( (mano[2].getValor() == mano[3].getValor()) && (mano[2].getValor() == mano[4].getValor()) )
        return true; 
    return false;
}

bool Jugada::Pareja()const
{
    int i= 0;
    while (i<4)
    {
        if (mano[i].getValor() == mano[i+1].getValor())
        {
           return true; 
        }
        i++;
    }
    return false;
}

bool Jugada::Full()const
{
    if ( (mano[0].getValor() == mano[1].getValor()) && (mano[0].getValor() == mano[2].getValor()) 
        && (mano[3].getValor() == mano[4].getValor()) )
        return true; 
    if ( (mano[2].getValor() == mano[3].getValor()) && (mano[2].getValor() == mano[4].getValor()) 
        && (mano[0].getValor() == mano[1].getValor()) )
        return true; 
    return false;
}

bool Jugada::Doble() const
{
    if ( (mano[0].getValor() == mano[1].getValor()) && (mano[2].getValor() == mano[3].getValor()) )
        return true; 
    if ( (mano[0].getValor() == mano[1].getValor()) && (mano[3].getValor() == mano[4].getValor()) )
        return true; 
    if ( (mano[1].getValor() == mano[2].getValor()) && (mano[3].getValor() == mano[4].getValor()) )
        return true; 
    return false;
}

bool Jugada::Escalera() const
{
    for (int i=0; i<4; i++)
    {
        if (mano[i].getValor() != (mano[i+1].getValor()-1) )
                return false;
    }
    return true;
}

bool Jugada::Color() const
{
    bool resultado= true;
    int i= 0;
    while (i<5)        // pruebo con rojas
    {
        if (mano[i].getPalo() != corazones &&  mano[i].getPalo() != diamantes)
             resultado= false;
        i++;
    }
    if (resultado) return true;
    
    resultado= true;    // pruebo con negras
    i= 0;
    while (i<5)
    {
        if (mano[i].getPalo() != picas &&  mano[i].getPalo() != treboles)
                resultado= false; 
        i++;
    }
    return resultado;
}

void Jugada::Ordenar() 
{
    int n= 4;
    int i= 0;
    bool intercambiado= true;
    while (intercambiado && n>0)
    {
        intercambiado= true;
        while (i<n)
        {
            if (mano[i].getValor() > mano[i+1].getValor())
            {
                 Carta aux= mano[i];
                 mano[i]= mano[i+1];
                 mano[i+1]= aux;
                 intercambiado= true;
            }
            i++;
        }
    i= 0;
    n--;
    }
}

bool Jugada::Completa()
{
    if (recibidas >= 5)
        return true;
    return false;
}

bool Jugada::anyadirCarta(const Carta &c)
{
    if (!Completa())
    {
        mano[recibidas++]= c;
        return true;
    }
    return false;
}
        

void Jugada::Imprimir()
{
    cout << "\t\t\t********** JUGADA *************\n" << endl;
    for (int i=0; i<5; i++)
    {
        mano[i].Imprimir();
    }
    cout << endl;
}

bool Jugada::operator==(const Jugada &j)
{
    for (int i=0; i<5; i++)
    {
        if (mano[i]!=j.mano[i])
                return false;
    }
    return true;
}

bool Jugada::operator>(const Jugada &j)
{
    
    if (valor>j.valor)
        return true;
    
    else if (valor == j.valor && valor == escalera_color) // en caso de dos escaleras color
    {
         if ( (cartaAlta.getPalo() == corazones || cartaAlta.getPalo() == diamantes) && 
             (j.cartaAlta.getPalo() != corazones || j.cartaAlta.getPalo() != diamantes) )
             return true;
         else if ( (cartaAlta.getPalo() != corazones || cartaAlta.getPalo() != diamantes) && 
             (j.cartaAlta.getPalo() != corazones || j.cartaAlta.getPalo() != diamantes) && cartaAlta > j.cartaAlta )
             return true;   
         else
             return false;
    }
    
    else if (valor == j.valor && valor == color) // en caso de dos jugadoas color
    {
        if ( (cartaAlta.getPalo() == corazones || cartaAlta.getPalo() == diamantes) && 
             (j.cartaAlta.getPalo() != corazones || j.cartaAlta.getPalo() != diamantes) )
             return true;
        else if ( (cartaAlta.getPalo() != corazones || cartaAlta.getPalo() != diamantes) && 
             (j.cartaAlta.getPalo() != corazones || j.cartaAlta.getPalo() != diamantes) && cartaAlta > j.cartaAlta )
             return true;
        else
             return false;
    }
    
    else if (valor == j.valor && valor == doble) // en caso de dos dobles parejas
    {
        if (cartaAlta.getValor() < j.cartaAlta.getValor() )
                return true;
        else if (cartaAlta.getValor() == j.cartaAlta.getValor() &&
                cartaBaja.getValor() < j.cartaBaja.getValor() ) 
                return true;
        else 
                return (cartaDoble > j.cartaDoble);
    }
    
    else if (valor == j.valor && valor == pareja) // en caso de dos parejas
    {
        if (cartaAlta.getValor() < j.cartaAlta.getValor() )
                return true;
        else 
                return (cartaBaja > j.cartaBaja);
    }
    
    else if (valor == j.valor)
        return cartaAlta > j.cartaAlta;
    else
        return false;
}

bool Jugada::operator<(const Jugada &j)
{
    
    if (valor<j.valor)
        return true;
    
    else if (valor == j.valor && valor == escalera_color) // en caso de dos escaleras color
    {
         if ( (cartaAlta.getPalo() != corazones || cartaAlta.getPalo() != diamantes) && 
             (j.cartaAlta.getPalo() == corazones || j.cartaAlta.getPalo() == diamantes) )
             return true;
         else if ( (cartaAlta.getPalo() == corazones || cartaAlta.getPalo() == diamantes) && 
             (j.cartaAlta.getPalo() == corazones || j.cartaAlta.getPalo() == diamantes) && cartaAlta < j.cartaAlta )
             return true;   
         else
             return false;
    }
    
    else if (valor == j.valor && valor == color) // en caso de dos jugadoas color
    {
        if ( (cartaAlta.getPalo() != corazones || cartaAlta.getPalo() != diamantes) && 
             (j.cartaAlta.getPalo() == corazones || j.cartaAlta.getPalo() == diamantes) )
             return true;
        else if ( (cartaAlta.getPalo() == corazones || cartaAlta.getPalo() == diamantes) && 
             (j.cartaAlta.getPalo() == corazones || j.cartaAlta.getPalo() == diamantes) && cartaAlta < j.cartaAlta )
             return true;
        else
             return false;
    }
    
    else if (valor == j.valor && valor == doble) // en caso de dos dobles parejas
    {
        if (cartaAlta.getValor() > j.cartaAlta.getValor() )
                return true;
        else if (cartaAlta.getValor() == j.cartaAlta.getValor() &&
                cartaBaja.getValor() > j.cartaBaja.getValor() ) 
                return true;
        else 
                return (cartaDoble < j.cartaDoble);
    }
    
    else if (valor == j.valor && valor == pareja) // en caso de dos parejas
    {
        if (cartaAlta.getValor() > j.cartaAlta.getValor() )
                return true;
        else 
                return (cartaBaja < j.cartaBaja);
    }
    
    else if (valor == j.valor)
        return cartaAlta < j.cartaAlta;
    else
        return false;
}       
        
    
    
    
                
        
                
        
