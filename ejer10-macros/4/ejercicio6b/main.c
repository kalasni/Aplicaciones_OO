

int main(int argc, char *argv[])
{
    int *lista= NULL;
    int opcion, elemento, posicion;
    printf("Introduce la capacidad de la lista : ");
    scanf("%d",&TAMANNO);
    lista= (int *)malloc(TAMANNO * sizeof(int)); // asigno el espacio a la lista
    if (lista== NULL)
    {
        printf("No hay suficiente espacio en memoria");
        return -1;
    }
    
    while(1)
    {
    do
    {
        system("cls");
        Menu();
        printf("\n\nElegir una opcion: ");
        scanf("%d",&opcion);
    }
    while( opcion<1 || opcion>5);
    
    switch(opcion)
    {
        case 1: InicializarLista(lista);
                system("PAUSE");
                break;
        case 2: VerLista(lista);
                system("PAUSE");
                break;
        case 3: printf("introduce el elemento que desea insertar: ");
                scanf("%d", &elemento);
                InsertarElemento(lista, elemento);
                system("PAUSE");
                break;
        case 4: printf("introduce la posicion del elemento que desea borrar : ");
                scanf("%d", &posicion);
                BorrarElemento(lista, posicion);
                system("PAUSE");
                break;
        case 5: exit(0);
    }
    }
        
  	
  return 0;
}

void Menu()
{
    printf("\n\t\tOPCIONES \n");
    printf("1.\tInicializar Array: \n");
    printf("2.\tVer Array: \n");
    printf("3.\tAñadir Elemento: \n");
    printf("4.\tEliminar elemento: \n");
    printf("5.\tSalir: ");
}
