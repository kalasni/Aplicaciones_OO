#include <iostream>
#include <stdlib.h>
#include "Pocker.h"

using namespace std;

Pocker::Pocker()
{
    jugadores= new Jugador[1];
    numero= 1;
    apuesta= 3;
    acumulado= 0;
    pendientes= 0;
}

Pocker::Pocker(const Pocker &p)
{
    jugadores= new Jugador[p.numero];
    for (int i=0; i<p.numero; i++)
    {
        jugadores[i]= p.jugadores[i];
    }
    numero= p.numero;
    apuesta= p.apuesta;
    acumulado= p.acumulado;
}

Pocker::~Pocker()
{
    delete []jugadores;
}

int Pocker::CalcularActivos()
{
    int contador= 0;
    for (int i=0; i<numero; i++)
    {
        if (jugadores[i].getActivo())
           contador++;
    }
    return contador;
}

void Pocker::Bienvenida()
{
    do
    {
        system("cls");
        cout << "\n\n\t\t\tJUEGO DE POCKER" << "\n\t\t\t***************\n\n" << endl;
        cout << "*************** SE ABRE CON 3 EUROS. APUESTA MAXIMA " << MAXIMO << " EUROS **************\n\n" << endl;
        cout << "Numero de jugadores (entre 2 y 8): ";
        cin >> numero;
        cin.ignore(40,'\n');
        cout <<"\n\n";
    }
    while (numero <2 || numero >8);
}

void Pocker::Enhorabuena(int i)
{
    system("cls");
    cout << "\n\n\t\t\tENHORABUENA " << jugadores[i].getNombre() << "\n\n" << endl;
    jugadores[i].Imprimir();
    cout << "\n\nHas ganado " << acumulado << " euros\n" << endl;
}

void Pocker::AnyadirJugador(int i)
{
    char nombre[80];
    int dinero;
    cout << "Nombre del jugador:  ";
    cin >> nombre;
    cout << "Dinero del jugador : ";
    cin >> dinero;
    cin.ignore(40,'\n');
    jugadores[i].setNombre(nombre);
    jugadores[i].setDinero(dinero);
}

int Pocker::SortearMano()
{
     EnteroAleatorio num(0, numero-1);
     return num.GenerarAleatorio();
}

bool Pocker::RepartirCartas(int num, Jugada &jug)
{
    for (int i=0; i<num; i++) // para cada carta
    {
        Carta c= baraja.Repartir();
        if (!jug.anyadirCarta(c))
        {
                return false;
        }
    }
    return true;
}

bool Pocker::RepartoInicial()
{
    for (int i=0; i<numero; i++)   // para cada jugador
    {
        Jugada jugNueva;
        if (!RepartirCartas(5, jugNueva))
                return false;
        jugadores[i].setJugada(jugNueva);
    }
    return true;
}

int Pocker::Descartadas(int i)
{
    int resultado= 0;
    for (int j=0; j<5; j++)
    {
        if (jugadores[i].getDescarte(j))
                resultado++;
    }
    return resultado;
}


bool Pocker::HacerDescartes(int elegido)
{
    
    
    
    char car, car2;
    int posicion;
    
    Jugada jugAntigua= jugadores[elegido].getJugada();
    Carta carta;
    
    do
    {
        system("cls");
        jugadores[elegido].Imprimir();
        car= 'n';
        cout << "\n\nQuieres descartas alguna (s/n): ";
        cin >> car;
        cin.ignore(40,'\n');
        if (toupper(car) == 'S')
        {
                cout << "\n\nPosicion de la carta: ";
                cin >> posicion;
                carta= jugAntigua.getCarta(posicion-1);
                cout << "\n\nDescarte: ";
                carta.Imprimir();
                cout << "\n\nEs correcto(s/n): ";
                cin >> car2;
                cin.ignore(40,'\n');
                if (toupper(car2) == 'S')
                {
                   jugadores[elegido].Descartar(posicion-1);
                   cout << "\n\n ¡¡¡ Descartada !!!!\n\n";
                   system("PAUSE");
                }
        }
    }
    while ( toupper(car) == 'S' && Descartadas(elegido)<5);
    Jugada jugNueva;
    int numDescarte= 0;
    for (numDescarte=0; numDescarte<5 ; numDescarte++) // para cada carta
    {
          if (jugadores[elegido].getDescarte(numDescarte)) continue; //sino lo salta
          if ( !jugNueva.anyadirCarta(jugAntigua.getCarta(numDescarte)) )
                    return false;
    }
    numDescarte= Descartadas(elegido);
    // añado las cartas que faltan
    if (!RepartirCartas(numDescarte, jugNueva))
                return false;
    jugadores[elegido].setJugada(jugNueva);
    return true;
}
        
        

int Pocker::Menu1()
    {
        int op;
        cout <<"\n1\tMostrar situacion\n"
        <<"2\tMostrar apuesta\n"
        <<"3\tAceptar apuesta\n"
        <<"4\tNo aceptar apuesta\n" << endl;
        cout << "Introduce una opcion: ";
        cin >> op;
        if (op>0 && op<5)
                return op;
        else
                return 0;
    }
    
int Pocker::Menu2()
    {
        int op;
        cout <<"\n1\tMostrar situacion\n"
        <<"2\tMostrar apuesta\n"
        <<"3\tSubir apuesta\n"
        <<"4\tPasar\n" << endl;
        cout << "Introduce una opcion: ";
        cin >> op;
        cin.ignore(40, '\n');
        if (op>0 && op<5)
                return op;
        else
                return 0;
    }

void Pocker::JugarTurno1(int i)
{
    bool fin= false;
    do
    {
        system("cls");
        jugadores[i].Actualizar();
        cout << "\n\nJUGADOR: " << jugadores[i].getNombre() << "\n" << endl;
        int opcion= Menu1();
        switch (opcion)
        {
                case 1:
                     cout << "\n\n";
                     jugadores[i].Imprimir();    
                     break;
                      
                case 2:
                     cout << "\n\n";
                     cout << "APUESTA: " << apuesta << endl;  
                     cout << "ACUMULADO: " << acumulado << endl;
                     break;
                     
                case 3:
                     if (jugadores[i].getDinero()<apuesta)
                     {
                         cout << "\n\nNo tienes suficiente dinero" << endl;  
                     }
                     else
                     {
                          int money= apuesta - jugadores[i].getApostado();
                          jugadores[i].setApostado(jugadores[i].getApostado()+ money);
                          jugadores[i].setDinero(jugadores[i].getDinero() - money); // pago la apuesta
                          cout << "\n\nApuesta cubierta" << endl;
                          acumulado+= apuesta;
                          pendientes--;
                          if (pendientes == 0)
                             apuesta= 0;
                          fin= true;
                     }
                     break;
                
                case 4:
                     jugadores[i].NoVoy();
                     pendientes--;
                     fin= true;
                     break;   
        }
        cout << "\n\n";
        system("pause");
   }
   while (!fin);
}         

void Pocker::JugarTurno2(int i)
{
    bool fin= false;
    int farol=0;
    do
    {
        system("cls");
        cout << "\n\nJUGADOR: " << jugadores[i].getNombre() << "\n" << endl;
        int opcion= Menu2();
        switch (opcion)
        {
                case 1:
                     cout << "\n\n";
                     jugadores[i].Imprimir();    
                     break;
                      
                case 2:
                     cout << "\n\n";
                     cout << "APUESTA: " << apuesta << endl;  
                     cout << "ACUMULADO: " << acumulado << endl;
                     break;
                     
                case 3:
                     do
                     {
                         cout <<"\n\nAPUESTA MINIMA " << MINIMO << " euro";
                         cout <<"\nAPUESTA MAXIMA " << MAXIMO << " euro";
                         cout <<"\n\nCuanto quieres apostar: ";
                         cin >> farol;
                         cin.ignore(40,'\n');
                     }
                     while (farol < 1 || farol > 100);
                     
                     if (jugadores[i].getDinero()< farol)
                     {
                         cout << "\n\nNo tienes suficiente dinero" << endl;  
                     }
                     else
                     {
                          jugadores[i].setDinero(jugadores[i].getDinero() - farol); // pago la apuesta
                          apuesta+=farol;
                          jugadores[i].setApostado(jugadores[i].getApostado()+ farol);
                          acumulado+= apuesta;
                          cout << "\n\nAPUESTA: " << apuesta << endl;  
                          cout << "ACUMULADO: " << acumulado << endl;
                          pendientes= CalcularActivos() -1;
                          fin= true;
                     }
                     break;
                
                case 4:
                     fin= true;
                     break;   
        }
        cout << "\n\n";
        system("pause");
   }
   while (!fin);
}         
 
int Pocker::CalcularGanador()
{
    int resultado= 0;
    Jugada j, ganadora;
    
    while (!jugadores[resultado].getActivo()) // empieza como ganador el primero disponible
    {
        resultado++;
    }   
    
    for (int i= (resultado + 1); i<numero; i++)
    {
        ganadora= jugadores[resultado].getJugada(); // la jugada ganadora tendrá la jugada de jugador resultado
        ganadora.ValorarJugada();
        if (jugadores[i].getActivo()) 
        {
            j= jugadores[i].getJugada();
            j.ValorarJugada();
            if (j>ganadora)
            {
                cout << "dentro de la comparacion en ganador";
                resultado= i;
            }
        }
    }
    return resultado;        
}

void Pocker::Jugar()
{
    bool fin= false;
    int turno= 1;
    char car= 'N';
    Bienvenida();
    jugadores= new Jugador[numero];
    for (int i=0; i<numero; i++)
    {
        cout << "\tJugador " << i+1 << endl;
        AnyadirJugador(i);
        cout << "\n";
    }
    int jugMano= SortearMano();
    int i;
    cout << "Empieza de mano por sorteo: " << jugadores[jugMano].getNombre() << endl;
    cout << "NOTA: Las cartas se reparten automaticamnete de forma aleatoria" << endl;
    cout << "\n\tComenzar el juego\n\n";
    system("pause");
    while (!fin)
    {   
        apuesta= 3;
        acumulado= 0;
        baraja.Inicializar();
        baraja.Barajear();
        if (!RepartoInicial())
        {
                cerr << "Fallo al repartir las cartas" << endl;
                return;
        }
        turno= 1;
        while (CalcularActivos()>1 )
        {
                i=jugMano;
                pendientes= CalcularActivos();
                while(pendientes > 0)
                {
                        if (CalcularActivos()<= 1) 
                           break;
                        if (jugadores[i%numero].getActivo()) 
                              JugarTurno1(i%numero);
                        if (jugadores[i%numero].getActivo()) 
                              JugarTurno2(i%numero);
                        i++;
                }
                
                if (CalcularActivos()<= 1 || turno == 3) 
                           break;
                           
                for (int i=jugMano; i < numero+jugMano; i++)
                {
                        if (jugadores[i%numero].getActivo() && CalcularActivos()>1) 
                              HacerDescartes(i%numero);
                }
                turno++;
                apuesta= 0;
        }    
        int ganador= CalcularGanador();
        Enhorabuena(ganador);
        cout << "Repartir el siguiente (s/n) (o finalizar el pocker): ";
        cin >> car;
        cin.ignore(40,'\n');
        if (toupper(car) == 'N')
                fin= true;
        else
                jugMano= (jugMano+1)%numero;        // pasa la manmo al siguiente
    }
}
      
                    
        
    
    
      
 
    
    
    
        


             
    
        
