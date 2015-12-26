#ifndef INVENTARIO_H
    #define INVENTARIO_H
    
    #include "Video.h"
    
    const int MAX= 200;
    
    class Inventario
    {
        private:
                Video almacen[MAX];
                Video alquilados[MAX];
                short totalVideos;
                int totalAlquilados;
        public:
                // contructores
                Inventario();
                Inventario(const Inventario&); // constructotr copia
                
                // inspectores (funciones inline implicitas)
                short getNumVideos() const
                { return totalVideos; }
                short getAlquilados() const
                { return totalAlquilados; }
                Video getVideo(int i=1) const //por defecto el primero
                { 
                  return almacen[i-1];
                }
  
                // modificadores
                void InicializarInventario();
                void InicializarAlmacen();
                void InicializarAlquilados();
                void InicializarTotalVideos();
                void InicializarTotalAlquilados();
                
                void insertarVideo(const Video &v);
                int borrarVideo(int i);
                
                // funciones de busqueda sobrecargadas
                int BuscarVideo(const char*nombre, int posicion=0)const; // devuelve la posicion sino 0
                int BuscarVideo(const Video &v, int posicion= 0)const; // devuelve la posicion sino 0
                int BuscarVideo(const char*nombre, const char*director)const; // devuelve la posicion sino 0
                
                int Disponible(int posicion)const;  // si disponible 1 sino 0
                int Alquilar(const Video &v);
                int Devolver(const Video &v);
                void Ordenar(int opcion);
                void Imprimir() const;
                
  };     
#endif         
