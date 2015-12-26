#ifndef CARTERO_H
    #define CARTERO_H
    
    #include "Cartas.h"
    #include <string.h>
    #include <string>
    #include <cstdlib>
    #include <iostream>
    #include <fstream>
    
    using namespace std;
    
    class Cartero
    {
        private:
                char *nombre;
                Cartas *saco;
                int tamanno, numero;
                
        protected:
                bool sacoLLeno();
                
        public:
                // constructores y destructor
                Cartero();
                Cartero(const char *, int );
                Cartero(const Cartero &c);
                ~Cartero();
                                  
                // modificadores
                bool Iniciar(const char *nom, int n);
                bool insertarCarta(const Cartas &c);
                                            
                // inspectores
                const char * getNombre() const
                { return nombre; }
                int getNumero() const
                { return numero; }
                int getTamanno() const
                { return tamanno; }
                Cartas getCarta(int posicion) const;
                
                // funcionales
                void Imprimir();
                int GuardarFichero(const char *);
                int LeerFichero(const char *, int);
                
                // operadores
                Cartero & operator= (const Cartero &c);
                bool operator== (const Cartero &c);
                bool operator!= (const Cartero &c);
    };
    
#endif
    
