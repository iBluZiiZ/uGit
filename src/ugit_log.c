#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Imprime el registro de commits de una rama específica.
//              Esta función itera a través de los commits de una rama y muestra información
//              relevante como el ID del commit, su descripción y los detalles del autor.

/**
 * Imprime el registro de commits de una rama específica.
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch que contiene la información de las ramas y sus commits.
 *   - User: Puntero a la estructura infoUsuario que contiene el nombre y email del autor.
 *   - index: Índice de la rama de la que se quiere mostrar el registro de commits.
 *
 * Comportamiento:
 *   - Si hay commits en la rama especificada, itera sobre cada commit e imprime su ID, descripción,
 *     número de archivos y detalles del autor.
 *   - Si no hay commits, imprime un mensaje indicando que no existen commits en la rama.
 */
void ugit_log(Branch* branch, infoUsuario* User, int index) {
    // Verifica si hay commits en la rama especificada
    if (branch[index].num_commit > 0) {
        for (int i=0; i < branch[index].num_commit; i++) { 
            // Itera a través de cada commit y muestra la información relevante
            printf("\n===========================\n");
            printf("Commit: %ld\n", branch[index].commit[i].id);
            printf("Descripcion: %s\n", branch[index].commit[i].descripcion);
            printf("Archivos: %d\n", branch[index].commit[i].num_archivos);
            printf("Autor: %s <%s>\n", User->nombre, User->email);
        }
    }
    else {
        // Mensaje si no hay commits en la rama
        printf("No existen commit's\n");
    }
}
