#include <iostream>
#include <stdlib.h>

#include "Calculadora.h"

using namespace std;

int Menu();

int main()
{
  Calculadora cc;
   
  while(cc.getEstado())
  {
    int opcion= Menu();
    switch(opcion)
    {
        case 1: 
                cout << "\nIntroduce un operando: ";
                cc.setRacional();
                break;
        case 2: 
                cout << "\nIntroduce un operador: ";
                cc.setOperador();
                break;
    }
    cout << "\n\n" << endl;
    system("PAUSE");
  }             
  return 0;
}

int Menu()
{
    int opcion;
    do
    {
    system("cls");
    cout << "\t\tCALCULADORA DE NUMEROS RACIONALES\n" << endl;
    cout << "1\tIntroducir un numero racional (3/5)\n2\tIntroducir un operador (+, -, *, /, =, AC, ON, OFF)\n" << endl;
    cout << "Elige uma opcion: " ;
    cin >> opcion;
    cin.ignore(43,'\n');
    }
    while (opcion <0 || opcion>2);
    return opcion;
}

    
