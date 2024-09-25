#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función agrega un archivo al commit en preparación de la rama especificada.
//              Busca un espacio vacío en la lista de archivos del commit actual y almacena el nombre del archivo
//              si encuentra uno disponible.

/**
 * Agrega un archivo al commit en preparación de la rama especificada.
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch que contiene la información de la rama.
 *   - index: Índice de la rama en la que se desea agregar el archivo.
 *   - archivo: Cadena de texto que representa el nombre del archivo a agregar.
 *
 * Comportamiento:
 *   - Verifica si la rama y el índice son válidos.
 *   - Comprueba si el archivo ya está presente en el commit actual.
 *   - Busca un espacio vacío en la lista de archivos del commit y lo agrega.
 *   - Imprime mensajes de error si no se puede agregar el archivo.
 */
void ugit_add(Branch* branch, int index, const char* archivo) {
    // Verifica si la rama es válida y si el índice está dentro de límites
    if (branch == NULL || index < 0 || index >= MAX_SIZE) {
        printf("Error: rama no valida.\n");
        return; // Salida en caso de error
    }

    int num = branch[index].num_commit; // Obtiene el número de commits en la rama

    // Verifica si el número de commits es válido
    if (num <= 0 || num >= MAX_SIZE) {
        printf("Error: commit no valido.\n");
        return; // Salida en caso de error
    }

    // Comprobar si el archivo ya está en los archivos del commit actual
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strcmp(branch[index].commit[num].archivos[i], archivo) == 0) {
            printf("El archivo '%s' ya fue agregado anteriormente.\n", archivo);
            return; // Salida si el archivo ya fue agregado
        }
    }

    // Buscar un espacio vacío para agregar el archivo
    for (int i = 0; i < MAX_SIZE; i++) {
        if (strlen(branch[index].commit[num].archivos[i]) == 0) {
            strncpy(branch[index].commit[num].archivos[i], archivo, MAX_TEXT - 1);
            branch[index].commit[num].archivos[i][MAX_TEXT - 1] = '\0'; // Asegura que esté null-terminado
            branch[index].commit[num].num_archivos++;   // Incrementa el número de archivos en el commit
            printf("Archivo '%s' agregado al commit en preparacion.\n", archivo);
            return; // Salida exitosa
        }
    }
    
    // Mensaje de error si no hay espacio disponible
    printf("No se pudo agregar el archivo '%s', no hay espacio disponible.\n", archivo);
}

