#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `create_branch_init` inicializa la rama principal llamada "main".
// Calcula un índice hash para la rama, verifica que esté dentro del rango válido y configura el nombre de la rama 
//  y su número de commits.

int create_branch_init(Branch* branch){
    const char* nameBranch = "main";
    int index = hash(nameBranch);
    if (index < 0 || index >= MAX_SIZE) {
        printf("Error: Indice fuera de rango para la rama.\n");
        return -1;
    }
    if (strlen(branch[index].nombre) > 0) {
        printf("Error: la rama '%s' ya existe.\n", branch[index].nombre);
        return -1;
    }
    strcpy(branch[index].nombre, nameBranch);
    branch[index].num_commit = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        branch[index].commit[i].id = -1; // Inicializa ID como inválido
        strcpy(branch[index].commit[i].descripcion, ""); // Inicializa la descripción
        for (int j = 0; j < MAX_SIZE; j++) {
            strcpy(branch[index].commit[i].archivos[j], ""); // Inicializa archivos
        }
    }
    return index;
}