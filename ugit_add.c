#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_add` agrega un archivo al commit en preparación de la rama especificada.
// Busca un espacio vacío en la lista de archivos del commit actual y almacena el nombre del archivo si encuentra uno disponible.

void ugit_add(Branch* branch, int index, const char* archivo) {
    int num = branch[index].num_commit;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strlen(branch[index].commit[num].archivos) == 0) {
            strncpy(branch[index].commit[num].archivos, archivo, MAX_TEXT);
            printf("Archivo '%s' agregado al commit en preparación.\n", archivo);
            return;
        }
    }
}