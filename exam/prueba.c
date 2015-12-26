 void mostrar(void)
   { 
   
    int antigue, antigue2;
    int conv_salari;
    int sitio, sitio2, aux;
    system ("cls");  // Limpia la pantalla.
   
    printf("           NOMBRE      SALARIO       INCREMENTO \n");
    printf("\n\n");
   
    for (sitio=0; sitio<=max-1; sitio++)
    { 
      for(sitio2= sitio+1; sitio2<max; sitio2++)
      {
         antigue=  atoi(agenda[sitio].antiguedad);
         antigue2= atoi(agenda[sitio2].antiguedad);
         
         if(antigue < antigue2)
         {
           aux= antigue;
           antigue= antigue2;
           antigue2= aux;
         }
      }     
    } 
      if (agenda[sitio].nombre[0])
      { 
        antigue= atoi(agenda[sitio].antiguedad);
           
       
        /* aqui irá el bucle de ordenacion   ?? */
        
        
       if (antigue >= 5 && antigue <=10)
       { 
         printf("EMPLEADO: %d", (sitio+1));
         printf(" %s        %s euros      (+5%)", agenda[sitio].nombre, agenda[sitio].salario);
         printf("\n\n");
       }
       
       if (antigue >=10 && antigue <=20)
       { 
         printf("EMPLEADO: %d", (sitio+1));
         printf(" %s        %s euros      (+10%)", agenda[sitio].nombre, agenda[sitio].salario);
         printf("\n\n");    
       }
       
       if(antigue > 20)
       { 
         printf("EMPLEADO: %d", (sitio+1));    
         printf(" %s        %s euros      (+20%)", agenda[sitio].nombre, agenda[sitio].salario);
         printf("\n\n");    
       } 
       printf("\n");
       fflush(stdin);
      }
     }   
  }   
     
