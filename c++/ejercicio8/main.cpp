#include <iostream>
#include <stdlib.h>
#include "Cartas.h"
#include "Cartero.h"

using namespace std;

int CalcularCartas(int codigo, const char *);
int AsignarCartero( char *nombre, int codigo, const char *fichero);
void LeerCartero(char *nombre, int codigo);
int Menu();

int main(int argc, char *argv[])
{
  char nombre[80];
  int codigoPostal;
  int opcion, cantidad;
  while(1)
  {
    system("cls");
    opcion= Menu();
    switch(opcion)
    {
        case 1:
                cout << "Codigo postal: ";
                cin >> codigoPostal;
                cout << "Nombre del cartero: ";
                cin >> nombre;
                cantidad=AsignarCartero( nombre, codigoPostal, "cartas.dat");
                if (cantidad > 0)
                {
                    cout << "Asignadas " << cantidad << " cartas" << endl;
                }
                else
                    cout << "No se ha podido asignar ninguna carta" << endl;
                break;
                
         case 2:
                cout << "Codigo postal: ";
                cin >> codigoPostal;
                cout << "Nombre del cartero: ";
                cin >> nombre;
                LeerCartero(nombre, codigoPostal);
                break;
                
         case 3:
                  exit(0);
    }
  system("PAUSE");	
  }
  return 0;
}

int CalcularCartas(int codigo, const char *fi)
{
    Cartas carta;
    int numero= 0, i= 0;
    while (carta.LeerFichero(fi, i))
    {  
       if(carta.getCodigo() == codigo)
       {
         numero++;
       }
       i++;
    }
    return numero;
}

int AsignarCartero( char *nombre, int codigo, const char *fichero)
{
    char buffer[80];
    int numero= CalcularCartas(codigo, fichero);
    Cartero *cartero= new Cartero(nombre, numero);
    int i= cartero->LeerFichero(fichero,codigo);
    if (i>0)
    {
        strcpy(buffer,cartero->getNombre());
        strcat(buffer,".dat");
        i= cartero->GuardarFichero(buffer);
        return i;
    }
    return 0;
}

void LeerCartero(char *nombre, int codigo)
{
    char buffer[80];
    strcpy(buffer,nombre);
    strcat(buffer,".dat");
    int numero= CalcularCartas(codigo, buffer);
    Cartero *cartero= new Cartero(nombre, numero);
    int i= cartero->LeerFichero(buffer,codigo);
    if (i > 0)
        cartero->Imprimir();
    else
        cout << "no se ha podido leer" << endl;
}

int Menu()
{
    int op;
    cout << "\n\n\t\tMENU\n\n"
    << "1\tAsignar cartas segun cod postal\n"
    << "2\tMostrar cartas segun cod postal\n" 
    << "3\tSalir\n"<< endl;
    cout << "Introduce opcion: ";
    cin >> op;
    cin.ignore(40,'\n');
    if (op>0 && op<4)
        return op;
    else
        return 0;
}
    
    
    

