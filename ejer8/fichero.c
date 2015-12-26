#include <stdio.h>
#include <stdlib.h>

int main()
{
  int i=0;
  char buffer[100];
  
  FILE *fp= NULL;
  fp= fopen ("texto.txt", "r");
  
  while (!feof(fp))
  {
    buffer[i]= fgetc(fp);
    i++;
  }
  
   buffer[--i]='\0';
   printf ("%s \n", buffer);
   system("pause");
   return 0;
     
}
