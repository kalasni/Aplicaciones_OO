#ifndef FUTBOLISTA_H
    #define FUTBOLISTA_H
    
    #include <string>
    #include "Fecha.h"
    
    using namespace std;
    
    class Futbolista
    {
        private:
                string nombre;
                Fecha fecha;
        public:                   
                Futbolista();
                void Inicializar();
                
                //inspectores
                string getNombre() const
                { return nombre; }
                Fecha getFecha() const
                { return fecha; }
                void Mostrar();
                
                //modificadores
                void setNombre(const string &s);
                void setFecha(const Fecha &f); 
                void Leer();
                
                
                //operadores sobrecargados de la clase
                bool operator<= (const Futbolista &f);
                bool operator>= (const Futbolista &f);
                bool operator< (const Futbolista &f);
                bool operator> (const Futbolista &f);
                bool operator== (const Futbolista &f);     
    };
#endif
                                                      
