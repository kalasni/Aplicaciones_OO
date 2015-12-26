#ifndef JUGADA_H
    #define JUGADA_H
    
    #include "Carta.h"
        
    enum TipoJugadas {escalera_color=9, pocker=8, full=7, color=6, escalera=5, trio=4, doble=3, pareja=2, carta=1};
        
    class Jugada
    {
        private:
                Carta mano[5];
                int recibidas;
                TipoJugadas valor;
                Carta cartaAlta;
                Carta cartaBaja;
                Carta cartaDoble;
                
                
        protected:
                bool Escalera() const;
                bool Color() const;
                bool Pocker()const;
                bool Trio()const;
                bool Doble() const;
                bool Pareja()const;
                bool Full()const;
                void Ordenar();
                               
        public:
                // constructores
                Jugada();
                
                // modificadores                
                bool anyadirCarta(const Carta &c);
                
                // inspectores
                void ValorarJugada();
                bool Completa();
                Carta getCarta(int posicion)
                { return  mano[posicion]; }
                const TipoJugadas getValor() const
                { return valor; }
                const Carta getCartaAlta() const
                { return cartaAlta; }
                const Carta getCartaBaja() const
                { return cartaBaja; }
                const Carta getCartaDoble() const
                { return cartaDoble; }
                
                // funcionales
                void Imprimir();
                
                bool operator==(const Jugada &j);
                bool operator<(const Jugada &j);
                bool operator>(const Jugada &j);
    };
#endif
    
                
                
                  
                        
        
