#include <iostream>
#include <string>
#include "Fecha.h"

using namespace std;

Fecha::Fecha()
{
    set(1,1,1900);
}

Fecha::Fecha(int dd, char  *m, int aa)
{
    string mmes= m;
    int mm= ConvertirMes(mmes);
    
    if (Comprobar(dd,mm,aa))
    {
        set(dd,mm,aa);
    }
    else
    {
        set(1,1,1900);
        cout << "Fecha incorrecta (por defecto 01/01/1900)" << endl;
    }
}

Fecha::Fecha(int dd, int  mm, int aa)
{
    if (Comprobar(dd,mm,aa))
    {
        set(dd,mm,aa);
    }
    else
    {
        set(1,1,1900);
        cout << "Fecha incorrecta (por defecto 01/01/1900)" << endl;
    }
}

bool Fecha::Comprobar(int dd, int mm, int aa)
{
    if (aa <=0) 
        return false;
    if (mm <= 0 || mm>12) 
        return false;
    if ( ((mm==1) || (mm==3) || (mm==5) || (mm==7) || (mm==8) || (mm==10) ||
         (mm==12)) && ((dd<1) || (dd>31)) )
        return false;
    if ( ((mm==4) || (mm==6) || (mm==9) || (mm==11)) && ((dd<1) || (dd>30)) )
        return false; 
    if ( (mm==2)&&(mm%4)&& ((dd<1) || (dd>29)) )
        return false;
    if ( (mm==2) && ((dd<1) || (dd>28)) )
        return false;
    return true;
}

int Fecha::ConvertirMes(string m)
{
    string mesesTex[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio",
                       "agosto", "septiembre", "octubre", "noviembre ", "diciembre"};

    for (int i=0; i<12; i++)
    {
        if (mesesTex[i] == m)
            return i+1;
    }
    return 0;
}  

string Fecha::getMesNombre() const
{ 
    string mesesTex[12]= {"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio",
                       "agosto", "septiembre", "octubre", "noviembre ", "diciembre"};

    return mesesTex[mes-1]; 
}

void Fecha::set(int dd, char *m, int aa)
{
    string mmes= m;
    int mm= ConvertirMes(mmes);
    
    if (Comprobar(dd,mm,aa))
    {
        dia= dd;
        mes= mm;
        anno= aa;
    }
    else
    {
        cout << "Fecha incorrecta " << endl;
    }
}

void Fecha::set(int dd, int mm, int aa)
{
    if (Comprobar(dd,mm,aa))
    {
        dia= dd;
        mes= mm;
        anno= aa;
    }
    else
    {
        cout << "Fecha incorrecta " << endl;
    }
}

void Fecha::setAnno(int aa)
{
    if (Comprobar(getDia(), getMes(), aa))
        anno= aa;
    else
        cout << "Anno incorrecto" << endl;
}

void Fecha::setMes(char *m)
{
    string mmes= m;
    int mm= ConvertirMes(mmes);
    
    if (Comprobar(getDia(), mm, getAnno()))
        mes= mm;
    else
        cout << "Mes incorrecto" << endl;
}

void Fecha::setMes(int mm)
{
    if (Comprobar(getDia(), mm, getAnno()))
        mes= mm;
    else
        cout << "Mes incorrecto" << endl;
}

void Fecha::setDia(int dd)
{
    if (Comprobar(dd, getMes(), getAnno()))
        dia= dd;
    else
        cout << "Dia incorrecto" << endl;
}

bool Fecha::Leer()
{
    int dd,mm,aa;
    string  mmes;
    cout << "Dia: ";
    cin >> dd;
    cout << "mes: ";
    cin >> mmes;
    cout << "Anno: ";
    cin >> aa;
    
    mm= ConvertirMes(mmes);
    
    if (Comprobar(dd,mm,aa))
    {
        set(dd,mm,aa);
        return true;
    }
    else
    {
        cout << "Fecha incorrecta " << endl;
        return false;
    }
    
}

void Fecha::Mostrar()
{
    cout << getDia() << ' ' << getMesNombre() << ' ' << getAnno() << flush;
}
        
       //operadores sobrecargados de la clase
bool Fecha::operator<= (const Fecha &f)
{
    if (getAnno() > f.getAnno())
        return true;
    if(getAnno() == f.getAnno() && getMes() > f.getMes())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() > getDia())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() == getDia())
        return true;
    return false;
}

bool Fecha::operator>= (const Fecha &f)
{
    if (getAnno() < f.getAnno())
        return true;
    if(getAnno() == f.getAnno() && getMes() < f.getMes())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() < getDia())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() == getDia())
        return true;
    return false;
}

bool Fecha::operator< (const Fecha &f)
{
    if (getAnno() > f.getAnno())
        return true;
    if(getAnno() == f.getAnno() && getMes() > f.getMes())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() > getDia())
        return true;
    return false;
}

bool Fecha::operator> (const Fecha &f)
{
    if (getAnno() < f.getAnno())
        return true;
    if(getAnno() == f.getAnno() && getMes() < f.getMes())
        return true;
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() < getDia())
        return true;
    return false;
}

bool Fecha::operator== (const Fecha &f)
{
    if (getAnno() == f.getAnno() && getMes() == f.getMes() && getDia() == getDia())
        return true;
    return false;
}

ostream& operator<< (ostream &salida, const Fecha &f)
{
    salida << f.getDia() << ' ' << f.getMesNombre() << ' ' << f.getAnno();
    return salida;
}

istream& operator>> (istream &entrada, Fecha &f)
{
    int dd, mm, aa;
    char aux;    // para leer '/'
    entrada >> dd >> aux >> mm >> aux >> aa;
    if (f.Comprobar(dd,mm,aa))
        f.set(dd,mm,aa);
    else
        cout << "Fecha incorrecta";
    return entrada;
}
                       
       
