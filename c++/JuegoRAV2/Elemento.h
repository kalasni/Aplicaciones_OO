#ifndef ELEMENTO_H
    #define ELEMENTO_H
    
    class Elemento
    {
        private:
                // Miembros de la clase
                int x;
                int y;
                int z;
        public:
                // constructotr por defecto
                Elemento(int a=0, int b=0, int c=0);
                
                // Funciones inspectoras
                inline int obtenerX() const
                { return x; }
                inline int obtenerY() const
                { return y; }
                inline int obtenerZ() const
                { return z; }
                
                // modificadores
                void FijarX(int a);
                void FijarY(int b);
                void FijarZ(int c);
    };

#endif    
    
                
