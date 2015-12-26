/* Programa al que se le introduce la fecha actual y una fecha de nacimiento y 
   calcula los dias vividos desde esta a la actual. (21-04-03) */


#include <stdio.h>
#include <stdlib.h>

int main()
{
 int dia, mes, anyo, edad, a_act, m_act, d_act, m1, a1, d1, d;
 puts ("Introduzca fecha actual: ej: 21 / 07 / 1954 \n");
 scanf ("%d / %d / %d" , &d_act, &m_act, &a_act);
 puts ("Introduzca su fecha de nacimiento: \n");
 scanf ("%d / %d / %d", &dia, &mes, &anyo);
 a1= a_act - anyo;
 m1= m_act - mes;
 d1= d_act - dia;

 if (mes==0 && d1 < 0)
 {
   d=d1;
   a1= a1-1;
   m1=11+m1;
   if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) { d1 = 31 + d;}
   else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
   {
    d1 = 30 + d;
   }
   else
   {
    d1 = 29 + d;
   }
 }
  else
  {
     if (m1 < 0)
     {
      a1 = a1 - 1; m1 = 12 + m1;
     }
     if (d1 < 0)
     {
        m1 = m1 - 1;
        d = d1;
        if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
        {
          d1 = 31 + d;
        }
        else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
          d1 = 30 + d;
        }
        else {d1 = 29 + d;}
     }
  }

edad =(a1*365)+(m1*30)+d1;
printf ("El total de los dias vividos es: %d\n\n", edad);
system("pause");
return 0;
}
 
