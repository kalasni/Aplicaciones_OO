


typedef struct tpila
{
  void *dato;
  struct tpila *siguiente;

}datopila;


int main()
{
  char valor[10];
  datopila *p= NULL;
  int opcion;
  
  for(;;)
  {
    opcion= menu();
     
         switch (opcion) {
            
                case 1:  
                        iniciar_pila(&pila)
            
                case 2:  
                        apilar(&pila, valor);
                    
                    
                case 3: 
                        desapilar(&pila);
                    
                    
                case 4: return 0;
                    
        }
     }                 
 }
 
 
void iniciar_pila(datopila **pila)
{
   datopila *cima= *pila;
   datopila *q= *pila;
   
   if(pilavacia(cima))
   {
     return;
   }
   
   while (cima!=NULL)
   {
     q= cima;
     cima= cima->siguiente;
     free(q);
   }
   *pila= NULL;
 }        
  
  
  
 void apilar(datopila **pila, void *v)
 {
   datopila *q= NULL;
   q= (datopila*)malloc(sizeof(datopila))
   if(!q)
   {
     exit(1);
   }
   q->dato= v;
   q->siguiente= *pila;
   *pila= q;
  
 }   
  
 
 void *desapilar(datopila **pila)
 {
   datopila *cima= *pila;
   void *elementos= NULL;
   
   if(pilavacia(cima)) 
   {
     return NULL;
   }
   elemento= cima->dato;
   cima= cima->siguiente;
   *pila= cima;
   free(cima);  
   return elemento;
 }    


int pilavacia(datopila *pila);
{
      
        
  int menu()
  {
     int opc;
     
     printf (" MENU DE PROGRAMA PILA \n");
     printf (" (1) - INICIAR PILA \n");
     printf (" (2) - APILAR DATO EN LA PILA \n");
     printf (" (3) - DESAPILAR DATO DE LA PILA \n");
     printf (" (4) - SALIR DEL PROGRAMA \n");
      
     scanf ("%d", &opc);
     return opc; 
     
  }  

