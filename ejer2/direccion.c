/* Programa que utiliza variables para introducir valores como nombre,
   dirección y telefono y despues las muestra mediante la funcion 
   printf.    (08-04-03) */

#include <stdio.h>
#include <stdlib.h>
char nombre, direccion, telefono;
int main()
{
char nombre[]= "Vicent";
char direccion[]= "C/Sin Nombre";
char telefono[]= "584939034";
printf ("%s\n" "%s\n" "%s\n", nombre, direccion, telefono);
system ("PAUSE");
return 0;
}
