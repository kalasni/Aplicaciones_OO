#include "video.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std; //  Usando espacio de nombres estandar.

int menu(void);

int main()
{
  int contador=0;
  int num;
  cout << "Numero de videos: ";
  cin >> num;
  video *coleccion= new video[num];
  
  while(1)
  {
    int opcion= menu();
         switch(opcion) {
                case 1:
                     if(contador < num)
                     {
                       coleccion[contador].leer_teclado();
                       contador++;
                     }
                     else
                     {
                        cout << "Coleccion llena";
                     }
                     break;
                     
                     
                case 2: 
                     cout << "coleccion de videos \n\n";
                     for(int i=0; i<contador; i++)
                     {
                       coleccion[i].imprimir();
                     }
                     break; 
               
                
               case 3:
                    //int n=0;
                    for(int i=0; i<contador; i++)
                    {
                      if(!coleccion[i].guardar_fichero("coleccion.txt"))
                      {
                        cout << "No se ha podido guardar";
                        break;
                      }
                      //n++;
                      
                    }
                    break;
                    
               case 4:
                    contador=0;
                    while(contador<num && coleccion[contador].leer_fichero("coleccion.txt", contador))
                    {
                      contador++;
                    }
                    if(contador<=0) cout << "No se ha podido leer " << endl;
                    else
                    { 
                      cout << "Se han leido " << contador << "videos" << endl;
                                                                               
                    }
                    break;
                    
              case 5:  
                   exit(0);
                   system("pause");
                   system("cls");
                                                                                                                                               
         }
       } 
   } 
       
       
   int menu()
   {
     int opc;
     cout << "\n\n MENU \n\n";
     cout << "(1)- INTRODUCIR VIDEO " << endl;
     cout << "(2)- MOSTRAR COLECCION DE VIDEOS " << endl;
     cout << "(3)- GUARDAR FICHERO DE COLECCION DE VIDEOS " << endl;
     cout << "(4)- LEER FICHERO" << endl;
     cout << "(5)- SALIR" << endl;  
     cin >> opc;
     cin.ignore(40, '\n');
     
     if(opc>0 && opc<6)
     {
       return opc;
     }
     else return 0;   
   }  
