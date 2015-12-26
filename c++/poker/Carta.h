#ifndef CARTA_H
    #define CARTA_H
    
    enum TipoPalo {corazones=1, diamantes, picas, treboles};
    enum TipoValor {as=1, rey, reina, jack, diez, nueve, ocho, siete, seis, cinco, cuatro, tres, dos};
        
    class Carta
    {
        private:
                TipoPalo palo;
                TipoValor valor;
        public:
                // constructor
                Carta(TipoValor v= dos, TipoPalo p= treboles);
                
                //modificadores
                void setPalo(TipoPalo p);
                void setValor(TipoValor v);
                
                // inspectores
                TipoPalo getPalo() const
                { return palo; }
                TipoValor getValor() const
                { return valor; }  
                void Imprimir();
                
                // operadores sobrecargados
                
                /* Predomina el valor antes que el palo, por orden 
                   el as, rey, reina .... En caso de tener el mismo valor
                   ganará el palo de corazones, diamanttes ... */
                // Ver implementacion   
                
                bool operator==(const Carta &c);
                bool operator!=(const Carta &c);
                bool operator<(const Carta &c);
                bool operator>(const Carta &c);
                bool operator<=(const Carta &c);
                bool operator>=(const Carta &c);
    };
#endif            
                
