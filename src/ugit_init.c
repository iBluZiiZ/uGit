#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función inicializa un nuevo repositorio si no existe uno previamente.
//              Verifica si el usuario tiene configurado nombre y email antes de crear el repositorio.

/**
 * Inicializa un nuevo repositorio de uGit si no existe uno previamente.
 *
 * Parámetros:
 *   - Flag: Puntero a la estructura Flag que indica el estado de configuración del usuario y del repositorio.
 *   - branch: Puntero a la estructura Branch donde se almacenará la información de la rama principal.
 *
 * Retorno:
 *   - Devuelve 0 si no se puede crear el repositorio (por ejemplo, si ya existe o falta configuración).
 *   - Devuelve el índice de la rama creada si el repositorio se inicializa con éxito.
 *   - Devuelve -1 en caso de error inesperado.
 *
 * Comportamiento:
 *   - Comprueba si ya existe un repositorio inicializado y, si es así, informa al usuario.
 *   - Verifica que tanto el nombre como el email del usuario estén configurados antes de proceder.
 *   - Si ambas configuraciones están presentes, inicializa un nuevo repositorio y marca el estado del repositorio como creado.
 */
int ugit_init(Flag* Flag, Branch* branch) {
    // Verifica si ya existe un repositorio
    if (Flag->repositorio == 1) {
        printf("Ya existe un repositorio creado.\n");
        return 0;   // Retorna 0 si ya existe un repositorio
    }

    // Verifica si falta la configuración del usuario
    if (Flag->email == 0 || Flag->name == 0) {
        printf("No se puede crear un repositorio, debido a que falta la configuracion del usuario.\n");
        return 0;   // Retorna 0 si falta configuración
    }

    // Si la configuración es correcta y el repositorio no existe, se inicializa
    if (Flag->email == 1 && Flag->name == 1 && Flag->repositorio == 0) {
        printf("Se ha inicializado un repositorio vacio de uGit.\n");
        int index = create_branch_init(branch); // Crea la rama principal
        Flag->repositorio = 1;  // Marca que el repositorio ha sido creado
        return index;   // Retorna el índice de la rama creada
    }
    return -1;  // Retorna -1 en caso de error inesperado
}
