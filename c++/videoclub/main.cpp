#include <iostream>
#include <stdlib.h>
#include "Video.h"
#include "Inventario.h"

using namespace std;

int main(int argc, char *argv[])
{
 Inventario videoclub;
  {
  Video vid;
  vid.set("el resplandor", "Kubric", "Terror", 2);
  vid.Imprimir();
  cout << "Genero  : " << vid.getGenero() << endl;
  vid.set("el resplandor", "Kubric", "d", 0);
  }
  
  Video *v= new Video;
  v->set("otra peli", "Kubric", "humor", 4);
  cout << "\n\n";
  v->Imprimir();
  delete v;
  cout << "numero de videos: ";
  
  int x;
  cin >> x;
 
  Video *array= new Video[x];
  for (int i=0; i<x; i++)
  {
    array[i].set("alfonso", "director", "miedo", i);
  }
  for (int i=0; i<x; i++)
  {
    array[i].Imprimir();
    cout << endl;
  }
  
  cout << "\n\n";
  Video vid3("prueba", "director");
  vid3.Imprimir();
  vid3.set("el resplandor", "Kubric", "final", 3);
  vid3.Imprimir();
  cout << "\n\nprueba de copiado \n\n";system("PAUSE");
  Video vid4(vid3);
  vid4.Imprimir();
  cout << "\n\nprueba de copiado \n\n";system("PAUSE");
  Video vid5;
  vid5= vid4;
  vid3--;
  vid3.Imprimir();
  cout << endl;
  Video v6(vid4++);
  v6.Imprimir();
  cout << endl;
  vid4.Imprimir();
  cout << endl;
  vid5++;
  vid5.Imprimir();
  cout << endl;
  cout << "\n\n";
  system("PAUSE");
  videoclub.insertarVideo(vid5);
  for (int i=0; i<6; i++)
  {
    videoclub.insertarVideo(array[2]);
  }
  videoclub.Imprimir();
  system("pause");
  Video pol;
  int puesto= videoclub.BuscarVideo(vid5);
  if (puesto)
  {
    pol= videoclub.getVideo(puesto);
  }
  pol.Imprimir();
  system("pause");
  return 0;
}
