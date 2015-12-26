#ifndef VIDEO_H
    #define VIDEO_H
    
    #include <string>
    const int TAM= 40;
    
    class Video
    {
        private:
                
                char *nombre ;
                char *director;
                char *genero ;
                short cantidad;
        public:
                // constructores
                Video();
                Video(char *nom);
                Video(char *nom, char *dir);
                Video(char *nom, char *dir, char *gen);
                Video(char *nom, char *dir, char *gen, short num);
                Video(const Video&);
                
                // destructor
                ~Video();
                
                // modificadores
                bool set(char *nom, char *dir, char *gen, short num);
                bool setNombre(char *);
                bool setDirector(char *);
                bool setGenero(char *);
                bool setCantidad(short num);
                
                // inspectores
                inline const char* getNombre() const
                { return nombre; }
                inline const char * getDirector() const
                { return director; }  
                inline const char * getGenero() const
                { return genero; }
                inline short getCantidad() const
                { return cantidad; }
                
                // operadores sobrecargados
                int operator== (const Video &v);
                Video& operator= (const Video &v);
                
                Video& operator++();      // prefijo
                Video& operator++(int);   // sufijo             
                Video& operator--();      // prefijo          
                Video& operator--(int);   // sufijo             
                
                
                // funcionales
                bool Leer();
                void Imprimir();
                bool GuardarFichero(char *nombre);
                bool LeerFichero(char *nombre, int num);
    };
    
#endif
    
