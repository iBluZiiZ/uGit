#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_commit` crea un nuevo commit en la rama especificada con una descripción dada.
// Verifica argumentos válidos, si el mensaje no está vacío y si no se ha superado el límite de commits antes de 
// almacenar la información del commit.

void ugit_commit(Branch* branch, const char* descripcion, int index) {
    if (branch == NULL || descripcion == NULL) {
        printf("Error: Argumentos inválidos.\n");
        return;
    }
    int num = branch[index].num_commit;
    if (strlen(descripcion) == 0) {
        printf("El mensaje del commit está vacío.\n");
        return;
    }
    if (num >= MAX_SIZE) {
        printf("Has superado el límite de commits.\n");
        return;
    }
    branch[index].commit[num].id = hash(descripcion);
    strncpy(branch[index].commit[num].descripcion, descripcion, MAX_TEXT - 1);
    branch[index].commit[num].descripcion[MAX_TEXT - 1] = '\0';  // Asegurar la terminación de la cadena
    branch[index].num_commit++;
}