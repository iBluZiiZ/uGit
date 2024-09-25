#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `hash` calcula un valor hash para el nombre de una rama dado.
// Verifica si el nombre de la rama es NULL, suma los valores ASCII de sus caracteres y retorna un índice dentro
// de un tamaño fijo (en este caso, 128).

unsigned int hash(const char *nameBranch) {
    if (nameBranch == NULL) {
        printf("Error: nombre de la rama es NULL.\n");
        return 0;
    }
    unsigned int hash_value = 0;
    size_t length = strlen(nameBranch);
    for (size_t i = 0; i < length; i++) {
        hash_value += (hash_value * 31) + nameBranch[i];
    }
    return hash_value % MAX_SIZE;
}