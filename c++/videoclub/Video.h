#ifndef VIDEO_H
    #define VIDEO_H
    
    #include <string>
       
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
                void set(char *nom, char *dir, char *gen, short num);
                void setNombre(char *);
                void setDirector(char *);
                void setGenero(char *);
                void setCantidad(short num);
                
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
                int operator== (const Video &v) const;
                Video& operator= (const Video &v);
                
                Video& operator++();      // prefijo
                Video& operator++(int);   // sufijo             
                Video& operator--();      // prefijo          
                Video& operator--(int);   // sufijo             
                
                
                // funcionales
                void Imprimir() const;
    };
    
#endif
    
