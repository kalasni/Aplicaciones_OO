#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592

float areatri();
float areatrisos();
float areacuadra();
float areatrape();
float areacir();
float arearectangulo();
float salir();

int main()
{
  int a, opc;
  float (*ptro[])() = {areatri, areatrisos, areacuadra, areatrape,
  areacir, arearectangulo, salir};
  
 do 
 { 
     printf ("Marque el area que quiere calcular: \n");
     printf ("\n\n");
     printf ("(1) - Triangulo Rectangulo \n");
     printf ("(2) - Triangulo Isosceles \n");
     printf ("(3) - Cuadrado \n");
     printf ("(4) - Trapecio \n");
     printf ("(5) - Circulo \n");
     printf ("(6) - Rectangulo \n");
     scanf ("%d", &a);
     fflush (stdin);
     system ("cls");
     
     printf ("El area es: %f ", (*ptro[a-1])());
     printf ("\n\n");
     system ("pause");
     
 } while (a < 7);
     
}   
 

  float areatri()
  {
    float cat1, cat2;
    printf ("Introduzca las longuitudes de los catetos del triangulo:");
    scanf ("%f %f", &cat1, &cat2);
    system ("cls");
    return (cat1 * cat2 / 2);
  }

  float areatrisos()
  {
    float lado1, lado2;
    printf ("Introduzca las longuitudes de los dos lados desiguales:");
    scanf ("%f %f", &lado1, &lado2);
    system ("cls");
    return (lado1 * lado2 / 2);
  }
  
  
  float areacuadra()
  {
    float lado;
    printf ("Introduzca la longuitud del lado del cuadrado: \n");
    scanf ("%f", &lado);
    system ("cls");
    return (lado * lado);
  }
  
  float areatrape()
  {
    float basesup, baseinf, alt;
    printf ("Introduzca la longuitud de la base inferior: \n");
    scanf ("%f", &baseinf);
    fflush (stdin);
    printf ("Introduzca la longuitud de la base superior: \n");
    scanf ("%f", &basesup);
    fflush (stdin);
    printf ("Introduzca la altura del trapecio: \n");
    scanf ("%f", &alt);
    fflush (stdin); 
    system ("cls");
    
    return (baseinf * basesup * alt) / 2;
     
  }
   
  float areacir()
  {
    float radio;
    printf ("Introduzca el radio del circulo: \n");
    scanf ("%f", &radio);
    system ("cls");
    return (pow(radio, radio)* PI);
  }
  
  
  float arearectangulo()
  {
    float base, altura;
    printf ("Introduzca la base: \n");
    scanf ("%f", &base);
    fflush (stdin);
    printf ("Introduzca la altura: \n");
    scanf ("%f", &altura);
    fflush (stdin);
    system ("cls");
    
    return base * altura;
  }  
    
  float salir()
  {
    return 0;
  }    
