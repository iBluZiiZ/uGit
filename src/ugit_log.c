#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Imprime el registro de commits de una rama específica.
// Esta función itera a través de los commits de una rama y muestra información
// relevante como el ID del commit, su descripción y los detalles del autor.

void ugit_log(Branch* branch, infoUsuario* User, int index) {
    if (branch[index].num_commit > 0) {
        for (int i=0; i < branch[index].num_commit; i++) { 
            printf("\n===========================\n");
            printf("Commit: %ld\n", branch[index].commit[i].id);
            printf("Descripcion: %s\n", branch[index].commit[i].descripcion);
            printf("Archivos: %d\n", branch[index].commit[i].num_archivos);
            printf("Autor: %s <%s>\n", User->nombre, User->email);
        }
    }
    else {
        printf("No existen commit's\n");
        printf("%d", branch[index].num_commit);
    }
}
