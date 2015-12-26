#include <iostream>
#include <stdlib.h>
#include "Video.h"

using namespace std;

int Menu();


int main(int argc, char *argv[])
{
  int x;
  cout << "\n\nNumero de videos: ";
  cin >> x;
  Video *coleccion= new Video[x]; 
  Video fin("nombre", "director", "genero", 4);
  Video otro(fin);
  otro.Imprimir();
  Video a1, a2;
  a1 = a2 = fin;
  cout << "\n imprimo c1\n\n";
  a1.Imprimir();
  cout << "\n imprimo c2\n\n";
  a2.Imprimir();
  cout << "\n imprimo fin\n\n";
  fin.Imprimir();
  system("PAUSE");
  int j=0;
  while(1)
  {
  system("cls");
  int opcion= Menu();
  switch(opcion)
  {
    case 1:
        
        cout << "\n\tIntroducir video" << endl;
        if (j<x)
        {
            cout << "\n\tVideo " << j+1 << endl;
            if (coleccion[j].Leer())
            {
               j++;
            }
            else
               cout << "No se ha podido leer\n" << endl; 
        }
        else
            cout << "\n\tNo se pueden insertar mas videos " << endl;    
        break;
        
    case 2:
    
        cout << "\n\t\tCOLECCION DE VIDEOS\n" << endl;
        for (int i=0; i<j; i++)
        {
            cout.setf(ios::left);
            cout.width(4);
            cout << i+1;
            coleccion[i].Imprimir();
            cout << endl;
        }
        break;
        
    case 3:
    
        for (int i=0; i<j; i++)
        {
            if (!coleccion[i].GuardarFichero("coleccion.dat"))
            {
                    cout << "Error al guardar";
            }
        }
        break;
        
    case 4:
    
        j=0; 
        while ((j<x) && coleccion[j].LeerFichero("coleccion.dat", j ))
        {
                j++;
        }
        if (j <= 0)
        {
                cout << "Error al leer";
        }
        else
                cout << "se han leido " << j << " videos" <<endl;
        break;
        
    case 5:
          exit(0);
  }
  system("PAUSE");
  }
  return 0;
}

int Menu()
{
    cout << "\n\n1\tIntroducir video\n"
    << "2\tMostrar videos\n"
    << "3\tGuardar en fichero\n"
    << "4\tLeer de fichero\n"
    << "5\tSalir\n" << endl;
    cout << "Introducir una opcion: ";
    int opcion;
    cin >> opcion;
    cin.ignore(35,'\n');
    if (opcion>0 && opcion<8)
        return opcion;
    else
        return 0;
}
