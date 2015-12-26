typedef struct
{

  char *nombre;
  int notas[4];
  
} alumno;

elemento *clase= NULL;


int main()
{
  alumno *ptro= NULL;
  int opcion, posicion, i=0;
  
  while(1)
  {
    system("cls");
    opcion= menu();
    switch (opcion) {
    
             case 1:  do
                      {
                         printf("posicion: ");
                         scanf(("%d", &posicion); 
                         fflush(stdin);
                         
                      }while(posicion < 1 && posicion > tamano(clase)+1); 
                       
                      if((ptro=nuevo_alumno())==NULL)
                      {
                         printf("No se puede leer alumno\n");
                      }
                      else 
                      {
                         anadir(posicion, ptro, &clase);
                         printf("Se ha anadido uno nuevo \n");
                      }
                      break;     
                       
                  
             case 2:  do
                      {
                         printf("posicion: ");
                         scanf(("%d", &posicion); 
                         fflush(stdin);
                         
                      }while(posicion < 1 && posicion > tamano(clase)+1); 
                      
                      if((ptro=obtener(posicion, clase))==NULL)
                      {
                         printf ("No se ha podido obtener alumno\n");
                      }
                      else  mostar (*ptro);
                      break;
                      
                      
             case 3:  do
                      {
                         printf("posicion: ");
                         scanf(("%d", &posicion); 
                         fflush(stdin);
                         
                      while(posicion < 1 && posicion > tamano(clase)+1); 
                       
                      if(borrar(posicion, clase)==0)
                      {
                          printf("No se puede borrar \n");
                      }
                      else 
                      {
                          printf ("Alumno borrado \n");
                      }
                      break;                    
                      
             
             case 4:  for(i=1; i<=tamano(clase); i++)
                      {
                        if((ptro=obtener(i, clase))==NULL)
                        {
                          printf ("ERROR \n"); break;
                        }
                        else mostrar(ptro*);
                      }
                      break;
                     
                                    
            case 5:  for(i=1; i<=tamano(clase); i++)
                     {     
                       if(!borrar(i, clase))
                       {
                         printf ("ERROR \n"); break
                       }
                       printf ("La clase esta vacia \n");
                       break;
                     }
                    
                                                                         
            case 6:  printf ("La media de la clase es: %g", media(clase));
                     break;
                   
           
            case 0:  exit(1);
      }
      system ("pause");
    }
  }                           



alumno leer_alumno()
{
  alumno a;
  char buffer[80];
  int i;
  printf ("Nombre: ");
  scanf ("%s, buffer);
  
  if((a.nombre= (char*)malloc(strlen(buffer)+1)==NULL)
  {
    printf ("No hay memoria\n");
    exit(1);
  }
  strcpy(a.nombre, buffer);
  
  for (i=0; i<4; i++)
  { 
    do
    {
      printf ("Nota del trimestre %d: ", i);
      scanf("%d", a.notas[i]);
      fflush(stdin);
     } while (a.notas[i] < 0 || a.notas[i] > 10);
   }
   return a;  
}    



alumno *nuevo_alumno()
{
  alumno *pt= NULL;
  if((pt= (alumno*) malloc(sizeof(alumno)))==NULL)
  {
    printf ("No hay memoria \n");
    return NULL;
  }
  *pt= leer_alumno();
  return pt;  
}  


void mostrar(alumno a)
{
  int i, sumatorio= 0;
  
  printf ("Nombre: \t %s \n\n", a.nombre);
  
  for(i=0; i<4; i++)
  {
    printf ("Trimestre %d: %d\n", i, a.notas[i]);
    sumatorio+= a.notas[i];
  }
  printf ("\n media de %s : %g", a.nombre, (float)sumatorio / 4); 
}


float media(elemento *lista)
{
  int posicion=1, j;
  alumno *ptro= NULL;
  float sumatorio= 0;
  
  ptro= (alumno*)obtener(lista, posicion);
  
  while (ptro!= NULL)
  {
    for(j=0; j<4; j++)
    {
      sumatorio+= ptro->notas[j];
    }   
      posicion++;
      ptro=(alumno*) obtener(lista, posicion);
  }
   if(posicion>1)
   {
     return sumatorio / tamano(lista) * 4;
   }
   else return 0;  
}   
