#include <iostream>
#include <string>
#include "Racional.h"

using namespace std;

// Implementacion de los constructores
Racional::Racional()    // constructor por defecto
{
    setNumerador(0);
    setDenominador(1);
}

Racional::Racional(int num, int deno)
{
    setNumerador(num);
    setDenominador(deno);
} 

// Implementacion de los inspectores
int Racional::getNumerador() const
{
    return numerador;
}

int Racional::getDenominador() const
{
    return denominador;
}

// Implementacion de los modificadores
void Racional::setNumerador(int num) 
{
    numerador= num;
}

void Racional::setDenominador(int deno) 
{
    if (deno!= 0)
    {
        denominador= deno;
    }
    else
    {
        cerr << "Denominador ilegal (se pone a 1 por defecto)" << endl;
    }
}

// Implementacion de las funciones aritmeticas
Racional Racional::Sumar(const Racional& r) const
{
    int a= getNumerador();
    int b= getDenominador();
    int c= r.getNumerador();
    int d= r.getDenominador(); 
    return Racional(a*d + b*c, b*d);
}

Racional Racional::Restar(const Racional& r) const
{
    int a= getNumerador();
    int b= getDenominador();
    int c= r.getNumerador();
    int d= r.getDenominador(); 
    return Racional(a*d - b*c, b*d);
}

Racional Racional::Multiplicar(const Racional& r) const
{
    int a= getNumerador();
    int b= getDenominador();
    int c= r.getNumerador();
    int d= r.getDenominador(); 
    return Racional(a*c, b*d);
}

Racional Racional::Dividir(const Racional& r) const
{
    int a= getNumerador();
    int b= getDenominador();
    int c= r.getNumerador();
    int d= r.getDenominador(); 
    return Racional(a*d, b*c);
}

// Implementacion de las funciones de stream
void Racional::Insertar(ostream &salida) const
{
    salida << getNumerador() << '/' << getDenominador();
    return;
}

void Racional::Extraer(istream &entrada)
{
    int num, deno;
    char aux;
    entrada >> num >> aux >> deno;
    setNumerador(num);
    setDenominador(deno);
    return;
}

void Racional::Simplificar()
{
    int cociente=2;
    while (cociente<=numerador || cociente<=denominador)
    {
        if ((numerador%cociente==0) && (denominador%cociente==0))
        {
                numerador= numerador/cociente;
                denominador= denominador/cociente;
        }
        else
        {
                cociente++;
                cociente= GenerarPrimo(cociente);
        }
    }
}    
    

int GenerarPrimo(int posicion)
{
    bool primo= true;
    int numero= posicion;
    do
    {
        for (int i= 2; i<numero; i++)
        {
           if (numero%i == 0)
           {
               primo= false;
           }
        }
        if (primo)   // el número es primo
        {
           return numero;
        }
        else         // pruebo con el siguiente número
        {
           numero++;
           primo= true;
        }
    }
    while(1); /* la condición de terminación se debe a que 
                la cantidad de números primos es infinita */
}

bool Racional::operator== (const Racional &v)const
{
    if ( getNumerador()==v.getNumerador() && getDenominador()==v.getDenominador())
         return true;
    else
         return 0;
}


Racional& Racional::operator= (const Racional &r)
{
    if (*this == r)
        return *this;
    else
    {
        setNumerador(r.getNumerador());
        setDenominador(r.getDenominador());
        return *this;
    }
}

Racional& Racional::operator= (const int &num)
{
        setNumerador(num);
        setDenominador(1);
        return *this;
}



Racional operator+ (const Racional &r, const Racional &s)
{
    int a= r.getNumerador();
    int b= r.getDenominador();
    int c= s.getNumerador();
    int d= s.getDenominador(); 
    return Racional(a*d + b*c, b*d);  
} 

Racional operator- (const Racional &r, const Racional &s)
{
    int a= r.getNumerador();
    int b= r.getDenominador();
    int c= s.getNumerador();
    int d= s.getDenominador(); 
    return Racional(a*d - b*c, b*d);  
}            
  
Racional operator* (const Racional &r, const Racional &s)
{
    int a= r.getNumerador();
    int b= r.getDenominador();
    int c= s.getNumerador();
    int d= s.getDenominador(); 
    return Racional(a*c, b*d);  
}                    

Racional operator/ (const Racional &r, const Racional &s)
{
    int a= r.getNumerador();
    int b= r.getDenominador();
    int c= s.getNumerador();
    int d= s.getDenominador(); 
    return Racional(a*d, b*c);  
}    

ostream& operator<< (ostream &salida, const Racional &r)
{
    salida << r.getNumerador() << '/' << r.getDenominador();
    return salida;
}

istream& operator>> (istream &entrada, Racional &r)
{
    int num, deno;
    char aux;    // para leer '/'
    entrada >> num >> aux >> deno;
    r.setNumerador(num);
    r.setDenominador(deno);
    return entrada;
}
    


    
