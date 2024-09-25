#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_init` inicializa un nuevo repositorio si no existe uno previamente.
// Verifica si el usuario tiene configurado nombre y email antes de crear el repositorio.

int ugit_init(Flag* Flag, Branch* branch) {
    if (Flag->repositorio == 1) {
        printf("Ya existe un repositorio creado.\n");
        return 0;
    }
    if (Flag->email == 0 || Flag->name == 0) {
        printf("No se puede crear un repositorio, debido a que falta la configuracion del usuario.\n");
        return 0;
    }
    if (Flag->email == 1 && Flag->name == 1 && Flag->repositorio == 0) {
        printf("Se ha inicializado un repositorio vacio de uGit.\n");
        int index = create_branch_init(branch);
        Flag->repositorio = 1;
        return index;
    }
    return -1;
}
