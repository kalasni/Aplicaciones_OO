#ifndef POCKER_H
    #define POCKER_H
    
    #include "Carta.h"
    #include "Baraja.h"
    #include "Jugada.h"
    #include "Jugador.h"
    
    #define MINIMO 1
    #define MAXIMO 100
    
    class Pocker
    {
        private:
                Jugador *jugadores;
                Baraja baraja;
                int numero;
                int apuesta;
                int acumulado;
                int pendientes;
        
        protected:
                
                void Descarte(Jugador &j); 
                void Bienvenida();
                int SortearMano();
                bool RepartirCartas(int num, Jugada &jug);
                bool RepartoInicial();
                int Descartadas(int i);
                bool HacerDescartes(int elegido);
                void AnyadirJugador(int i);
                int Menu1();
                int Menu2();
                void JugarTurno1(int i);
                void JugarTurno2(int i);
                int CalcularActivos();
                int CalcularGanador();
                void Enhorabuena(int); 
        public:
                // constructores y destructor
                Pocker();
                Pocker(const Pocker &p);
                ~Pocker();
                
                void Jugar();
    };
#endif
