#ifndef JUGADOR_H
    #define JUGADOR_H
    
    #include "Carta.h"  
    #include "Jugada.h"             
                                                             
    class Jugador
    {
        private:
                char *nombre;
                int dinero;
                Jugada jugada;
                int apostado;
                bool activo;
                bool descartes[5];
        protected:
                void Actualizar();
                void setApostado(int ap)
                { apostado= ap; }
                void setJugada(const Jugada &j);
                void Descartar(int posicion);
                bool getDescarte(int posicion)
                { return descartes[posicion]; }
                bool getActivo()
                { return activo; }
                int getApostado()
                { return apostado; }
                
        public:
                friend class Pocker;
                void Voy()
                { activo= true;}    
                void NoVoy()
                { activo= false;}           
                                                
                // constructor 
                Jugador();                // por defecto
                Jugador(char *nombre, int d, const Jugada &j); // con argumentos
                Jugador(const Jugador &j);
                ~Jugador();
                
                // modificadores
                  void setNombre(char *);
                void setDinero(int d);
                char * getNombre() const
                { return nombre; }
                int getDinero() const
                { return dinero; } 
                Jugada getJugada() const 
                { return  jugada; }
                void Imprimir();
                
                // sobrecarga de operadoradores
                bool operator==(const Jugador &j);
                Jugador& operator=(const Jugador &j);
    };
#endif            
                
