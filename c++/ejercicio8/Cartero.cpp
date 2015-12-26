
#include "Cartero.h"

Cartero::Cartero()
{
    nombre= new char[1];
    strcpy(nombre, "");
    saco= new Cartas;
    tamanno= 0;
    numero= 0;
}

Cartero::Cartero(const char *nom, int n)
{
    if (n >0)
    {
        nombre= new char[strlen(nom)+1];
        strcpy(nombre, nom);
        tamanno= n;
        numero= 0;
        saco= new Cartas[tamanno];
   }
   else        //constructor por defecto
   {
        nombre= new char[1];
        strcpy(nombre, "");
        saco= new Cartas[1];
        tamanno= 0;
        numero= 0;  
   }
}

Cartero::~Cartero()
{
    delete []nombre;
    delete []saco;
}

Cartero::Cartero(const Cartero &c)
{
   nombre= new char[strlen(c.nombre)+1];
   strcpy(nombre,c.nombre);
   saco= new Cartas[c.tamanno];
   for (int i=0; i<c.numero; i++)
   {
      saco[i]= c.saco[i];
   }
   tamanno= c.tamanno;
   numero= c.numero;
   
}
        

bool Cartero::sacoLLeno()
{
    if (numero >= tamanno)
        return true;
    else
        return false;
}

bool Cartero::Iniciar(const char *nom, int n)
{
    if (n >0)
    {
        tamanno= n;
        numero= 0;
        delete []saco;
        saco= new Cartas[tamanno];
        delete []nombre;
        nombre= new char[strlen(nom)+1];
        strcpy(nombre, nom);
        return true;
    }
    else
        return false;
}

Cartas Cartero::getCarta(int posicion) const
{ 
       Cartas c;
       if (posicion < numero)
           return saco[posicion];
       else
           return c;       
}  

bool Cartero::insertarCarta(const Cartas &c)
{
    if (tamanno > 0 && !sacoLLeno())
    {
        saco[numero++]= c;
        return true;
    }
    return false;                
}

void Cartero::Imprimir()
{
    cout.setf(ios::left);
    cout << "\n";
    cout.width(20);
    cout << nombre;
    cout << "Cartas asignadas: " << numero << "\n" << endl;
    cout.width(13);
    cout << "NOMBRE";
    cout.width(25);
    cout << "DIRECCION" ;
    cout.width(23);
    cout << "CIUDAD" ;
    cout.width(11);
    cout << "ESTADO";
    cout.width(6);
    cout << "CODIGO" << "\n" << endl;
    for (int i= 0; i<numero; i++)
    {
        saco[i].Imprimir();
        cout << endl;
    }
}

int Cartero::LeerFichero(const char *nom, int codigo)
{
    int i= 0; // contador total
    int j= 0; // contador de las que pertenecen al codigo postal
    Cartas carta;
    while (j<tamanno && carta.LeerFichero(nom, i))
    {
        if (carta.getCodigo() == codigo)
        {
                if (!insertarCarta(carta))
                {
                      return j;
                }
                j++;
        }
        i++;
    }
    return j;
}

int Cartero::GuardarFichero(const char *nom)
{
    int i=0;
    while (i<numero && saco[i].GuardarFichero(nom))
    {
        i++;
    }        
    return i;
}

Cartero& Cartero::operator= (const Cartero &c)
{
    if (*this == c)
        return *this;
    else
    {
        delete []nombre;
        nombre= new char[strlen(c.nombre)+1];
        strcpy(nombre, c.nombre);
        delete []saco;
        saco= new Cartas[c.tamanno];
        for (int i=0; i<c.numero; i++)
        {
              saco[i]= c.saco[i];
        }
        tamanno= c.tamanno;
        numero= c.numero;
        return *this;
    }
}

bool Cartero::operator== (const Cartero &c)
{
    if (strcmp(nombre,c.nombre)) return false;
    if (numero!=c.numero) return false;
    if (tamanno!=c.tamanno) return false;
    for (int i=0; i<numero; i++)
    {
        if (saco[i]!=c.saco[i])
                return false;
    }
    return true;
}

bool Cartero::operator!= (const Cartero &c)
{
    if (!strcmp(nombre,c.nombre)) return false;
    if (numero==c.numero) return false;
    if (tamanno==c.tamanno) return false;
    for (int i=0; i<numero; i++)
    {
        if (saco[i]==c.saco[i])
                return false;
    }
    return true;
}


