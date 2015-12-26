#ifndef CONTROL_H
    #define CONTROL_H
    
    #include "Conjetura.h"
    #include "Respuesta.h"
    #include "Elemento.h"
          
    class Control
    {
        private:
                // Miembros de la clase
                Elemento numeroSecreto;
                Conjetura entrada;
                Respuesta salida;
                
        protected:
                // Funciones de utilidad
                void Bienvenida(int ) const;
                void Aviso() const;
                Respuesta Evaluar(const Conjetura &c) const;
                bool Ganador(const Respuesta &r) const;
                void Felicidades() const;
                void Mostrar(const Conjetura &c, const Respuesta &r) const;
                void Adios() const;
                int obtenerRojo(const Conjetura &c) const;
                int obtenerAmarillo(const Conjetura &c) const;
                int obtenerVerde(const Conjetura &c) const;
        
        public:
                // constructor por defecto
                Control();
                
                // Funcion de utilidad
                void Jugar(int intentos);
                               
    };
#endif 
