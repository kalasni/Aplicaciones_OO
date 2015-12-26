#ifndef FECHA
    #define FECHA
    
    #include <iostream>
    #include <string>
            
    using namespace std;
                               
    class Fecha
    {
    private:
        int dia, mes, anno;
        bool Comprobar(int dd, int mm, int aa);
        int ConvertirMes(string m);
    public:
        // constructores
        Fecha();
        Fecha(int dd, char  *m, int aa);
        Fecha(int dd, int mm, int aa);
        
        //modificadores
        void set(int dd, int mm, int aa);
        void set(int dd, char *, int aa);
        void setAnno(int aa);
        void setMes(char *);
        void setMes(int);
        void setDia(int dd);
        
        //inspectores
        inline int getAnno() const
          { return anno; }
        inline int getMes() const
          { return mes; }
        string getMesNombre() const;
        inline int getDia() const
          { return dia; }
        
        // funcionales
        bool Leer();
        void Mostrar();
        
        //operadores sobrecargados de la clase
        bool operator<= (const Fecha &f);
        bool operator>= (const Fecha &f);
        bool operator< (const Fecha &f);
        bool operator> (const Fecha &f);
        bool operator== (const Fecha &f);       
        
        friend ostream& operator<< (ostream &salida, const Fecha &f);
        friend istream& operator>> (istream &entrada, Fecha &f);   
       
    };
#endif    
         
