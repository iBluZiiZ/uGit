#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función calcula un valor hash para el nombre de una rama dado.
//              Verifica si el nombre de la rama es NULL, suma los valores ASCII de sus caracteres y retorna un índice
//              dentro de un tamaño fijo (en este caso, 128).

/**
 * Calcula un valor hash para el nombre de una rama.
 *
 * Parámetros:
 *   - nameBranch: Cadena de texto que representa el nombre de la rama.
 *
 * Retorna:
 *   - Un entero sin signo que representa el valor hash del nombre de la rama.
 *   - Si el nombre de la rama es NULL, imprime un error y retorna 0.
 */
unsigned int hash(const char *nameBranch) {
    if (nameBranch == NULL) {
        printf("Error: nombre de la rama es NULL.\n");
        return 0;   // Retorna 0 si el nombre de la rama es NULL
    }
    unsigned int hash_value = 0;    // Inicializa el valor hash
    size_t length = strlen(nameBranch); // Obtiene la longitud del nombre de la rama

    // Suma los valores ASCII de los caracteres del nombre de la rama
    for (size_t i = 0; i < length; i++) {
        hash_value += (hash_value * 31) + nameBranch[i];
    }
    return hash_value % MAX_SIZE;   // Retorna el índice hash dentro del rango permitido
}