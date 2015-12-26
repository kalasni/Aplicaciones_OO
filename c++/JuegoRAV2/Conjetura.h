#ifndef CONJETURA_H
    #define CONJETURA_H
    
    #include <iostream>
    #include <string>
    #include "Elemento.h"
    
    using namespace std;
    
    class Conjetura
    {
        private:
                // Miembros de la clase
                Elemento numero;
                
        protected:
                // Funcion modificadora
                void FijarDigito(int i, int v);
        
        public:
                // constructotr por defecto
                Conjetura();
                
                // Funciones inspectoras
                int obtenerDigito(int i) const;
                               
                // modificadores
                bool Actualizar();
    };

#endif    
    
