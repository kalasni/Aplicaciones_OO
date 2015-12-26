
#include "video.h"
#include <iostream>
#include <string.h>
 
using namespace std;

int main()
{
   video mivideo; // objeto de la clase video.   
   
   mivideo.leer_teclado();
   system("PAUSE");
   mivideo.imprimir();
   mivideo.guardar_fichero("videos.txt");
   cout << "Numero de videos: ";
   int num;
   cin >> num;
   video *coleccion= new video[num];
   // video::get_total();
   mivideo.leer_fichero("videos.txt",1);
   mivideo.imprimir();
   system("PAUSE");	
   return 0;
}
