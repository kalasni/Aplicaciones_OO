/* Programa al que se le introducen cadenas de caracteres que se almacenan en una
   matriz y despues se muestran ordenadas alfabeticamente. */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

void alfabet (char *matriz[max]);
char *matriz[max], aux[60];
int cont = 0;

int main()
{
  int i, num;
  puts ("Introduzca el numero de cadenas que quiere introducir:\n");
  scanf ("%d", &num);
  puts ("Introduzca cadenas y termine cada una con enter: \n");

    for (i=0; i<=num; i++)
    {
       gets(aux);
       matriz[i]= (char*) malloc((strlen(aux))* sizeof(char));
       strcpy (matriz[i], aux);
       cont++;
    }

  alfabet (matriz);
  for (i=0; i<cont; i++)
  {
     puts (matriz[i]);
     printf ("\n");
  }
return 0;
}

 void alfabet (char *matriz[cont])
 {

    char *copia;
    int i, a;
    char chg=0;

     for (a=0; a<cont; a++)
     {

      for (i=0; i<cont-1; i++)
      {
           if (strcmp (matriz[i], matriz[i+1]) > 0)
           {
              copia=  matriz[i];
              matriz[i]=  matriz[i+1];
              matriz[i+1]=  copia;
           }
      }
    }
}
