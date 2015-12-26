#ifndef BARAJA_H
    #define BARAJA_H
    
    #include "Carta.h"
    #include "EnteroAleatorio.h"
    
    
    class Baraja
    {
        private:
                Carta baraja[52];
                bool repartidas[52];
                
        protected:
                void Inicializar();
                bool Repartida(const Carta &c) const;
        public:
                friend class Pocker;
                // constructor por defecto
                Baraja();
                
                // inspectores
                bool Vacia();
                
                // metodos funcionales
                Carta Repartir();
                Carta RepartirAleatorio();
                void Barajear();
                void Imprimir();
    };
#endif            
               
