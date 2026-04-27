#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *TiposProductos[]={"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

struct {
 int ProductoID; //Numerado en ciclo iterativo
 int Cantidad; // entre 1 y 10
 char *TipoProducto; // Algún valor del arreglo TiposProductos
 float PrecioUnitario; // entre 10 - 100
}typedef Producto;

struct {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable // “CantidadProductosAPedir”
}typedef Cliente;

void mostrarMenu (){

    printf("\n|| Menu || \n\nSeleccione cantidad de clientes:");
    
}

void mostrarCompra();

int main(){
    int cantClientes;
    char buff[50];
    srand(time(NULL));

    mostrarMenu();
    scanf("%d", &cantClientes);
    while (cantClientes>5 || cantClientes <=0){
        printf ("\nError: Maxima cantidad de clientes: 5 (cinco).\nNo puede cargar un valor menor o igual a cero.\n");
        mostrarMenu();
        scanf("%d", &cantClientes); 
    }

    Cliente * clientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));    
    
    for(int i=0; i<cantClientes; i++){
        clientes[i].ClienteID = i;
        printf("\nIngrese el nombre del cliente %d: ", i+1);
        scanf("%s", &buff);

        clientes[i].NombreCliente = (char*)malloc(strlen(buff) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);

        clientes[i].CantidadProductosAPedir = 1 + rand(5);
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for(int k=0; k<clientes[i].CantidadProductosAPedir; k++){
            clientes[i].Productos[k].ProductoID = k;
            clientes[i].Productos[k].Cantidad = 1 + rand(10);
            
            strcpy(clientes[i].Productos[k].TipoProducto, TiposProductos[rand(5)]);
           
            clientes[i].Productos[k].PrecioUnitario = 10 + rand(91);
        }

    }

    return 0;
}

void mostrarCompra(){

    printf("Mostrar compra");



}