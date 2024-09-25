#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función crea un nuevo commit en la rama especificada con una descripción dada.
//              Verifica argumentos válidos, si el mensaje no está vacío y si no se ha superado el límite de commits antes de 
//              almacenar la información del commit.

/**
 * Crea un nuevo commit en la rama especificada con una descripción dada.
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch que contiene la información de la rama.
 *   - descripcion: Cadena de texto que representa la descripción del commit.
 *   - index: Índice de la rama en la que se desea crear el commit.
 *
 * Comportamiento:
 *   - Verifica si los argumentos son válidos y si el mensaje del commit no está vacío.
 *   - Comprueba si se ha superado el límite de commits permitidos.
 *   - Almacena la información del commit en la rama especificada.
 *   - Imprime mensajes de error si no se puede crear el commit.
 */
void ugit_commit(Branch* branch, const char* descripcion, int index) {
    // Verifica si los argumentos son válidos
    if (branch == NULL || descripcion == NULL) {
        printf("Error: Argumentos invalidos.\n");
        return; // Salida en caso de error
    }

    // Verifica si el índice de la rama es válido
    if (index < 0 || index >= MAX_SIZE) {
        printf("Error: Indice de rama no válido.\n");
        return; // Salida en caso de error
    }

    // Verifica si el mensaje del commit está vacío
    int num = branch[index].num_commit;
    if (strlen(descripcion) == 0) {
        printf("El mensaje del commit esta vacio.\n");
        return; // Salida en caso de error
    }

    // Verifica si se ha superado el límite de commits
    if (num >= MAX_SIZE) {
        printf("Has superado el limite de commits.\n");
        return; // Salida en caso de error
    }

    // Verifica si hay archivos agregados para este commit
    if (strlen(branch[index].commit[num].archivos[0]) == 0) {
        printf("No hay archivos agregados para este commit.\n");
        return; // Salida en caso de error
    }

    // Almacena el ID y la descripción del commit
    branch[index].commit[num].id = hash(descripcion);
    strncpy(branch[index].commit[num].descripcion, descripcion, MAX_TEXT - 1);
    branch[index].commit[num].descripcion[MAX_TEXT - 1] = '\0';  // Asegura la terminación de la cadena

    // Imprime información del commit creado
    printf("\n[main %ld] %s", branch[index].commit[num].id, branch[index].commit[num].descripcion);
    printf("\nHay %d archivos.\n", branch[index].commit[num].num_archivos);
    branch[index].num_commit++; // Incrementa el número de commits en la rama
}