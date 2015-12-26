#ifndef RACIONAL
    #define RACIONAL
    
    #include <iostream>
    #include <string>
    
    using namespace std;
    
    // ADT Racional: Declaracion de la clase
    class Racional
    {
        private:
                int numerador;
                int denominador;
        public:
                // constructores
                Racional();
                Racional(int n, int d=1);
                
                //inspectores
                int getNumerador() const;
                int getDenominador() const;
                
                // modificadores
                void setNumerador(int n);
                void setDenominador(int d);
                
                // utilidades aritmeticas y de stream
                Racional Sumar(const Racional& r) const; 
                /* const indica que no se va a modificar ningún miembro dato
                   del objeto que invoca la funcion Sumar */
                   
                Racional Restar(const Racional& r) const;
                Racional Multiplicar(const Racional& r) const; 
                Racional Dividir(const Racional& r) const;
                void Simplificar();
                
                void Insertar(ostream &salida) const;
                void Extraer(istream &entrada);
                        
                // Operadores sobrecargados declarados como friend de la clase
                bool Racional::operator== (const Racional &v)const;
                Racional& Racional::operator= (const Racional &r);
                Racional& Racional::operator= (const int &num);
                friend Racional operator+ (const Racional &r, const Racional &s);
                friend Racional operator- (const Racional &r, const Racional &s);
                friend Racional operator* (const Racional &r, const Racional &s);
                friend Racional operator/ (const Racional &r, const Racional &s);
                
                friend ostream& operator<< (ostream &salida, const Racional &r);
                friend istream& operator>> (istream &entrada, Racional &r);
    };
    int GenerarPrimo(int posicion);
    
#endif    
        
        
