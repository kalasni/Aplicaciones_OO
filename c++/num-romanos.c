/* Programa al que se le introduce un numero arabigo comprendido
   entre 1 y 4000 y lo convierte a numeros romanos. (16-04-03) */
   
   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
 
 int numero, m, c, d, u;
 char romano[15]={"\0"};
 puts ("Conversion de un numero arabigo a numeros romanos\n");
 puts ("entre 1 y 4000");
 puts ("Introduzca el numero arabigo:");
 scanf ("%d", &numero);
 m = numero / 1000;   // Se obtienen los millares
 numero %= 1000;     // numero toma el resto en centenas
 c = numero / 100;   // se obtienen las centenas
 numero %= 100;      // numero toma el resto en decenas
 d = numero / 10;   // se obtienen las decenas
 u = numero % 10;   // numero toma el resto en unidades 
 
   /* Ahora se forma el numero en romanos */
   
  switch(m) { // millares
         case 1: strcat (romano, "M");
                break;
         case 2: strcat (romano, "MM");
                break;
         case 3: strcat (romano, "MMM");
                break;
   }
   
   switch(c) { //centenas
          case 1: strcat (romano, "C");
                 break;
          case 2: strcat (romano, "CC");
                 break;
          case 3: strcat (romano, "CCC");
                 break;
          case 4: strcat (romano, "CD");
                 break;
          case 5: strcat (romano, "D");
                 break;
          case 6: strcat (romano, "DC");
                 break;
          case 7: strcat (romano, "DCC");
                 break;
          case 8: strcat (romano, "CCM");
                 break;
          case 9: strcat (romano, "CM");
                 break;
    }
    
    switch(d) { // Decenas
           case 1: strcat (romano, "X");
                  break;
           case 2: strcat (romano, "XX");
                  break;
           case 3: strcat (romano, "XXX");
                  break;
           case 4: strcat (romano, "XL");
                  break;
           case 5: strcat (romano, "L");
                  break;
           case 6: strcat (romano, "LX");
                  break;
           case 7: strcat (romano, "LXX");
                  break;
           case 8: strcat (romano, "LXXX");
                  break;
           case 9: strcat (romano, "XC");
                  break;
    }
    
    switch(u) { //unidades
           case 1: strcat (romano, "I");
                  break;
           case 2: strcat (romano, "II");
                  break;
           case 3: strcat (romano, "III");
                  break;
           case 4: strcat (romano, "IV");
                  break;
           case 5: strcat (romano, "V");
                  break;
           case 6: strcat (romano, "VI");
                  break;
           case 7: strcat (romano, "VII");
                  break;
           case 8: strcat (romano, "VIII");
                  break;
           case 9: strcat (romano, "IX");
                  break;
    }                                                                                                                                                                                                                                      
    printf ("El numero en romanos es:  %s \n", romano);
    system ("pause");
    return 0;
  }                                                                       
 
