#ifndef CARTAS_H
    #define CARTAS_H
    
    #include <string>
    #include <cstdlib>
    #include <iostream>
    
    using namespace std;
    
    class Cartas
    {
        private:
                
                string nombre, direccion, ciudad, estado;
                int codigo;
                
        public:
                // modificadores
                bool set(char *nom, char *dir, char *ciu, char *est, int cod);
                                            
                // inspectores
                inline const string getNombre() const
                { return nombre; }
                inline const string getDirector() const
                { return direccion; }  
                inline const string getGenero() const
                { return ciudad; }
                 inline const string getEstado() const
                { return estado; }
                inline int getCodigo() const
                { return codigo; }
                
                // funcionales
                void Imprimir();
                bool Leer();
                bool GuardarFichero(const char *);
                bool LeerFichero(const char *, int num);
                
                // operadores
                bool operator==(const Cartas &c);
                bool operator!=(const Cartas &c);
    };
    
#endif
    
