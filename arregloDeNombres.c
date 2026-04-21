#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char * nombre;
    } typedef Persona;
void mostrarPersonas(Persona * persona);

int main (){
    char buff[30];
    Persona * usuarios;
    usuarios = (Persona*)malloc(5 * sizeof(Persona));

    for (int i=0 ; i<5 ; i++) {
        printf("Ingrese nombre de usuario: ");
        scanf("%s", buff);
        (usuarios + i)->nombre = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(((usuarios+i)->nombre), buff);
    }
    
    mostrarPersonas(usuarios);
    
    for (int i = 0; i < 5; i++) {
        free((usuarios + i)->nombre);
    }
    free(usuarios);

    return 0;
}


void mostrarPersonas(Persona * persona){
     for (int i=0 ; i<5 ; i++) {
        printf("%s\n", (persona + i)->nombre);
    }
}
void BuscaNombrePorId(Persona *personas, int cantidad, int id) {
    if (id >= 0 && id < cantidad) {
        printf("Nombre encontrado: %s\n", personas[id].nombre);
    } else {
        printf("no se encontró el valor buscado\n");
    }
}