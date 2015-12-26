#ifndef CALCULADORA_H
    #define CALCULADORA_H
    #include "Racional.h"
    
    #define MAX_OPERADORES 8
     
    
    class Calculadora
    {
        private:
                Racional resultado;
                int operador;
                bool estado;
                
        protected:
                int Buscar(const string &s);
        public:
                // constructores
                Calculadora();
                                
                //inspectores
                bool getEstado() const
                {  return estado; }
                       
                // modificadores
                void Encender()
                {  
                   resultado= 1;
                   operador= 0;
                   estado= true; 
                };
                void Apagar()
                {  estado= false; };
                void setRacional();
                void setOperador();
    };
    
       
#endif    
        
        
