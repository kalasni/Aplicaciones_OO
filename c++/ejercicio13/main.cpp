#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include "Fecha.h"
#include "Futbolista.h"

#define MAX 5

using namespace std;

int tamanno;

int Menu();
void GuardarFichero(Futbolista f[]);
void CargarFichero(Futbolista f[]);
void Intercambiar(Futbolista &a, Futbolista &b);
void Ordenar(Futbolista f[]);

int main(int numero, char *argv[])
{
    int num=0, h=0;
    if (numero == 2)
    {
        tamanno= atoi(argv[1]);
    }
    else
    {
        tamanno = MAX;
        cout << "\n\n\tNumero de jugadores por defecto " << MAX << "\n" << endl;
        system("pause");
    }
    
    Futbolista *equipo= new Futbolista[tamanno];
    Futbolista *aux;
    system("pause");
    while (1)
    {
        system("cls");
        int opcion= Menu();
        switch(opcion)
        {
                case 1:
                
                    system("cls");
                    cout << "\tIntroducir los jugadores\n\n" << endl;
                    for (int i=0; i<tamanno; i++)
                    {
                           equipo[i].Leer();
                           cout << endl;
                    }
                    break;
                
                case 2:
                    
                    system("cls");
                    cout << "\t Relacion de jugadores \n\n" << endl;
                    cout.setf(ios::left);
                    cout.width(20);
                    cout << "NOMBRE" << "FECHA" << endl;
                    for (int i=0; i<tamanno; i++)
                    {
                         equipo[i].Mostrar();
                    }
                    break;
                    
                case 3:
                
                    system("cls");
                    cout << "\n\nNumero de jugadores: ";
                    cin >> num;
                    aux= new Futbolista[num];
                    for (h=0; h<tamanno && h<num; h++)  // copia los primeros num futbolistas
                    {
                         aux[h]= equipo[h];
                    }
                    tamanno= num;
                    delete []equipo;
                    equipo= new Futbolista[tamanno];
                    for (h=0; h<tamanno; h++)
                    {
                        equipo[h]= aux[h];
                    }
                    break;
                
                case 4:
                                        
                    GuardarFichero(equipo);
                    break;
                    
                 case 5:
                 
                    CargarFichero(equipo);
                    break;
                    
                case 6:
                
                    Ordenar(equipo);
                    break;
                    
                case 7:
                
                    exit(0);
        }
    system("pause");
    }
    return 0;
}

int Menu()
{
    cout << "\n\n1\tLeer Futbolistas\n"
    << "2\tMostrar Futbolistas\n"
    << "3\tEstablecer numero de jugadores\n"
    << "4\tGuardar en fichero\n"
    << "5\tCargar en fichero\n"
    << "6\tOrdenar futbolistas\n"
    << "7\tSalir\n" << endl;
    cout << "Introducir una opcion: ";
    int opcion;
    cin >> opcion;
    if (opcion>0 && opcion<8)
        return opcion;
    else
        return 0;
}

void GuardarFichero(Futbolista f[])
{   
    ofstream fout("futbolistas.dat");
    for (int i=0; i<tamanno && !fout.fail(); i++)
    {
        fout << f[i].getNombre() << endl;
        fout << f[i].getFecha() << endl;
    }
    fout.close();
}

void CargarFichero(Futbolista f[])
{   
    ifstream fin("futbolistas.dat");
    string cadena;
    Fecha fecha;
    for (int i=0; i<tamanno && !fin.eof(); i++)
    {
        fin.getline(cadena,80,'\n');
        fin << cadena << endl;
        fin << fecha << endl;
        f[i].setNombre(cadena);
        f[i].setFecha(fecha);
    }
    fin.close();
}

void Intercambiar(Futbolista &a, Futbolista &b)
{
    Futbolista aux=a;
    a= b;
    b= aux;
}

void Ordenar(Futbolista f[])
{
    int intercambio =1;        // incializo las variables de control
    int n= tamanno-1;
    int i= 0;
    
    while(intercambio && n>1)
    {
        intercambio= 0;        // inicializo intercambio en cada pasada
        
        while (i<n)        // recorro todos los empleados no ordenados
        {
                if ( f[i] > f[i+1])
                {
                   Intercambiar(f[i], f[i+1]);
                   intercambio= 1;
                }
                i++;
        }
        i= 0;
        n--;
    }
}*/
