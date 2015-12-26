/* Programa que permite calcular el volumen de un donut conociendo las 
   dimensiones y el grosor del mismo. (01-07-03) */

#include <iostream>
#include <string>

using namespace std;

double Tamano_donut (const int &ext, const int &inte, const float &g);
float cilindro (const int &radio, const float &g);

int main()
{
  cout << "Dimensiones del donut: \n"; 
  cout << "Tamano exterior (radio exterior): ";
  int exterior;
  cin >> exterior; // Radio exterior
  cout << "tamano del agujero (radio interior): " << flush;
  int interior; // Radio interior
  cin >> interior;
  cout << "Grosor del donut: ";
  float grosor;
  cin >> grosor;
  
  cout << "\n\n Tamano del donut: " << Tamano_donut(exterior, interior, grosor)
  << " centim. cubicos" << endl;
  system("pause");
  return 0;
  }
  
  double Tamano_donut (const int &ext, const int &inte, const float &g)
  { 
    if(ext > inte)
    {
      return double(cilindro(ext, g) - cilindro(inte, g));
    }
    else return 0;  
  }
  
  
  float cilindro (const int &radio, const float &g)
  {
    const float pi= 3.1415f;
    return float(pi * radio * radio *g);  
  }  
