#include "Elemento.h"

Elemento::Elemento(int a, int b, int c)
{
    FijarX(a);
    FijarY(b);
    FijarZ(c);
}

void Elemento::FijarX(int a)
{
    if (a>=0 && a<=9)
        x=a;
}

void Elemento::FijarY(int b)
{
    if (b>=0 && b<=9)
        y=b;
}

void Elemento::FijarZ(int c)
{
    if (c>=0 && c<=9)
        z=c;
}
