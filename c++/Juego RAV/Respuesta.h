#ifndef RESPUESTA_H
    #define RESPUESTA_H
    
    #include "Elemento.h"
    
    class Respuesta
    {
        private:
                // Miembros de la clase
                Elemento contadores;
                
        protected:
                // modificadores
                void FijarRojo(int r);
                void FijarAmarillo(int a);
                void FijarVerde(int v);
        
        public:
                // constructor por defecto
                Respuesta(int r=0, int a=0, int v=0);
                
                // Funciones inspectoras
                int obtenerRojo() const;
                int obtenerAmarillo() const;
                int obtenerVerde() const;
    };

#endif 
