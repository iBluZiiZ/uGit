#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_commit` crea un nuevo commit en la rama especificada con una descripción dada.
// Verifica argumentos válidos, si el mensaje no está vacío y si no se ha superado el límite de commits antes de 
// almacenar la información del commit.

void ugit_commit(Branch* branch, const char* descripcion, int index) {
    if (branch == NULL || descripcion == NULL) {
        printf("Error: Argumentos invalidos.\n");
        return;
    }
    if (index < 0 || index >= MAX_SIZE) {
        printf("Error: Indice de rama no válido.\n");
        return;
    }
    int num = branch[index].num_commit;
    if (strlen(descripcion) == 0) {
        printf("El mensaje del commit esta vacio.\n");
        return;
    }
    if (num >= MAX_SIZE) {
        printf("Has superado el limite de commits.\n");
        return;
    }
    if (strlen(branch[index].commit[num].archivos[0]) == 0) {
        printf("No hay archivos agregados para este commit.\n");
        return;
    }
    branch[index].commit[num].id = hash(descripcion);
    strncpy(branch[index].commit[num].descripcion, descripcion, MAX_TEXT - 1);
    branch[index].commit[num].descripcion[MAX_TEXT - 1] = '\0';  // Asegurar la terminación de la cadena
    
    printf("\n[main %ld] %s", branch[index].commit[num].id, branch[index].commit[num].descripcion);
    printf("\nHay %d archivos.\n", branch[index].commit[num].num_archivos);
    branch[index].num_commit++;
}