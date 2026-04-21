#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
    char * nombre;
    } typedef Persona;
void mostrarPersonas(Persona * persona);

void mostrarPersonas(Persona *persona);
void BuscaNombrePorId(Persona *personas, int cantidad, int id);
int BuscaNombrePorPalabra(Persona *personas, int cantidad, char *palabra);


int main (){
    char buff[30];
    Persona * usuarios;
    char palabra[30];
    int cantidad = 5;
    int id;
    usuarios = (Persona*)malloc(5 * sizeof(Persona));

    for (int i=0 ; i<5 ; i++) {
        printf("Ingrese nombre de usuario: ");
        scanf("%s", buff);
        (usuarios + i)->nombre = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(((usuarios+i)->nombre), buff);
    }
    
    mostrarPersonas(usuarios);
 
    printf("\nIngrese ID a buscar: ");
    scanf("%d", &id);
    BuscaNombrePorId(usuarios, cantidad, id);

    printf("\nIngrese palabra clave: ");
    scanf("%s", palabra);

    int resultado = BuscaNombrePorPalabra(usuarios, cantidad, palabra);

    if (resultado != -1) {
        printf("Nombre encontrado: %s\n", usuarios[resultado].nombre);
    } else {
        printf("No se encontró ninguna coincidencia\n");
    }

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

int BuscaNombrePorPalabra(Persona *personas, int cantidad, char *palabra) {
    for (int i = 0; i < cantidad; i++) {
        if (strstr(personas[i].nombre, palabra) != NULL) {
            return i;
        }
    }
    return -1;
}