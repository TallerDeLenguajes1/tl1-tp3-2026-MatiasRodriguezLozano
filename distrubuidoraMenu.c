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

void mostrarCompra(int cant, Cliente *c);
float calcularCostoProducto(Producto p);

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
        scanf("%s", buff);

        clientes[i].NombreCliente = malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);

        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));

        for(int k=0; k<clientes[i].CantidadProductosAPedir; k++){
            clientes[i].Productos[k].ProductoID = k;
            clientes[i].Productos[k].Cantidad = 1 + rand() % 10;
            
            strcpy(buff, TiposProductos[rand() % 5]);
            
            clientes[i].Productos[k].TipoProducto = (char*)malloc((strlen(buff)+1) * sizeof(char));

            strcpy(clientes[i].Productos[k].TipoProducto, buff);
           
            clientes[i].Productos[k].PrecioUnitario = 10 + rand() % 91;
        }

    }

    
    mostrarCompra(cantClientes, clientes);

    for (int i = 0; i < cantClientes; i++) {
    free(clientes[i].NombreCliente);

    for (int k = 0; k < clientes[i].CantidadProductosAPedir; k++) {
        free(clientes[i].Productos[k].TipoProducto);
    }

    free(clientes[i].Productos);
}

free(clientes);

    return 0;
}

void mostrarCompra(int cant, Cliente *c){

printf("\n|| LISTA DE COMPRA POR CADA CLIENTE ||\n");

for (int i = 0; i < cant; i++) {
    float totalCliente = 0;

    printf("\n-Cliente %d-", i + 1);
    printf("\n%d-Nombre: %s(ID=%i)", i + 1, c[i].NombreCliente, c[i].ClienteID);
    printf("\n%d-Productos pedidos (%d): ", i + 1, c[i].CantidadProductosAPedir);

    for (int k = 0; k < c[i].CantidadProductosAPedir; k++) {
        float costo = calcularCostoProducto(c[i].Productos[k]);
        totalCliente += costo;

        printf("\n\n  Id del producto: %d", c[i].Productos[k].ProductoID);
        printf("\n  Cantidad: %d", c[i].Productos[k].Cantidad);
        printf("\n  Tipo de producto: %s", c[i].Productos[k].TipoProducto);
        printf("\n  Precio unitario: %.2f", c[i].Productos[k].PrecioUnitario);
        printf("\n  Total producto: %.2f", costo);
    }

    printf("\n\nTotal a pagar del cliente %d: %.2f\n", i + 1, totalCliente);
}

}

float calcularCostoProducto(Producto p) {
    return p.Cantidad * p.PrecioUnitario;
}