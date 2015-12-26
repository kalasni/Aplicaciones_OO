#include "Cartas.h"
#include <fstream>

bool Cartas::set(char *nom, char *dir, char *ciu, char *est, int cod)
{  
    if (cod == 109201 || cod == 109202 || cod == 109203 || cod == 109204 )
    {
        nombre= nom;                    
        direccion= dir;  
        ciudad= ciu; 
        estado= est; 
        codigo= cod; 
        return true;
    }
    else
        return false;
}

void Cartas::Imprimir()
{
    cout.setf(ios::left);
    cout.width(13);
    cout << nombre;
    cout.width(25);
    cout << direccion ;
    cout.width(23);
    cout << ciudad ;
    cout.width(11);
    cout << estado ;
    cout.width(6);
    cout << codigo ;
}
     
bool Cartas::Leer()
{
    char nom[80], direc[80], ciu[80], est[80];
    int cod;
    cin.ignore(256, '\n');
    cout << "Nombre: " << flush;
    cin.getline(nom, 80, '\n');
    cout << "Direccion: " << flush;
    cin.getline(direc, 80, '\n');
    cout << "Ciudad: " << flush;
    cin.getline(ciu, 80, '\n');
    cout << "Estado: " << flush; 
    cin.getline(est, 80, '\n');
    cout << "Codigo: " << flush; 
    cin >> cod ;
    return set(nom, direc, ciu, est, cod);
}

bool Cartas::GuardarFichero(const char *nom)
{
    fstream fichero;
    fichero.open(nom, ios::out | ios::app);
    if (!fichero)
    {
        cerr << "No se puede escribir el fichero" << endl;
        return false;
    }
    fichero << nombre << '*' << direccion << '*' << ciudad << '*' 
    << estado << '*' << codigo << endl;
    if (!fichero.fail())
    {
        fichero.close();
        return true;
    }
    return false;    
}

bool Cartas::LeerFichero(const char *fiche, int num)
{
    char nom[80], direc[80], ciu[80], est[80], buffer[80];
    int cod;
    fstream fichero;
    fichero.open(fiche, ios::in);
    if (!fichero)
    {
        cerr << "No se puede leer el fichero" << endl;
        return false;
    }
    for (int i= 0; i<num && !fichero.eof(); i++)
    {
        fichero.getline(buffer, 80, '\n');
        if (fichero.eof())
        {
            return false;
        }
    }
    if  (!fichero.eof() && !fichero.fail() && fichero.peek()!=EOF) 
    {
        fichero.getline(nom, 80, '*'); 
        fichero.getline(direc, 80, '*');
        fichero.getline(ciu, 80, '*');
        fichero.getline(est, 80, '*');
        fichero >> cod ;
        fichero.close();
        return set(nom, direc, ciu, est, cod);
    }
    return false;    
}

bool Cartas::operator==(const Cartas &c)
{
    if (nombre==c.nombre && direccion==c.direccion && estado==c.estado
        && ciudad==c.ciudad && codigo==c.codigo)
        return true;
    return false;
}

bool Cartas::operator!=(const Cartas &c)
{
    if (nombre==c.nombre && direccion==c.direccion && estado==c.estado
        && ciudad==c.ciudad && codigo==c.codigo)
        return false;
    return true;
}
