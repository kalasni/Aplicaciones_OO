#include "video.h"
#include <iostream>
#include <string.h>


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
                       if(coleccion[contador].leer())
                       {
                          contador++;
                       }
                       else 
                       {
                         cout << "no se ha podido leer";
                       }
                     else
                     {
                        cout << "Coleccion llena";
                     }
                     break;
                     
                     
                case 2: 
                     for(int i=0; i<contador; i++)
                     {
                       cout << "coleccion de videos \n\n";
                       coleccion[i].imprimir();
                     }
                     break; 
               
                
               case 3:
                    for(int=0; i<contador; i++)
                    {
                      if(!coleccion[i].guardar_fichero())
                      {
                        cout << "No se ha podido guardar";
                        break;
                      }
                    }
                    break;
                    
               case 4:
                    contador=0;
                    while(j<num && coleccion[j].leer_fichero("coleccion.txt", j))
                    {
                      j++;
                    }
                    if(j<=0) cout << "No se ha podido leer " << endl;
                    else
                    { 
                      cout << "Se han leido " << j << "videos" << endl;
                      contador= j;                                                            
                    }
                    break;
                    
              case 5:  
                   exit(0);
                   system("pause");
                   system("cls");
                                                                                                                                               
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
     cin.ingnore(40, '\n');
     
     if(op>0 && op<5)
     {
       return opc;
     }
     else return 0;   
   }  
