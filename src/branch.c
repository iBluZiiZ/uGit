#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función inicializa la rama principal llamada "main".
//              Utiliza un hash para generar un índice único de la rama, verifica si el índice es válido y si la rama ya existe.
//              Si la rama no existe, la inicializa con nombre y con un conjunto vacío de commits.

/**
 * Inicializa la rama principal llamada "main".
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch donde se almacenará la nueva rama inicializada.
 * 
 * Retorna:
 *   - El índice de la rama en caso de éxito.
 *   - -1 si ocurre un error, como si el índice está fuera de rango o la rama ya existe.
 */
int create_branch_init(Branch* branch){
    const char* nameBranch = "main";    // Nombre de la rama principal, en este caso 'main'. 
    int index = hash(nameBranch);       // Calcula el índice hash para la rama

    // Verifica si el índice está dentro de los límites del array
    if (index < 0 || index >= MAX_SIZE) {
        printf("Error: Indice fuera de rango para la rama.\n");
        return -1; // Retorna error si el índice no es válido
    }

    // Verifica si la rama ya existe
    if (strlen(branch[index].nombre) > 0) {
        printf("Error: la rama '%s' ya existe.\n", branch[index].nombre);
        return -1;
    }
    
    // Configura el nombre de la nueva rama y su número de commits
    strcpy(branch[index].nombre, nameBranch);
    branch[index].num_commit = 0;

    // Inicializa todos los commits de la rama
    for (int i = 0; i < MAX_SIZE; i++) {
        branch[index].commit[i].id = -1; // ID inicial inválido
        strcpy(branch[index].commit[i].descripcion, ""); // Descripcion vacía

        // Inicializa los nombres de los archivos en el commit
        for (int j = 0; j < MAX_SIZE; j++) {
            strcpy(branch[index].commit[i].archivos[j], ""); // Inicializa archivos vacíos
        }
    }
    return index; // Retorna el índice de la rama principal creada
}