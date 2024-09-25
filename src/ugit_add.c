#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_add` agrega un archivo al commit en preparación de la rama especificada.
// Busca un espacio vacío en la lista de archivos del commit actual y almacena el nombre del archivo si encuentra uno disponible.

void ugit_add(Branch* branch, int index, const char* archivo) {
    if (branch == NULL || index < 0 || index >= MAX_SIZE) {
        printf("Error: rama no valida.\n");
        return;
    }
    int num = branch[index].num_commit;
    if (num <= 0 || num >= MAX_SIZE) {
        printf("Error: commit no valido.\n");
        return;
    }

    // Comprobar si el archivo ya está en los archivos del commit actual
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(branch[index].commit[num].archivos[i], archivo) == 0) {
            printf("El archivo '%s' ya fue agregado anteriormente.\n", archivo);
            return;
        }
    }

    // Buscar un espacio vacío para agregar el archivo
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strlen(branch[index].commit[num].archivos[i]) == 0) {
            strncpy(branch[index].commit[num].archivos[i], archivo, MAX_TEXT - 1);
            branch[index].commit[num].archivos[i][MAX_TEXT - 1] = '\0'; // Asegura que esté null-terminado
            branch[index].commit[num].num_archivos++;
            printf("Archivo '%s' agregado al commit en preparacion.\n", archivo);
            return;
        }
    }

    printf("No se pudo agregar el archivo '%s', no hay espacio disponible.\n", archivo);
}

