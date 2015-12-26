#ifndef ENTEROALEATORIO
    #define ENTEROALEATORIO

    #include <stdlib.h>
    
class EnteroAleatorio
{
    private:
        int inferior;
        int superior;
    public:
        EnteroAleatorio(int a=0, int b= RAND_MAX); //constructores
        EnteroAleatorio(int a, int b, unsigned int semilla);
        
        int getInferior(); // inspectores
        int getSuperior();
        
        void setIntervalo(int a, int b);  // modificadores
        void setSemilla(unsigned int s);
                
        int GenerarAleatorio();  // funcionales
};

#endif
