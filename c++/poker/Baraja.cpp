#include <iostream>
#include "Baraja.h"

using namespace std;

Baraja::Baraja()
{
    Inicializar();
}

void Baraja::Inicializar()
{
    int contador=0;
    TipoPalo p= picas;
    TipoValor v= as;
    Carta carta;
    
    for (int i=1; i<=4; i++)
    {
        p= TipoPalo(i);
        
        for (int j=1; j<=13; j++)
        {
            v= TipoValor(j);  
            
            carta.setPalo(p);
            carta.setValor(v);
            baraja[contador++]= carta; // inicializo la baraja
        }
    }
    
    for (int i=0; i<52; i++)
        repartidas[i]= false;          // inicializo repartidas  
}
    
bool Baraja::Vacia()
{
    for (int i= 0; i<52; i++)
    {
        if (!repartidas[i])
            return false;
    }
    return true;
}

void Baraja::Barajear()
{
    EnteroAleatorio numero(0, 51);
    Carta aux[52];
    bool asignadas[52];
    int posicion= 0;
    for (int i=0; i<52; i++)
    {
        aux[i]= baraja[i];              // inicializo aux
    }
    for (int i=0; i<52; i++)
        asignadas[i]= false;          // inicializo aisgnadas 
    
    int contador=0;
    while (contador<52)
    {
        posicion= numero.GenerarAleatorio();
        while (asignadas[posicion])     // encuentro una posicion sin asignar   
        {
                posicion = (posicion + 1) % 52;
        }
        baraja[contador++]= aux[posicion];
        asignadas[posicion]= true;
    }
}

Carta Baraja::Repartir()
{
    int posicion= 0;
    while (repartidas[posicion] && posicion<52)
    {
        posicion++;
    }
    if (posicion >=52)
    {
        cout << "No quedan cartas en la baraja" << endl;
        exit(1);
    }
    else
    {
        repartidas[posicion]= true;
        return baraja[posicion];
    }
}    

Carta Baraja::RepartirAleatorio()
{
    EnteroAleatorio numero(0, 51);
    int posicion= numero.GenerarAleatorio();
    while (repartidas[posicion] && posicion<52)
    {
        posicion = (posicion + 1) % 52;
    }
    if (posicion >=52)
    {   cout << "No quedan cartas en la baraja" << endl;
        exit(1);
    }
    else
    {
        repartidas[posicion]= true;
        return baraja[posicion];
    }
}    

void Baraja::Imprimir()
{
    int numero= 0;
    for (int i= 0; i<52; i++)
    {
        baraja[i].Imprimir();
        cout << endl;
        numero++;
    }
    cout << "\n\nNumero: " << numero << endl;
}


              
