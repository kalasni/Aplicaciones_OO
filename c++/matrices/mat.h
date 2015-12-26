/*    MATRIZ.H    */				// Pantalla completa | Volver

#ifndef __MATRIZ_H
#define __MATRIZ_H

#ifndef __BOOL_H
#include "bool.h"
#endif

typedef unsigned char linea;

class Matriz
{
private:
  linea m, n;
  float **elem;

  void Iniciar ()                   { m = n = 0; elem = 0; }
  bool Cerrar ();
  float BuscarPivote (linea i, linea j);
  bool IntercambiarFilas (linea i, linea j);
public:
  Matriz ()                         { Iniciar (); }
  Matriz (linea i, linea j)         { Iniciar (); Hacer (i, j); }
  ~Matriz ()                        { Cerrar (); }
  bool Hacer (linea i, linea j);
  Matriz &Cargar (int posx, int posy);
  Matriz &HacerAzar ();
  Matriz &HacerNula ();
  Matriz &HacerIdentidad ();
  Matriz &HacerTriangular ();
  Matriz &HacerDiagonal ();
  Matriz &Ampliar (Matriz &M)       { return *this = Anexar (*this, M); }
  Matriz &SubMatriz (linea i, linea j);
  bool EsNula ();
  bool EsIdentidad ();
  bool EsTriangular ();
  bool EsCuadrada ()                { return m && m == n; }
  float Determinante ();
  float Adjunto (linea i, linea j);
  float MenorComplementario (linea i, linea j);
  Matriz &operator = (Matriz &M);
  Matriz &operator + (Matriz &M);
  Matriz &operator * (Matriz &M);
  Matriz &operator * (float f);
  bool operator ! ()                { return !elem; }
  float *operator [] (linea i)      { return elem [i]; }
  void Mostrar (int posx, int posy, int dec = 1);
  friend Matriz &Anexar (Matriz &A, Matriz &B);
};

#endif


