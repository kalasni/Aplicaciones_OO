/* Programa para calcular la suma, resta y producto de dos matrices del mismo orden,
   (las dos tienen que tener el mismo numero de filas y columnas). También muestra
   la traspuesta de la primera matriz. (02-05-03) */
   
#include <matrices.h>


int main()
{

 

 do {
 printf ("======================================\n");
 printf ("Elija el calculo que quiere realizar: \n");
 printf ("======================================\n");
 printf ("\n");
 printf ("(1) - SUMA \n");
 printf ("(2) - RESTA \n");
 printf ("(3) - MULTIPLICACION \n");
 printf ("(4) - MOSTRAR LA TRASPUESTA DE LA MATRIZ 1 \n");
 printf ("(5) - SALIR \n");
 printf ("\n");
 
 scanf ("%d", &num);

 switch (num) {
          

        case 1:   entr_datos();
                  suma (f1, c1, f2, c2, mat1, mat2, resul);
                  break;  
          
        case 2:   entr_datos();
                  resta (f1, c1, f2, c2, mat1, mat2, resul);
                  break;

        case 3:   entr_datos();
                  multip (f1, c1, f2, c2, mat1, mat2, resul);
                  break;

        case 4:   entr_datos2();
                  traspues (f1, c1, mat1);
                  break; 
                  
        case 5: 
                  system ("pause");
                  return 0; 
  }               
                           
 } while (num < 6);
}


