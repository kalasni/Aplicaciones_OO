*    MATRIZ.CPP    */				// Pantalla completa | Volver

#include "matriz.h"
#include <conio.h>
#include <stdlib.h>

#define __MAX_DEC__ 5           // Cantidad máxima de decimales

static char *formato [] =
{ "%f ", "%5.0f ", "%7.1f ", "%8.2f ", "%9.3f ", "%10.4f ", "%11.5f " };

Matriz &Matriz::Cargar (int posx, int posy)
{
  linea i, j;
  float valor;
  for (i = 0; i < m; i++, posy++)
    for (j = 0; j < n; j++)
    {
      gotoxy (posx + 8 * j, posy);
      cscanf ("%f", &valor);
      elem [i] [j] = valor;
    }
  return *this;
}

void Matriz::Mostrar (int posx, int posy, int dec)
{
  char *f = formato [dec < 0 || dec > __MAX_DEC__? 0: ++dec];
  if (elem)
  {
    linea i, j;
    for (i = 0; i < m; i++)
    {
      gotoxy (posx, posy++);
      for (j = 0; j < n; j++) cprintf (f, elem [i] [j]);
    }
  }
}

Matriz &Matriz::HacerAzar ()
{
  linea i, j;
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      elem [j] [i] = (float) (random (100) - random (100)) / (1 + random (10));
  return *this;
}

Matriz &Anexar (Matriz &A, Matriz &B)
{
  static Matriz M;
  linea i, j, k;
  if (A.m == B.m)
  {
    if (!M.Hacer (A.m, A.n + B.n))
      for (i = 0; i < M.m; i++)
      {
        for (j = 0; j < A.n; j++) M [i] [j] = A [i] [j];
        for (k = 0; k < B.n; k++) M [i] [j++] = B [i] [k];
      }
  }
  else M.Cerrar ();
  return M;
}

bool Matriz::Hacer (linea i, linea j)
{
  if (i == m && j == n) return _F;
  Cerrar ();
  if ((m = i) && (n = j) && (elem = new float * [m]))
  {
    do elem [--i] = 0; while (i);
    while ((elem [i] = new float [n]) && ++i < m);
  }
  return i < m? Cerrar (): _F;
}

Matriz &Matriz::SubMatriz (linea i, linea j)
{
  static Matriz M;
  linea p, q, r, s;
  if (i < m && j < n)
  {
    if (!M.Hacer (m - 1, n - 1))
      for (r = 0, p = 0; p < m; p++)
        if (p != i)
        {
          for (s = 0, q = 0; q < n; q++)
            if (q != j) M [r] [s++] = elem [p] [q];
          r++;
        }
  }
  else M.Cerrar ();
  return M;
}

float Matriz::BuscarPivote (linea i, linea j)
{
  linea k = i;
  while (!elem [k] [j] && ++k < m);
  if (k > i) IntercambiarFilas (k, i);
  return elem [i] [j];
}

bool Matriz::IntercambiarFilas (linea i, linea j)
{
  float r;
  if (!(i < m && j < m)) return _V;
  for (linea k = 0; k < n; k++)
  { r = elem [i] [k]; elem [i] [k] = elem [j] [k]; elem [j] [k] = r; }
  return _F;
}

float Matriz::Adjunto (linea i, linea j)
{
  float f = MenorComplementario (i, j);
  return (i + j) % 2? -f: f;
}

float Matriz::MenorComplementario (linea i, linea j)
{ return SubMatriz (i, j).Determinante (); }

bool Matriz::Cerrar ()
{
  if (elem)
  {
    while (m--) if (elem [m]) delete elem [m];
    delete elem;
  }
  Iniciar ();
  return _V;
}

Matriz &Matriz::operator = (Matriz &M)
{
  if (!Hacer (M.m, M.n))
  {
    linea i, j;
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        elem [i] [j] = M [i] [j];
  }
  return *this;
}

Matriz &Matriz::HacerNula ()
{
  linea i, j;
  for (j = 0; j < m; j++)
    for (i = 0; i < n; i++)
      elem [j] [i] = 0;
  return *this;
}

Matriz &Matriz::HacerIdentidad ()
{
  linea i, j;
  if (EsCuadrada ())
    for (j = 0; j < m; j++)
      for (i = 0; i < n; i++)
        elem [j] [i] = i == j;
  return *this;
}

Matriz &Matriz::HacerTriangular ()
{
  linea i, j, k;
  float p, q;
  for (i = 1; i < m; i++)
    for (j = 0; j < i && j < n; j++)
    {
      p = elem [i] [j];
      q = elem [0] [j];
      for (k = j; k < n; k++) elem [i] [k] -= (elem [0] [k] * p) / q;
    }
  return *this;
}

Matriz &Matriz::HacerDiagonal ()
{
  linea i, x, y;
  float pivote;
  for (i = 0; i < m; i++)
    if (!!(pivote = BuscarPivote (i, i)))
    {
      for (x = 0; x < m; x++)
        if (x != i)
          for (y = i + 1; y < n; y++)
            elem [x] [y] -= (elem [i] [y] * elem [x] [i]) / pivote;
      for (y = i + 1; y < n; y++) elem [i] [y] /= pivote;
      for (x = 0; x < m; x++) elem [x] [i] = (x == i);
    }
  return *this;
}

bool Matriz::EsIdentidad ()
{
  linea i, j;
  bool es;
  if (es = EsCuadrada ())
    for (i = 0; es && i < m; i++)
      for (j = 0; es && j < n; j++)
        es = elem [i] [j] == float (i == j);
  return es;
}

bool Matriz::EsNula ()
{
  linea i, j;
  bool es = _V;
  for (i = 0; es && i < m; i++)
    for (j = 0; es && j < n; j++)
      es = !elem [i] [j];
  return es;
}

bool Matriz::EsTriangular ()
{
  linea i, j;
  bool es = _V;
  for (j = 1; es && j < m; j++)
    for (i = 0; es && i < j && i < n; i++)
      es = !elem [j] [i];
  return es;
}

float Matriz::Determinante ()
{
  linea i, j, k;
  float d = 0, p;
  if (EsCuadrada ())
    switch (m)
    {
      case 1:
        return elem [0] [0];
      case 2:
        return elem [0] [0] * elem [1] [1] - elem [1] [0] * elem [0] [1];
      case 3:
        for (i = 0; i < m; i++)
        {
          for (p = 1, k = i, j = 0; j < m && !!(p *= elem [k++ % m] [j++]); );
          d += p;
        }
        for (i = 0; i < m; i++)
        {
          for (p = 1, k = m + i, j = 0; j < m && !!(p *= elem [k-- % m] [j++]); );
          d -= p;
        }
        break;
      default: for (j = 0; j < n; j++) d += elem [0] [j] * Adjunto (0, j);
    }
  return d;
}

Matriz &Matriz::operator * (Matriz &M)
{
  static Matriz P;
  linea i, j, k;
  float p;
  if (n == M.m)
  {
    if (!P.Hacer (m, M.n))
      for (i = 0; i < P.m; i++)
        for (j = 0; j < P.n; j++)
          {
            for (p = 0, k = 0; k < n; k++)
              p += elem [i] [k] * M [k] [j];
            P [i] [j] = p;
          }
  }
  else P.Cerrar ();
  return P;
}

Matriz &Matriz::operator * (float f)
{
  static Matriz P;
  linea i, j;
  if (!P.Hacer (m, n))
    for (i = 0; i < m; i++)
      for (j = 0; j < n; j++)
        P [i] [j] = elem [i] [j] * f;
  return P;
}

Matriz &Matriz::operator + (Matriz &M)
{
  static Matriz P;
  linea i, j;
  if (m == M.m && n == M.n)
  {
    if (!P.Hacer (m, n))
      for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
          P [i] [j] = elem [i] [j] + M [i] [j];
  }
  else P.Cerrar ();
  return P;
}


