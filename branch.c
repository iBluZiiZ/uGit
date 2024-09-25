#include "funciones.h"
// Autor: Oscar Cifuentes y Javier Carcamo
// La función `create_branch_init` inicializa la rama principal llamada "main".
// Calcula un índice hash para la rama, verifica que esté dentro del rango válido y configura el nombre de la rama 
//  y su número de commits.
int create_branch_init(Branch* branch){
    int index = 0;
    const char* nameBranch = "main";
    if (strcmp(nameBranch, "main") == 0) {
        index = hash(nameBranch);
        if (index >= 0 && index < MAX_SIZE) {
            strcpy(branch[index].nombre, nameBranch);
            branch[index].num_commit = 0;
        } else {
            printf("Error: índice fuera de rango para la rama.\n");
            return -1;
        }
    }
    return index;
}