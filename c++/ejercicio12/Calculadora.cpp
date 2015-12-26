
#include "Calculadora.h"
#include <iostream>
#include <string>
    
using namespace std;

Calculadora::Calculadora()
{
    Encender();
}

int Calculadora::Buscar(const string &s)
{
    string operadores[MAX_OPERADORES]= {"AC", "+", "-", "*", "/", "=",  "ON", "OFF"};
    
    for (int i=0 ; i< MAX_OPERADORES; i++)
    {
        if (s == operadores[i])
          return i;
    }
    return -1;
}

void Calculadora::setRacional()
{
    if (!getEstado())
    {
        cout << "Calculadora apagada" << endl;
        return;
    }
    
    Racional operando= 1, prueba=1;
    cin >> operando;
    if ((operando==prueba))
    {
        cout << "Operando incorrecto" << endl;
        return;
    }
    switch (operador)
    {
        case 1:
                resultado= resultado + operando;
                resultado.Simplificar();
                break;
        case 2:
                resultado= resultado - operando;
                resultado.Simplificar();
                break;
        case 3:
                resultado= resultado * operando;
                resultado.Simplificar();
                break;
        case 4:
                resultado= resultado / operando;
                resultado.Simplificar();
                break;
        default:
                resultado= operando;
                operador= 0; // para no guardar el operador entre numeros
                resultado.Simplificar();
                break;
    }
}

void Calculadora::setOperador()
{
    if (!getEstado())
    {
        cout << "Calculadora apagada" << endl;
        return;
    }
    
    string op;
    cin >> op;
    if (op.empty()) // compruebo que se ha leido un string               
    {
        cout << "Operador incorrecto" << endl;
        return;
    }
    
    int aux= Buscar(op);
    if (aux == -1)    // compruebo es un operador correcto
    {
        cout << "Operador incorrecto" << endl;
        return;
    }
    
    operador= aux;    // asigno a la variable miembro aux  
    switch (operador)
    {
        case 5:
                cout << "\n\nRESULTADO =  " << resultado;
                break;
        case 6:
                Encender();
                break;
        case 7:
                Apagar();
                break;
        case 0:
                resultado= 1;
                break;
    }
}
    
                     


