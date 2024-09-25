#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función muestra una lista de comandos disponibles en el sistema 'µGit',
//              junto con una breve descripción de lo que hace cada comando.

/**
 * Muestra una lista de comandos disponibles en el sistema 'µGit'.
 *
 * Comportamiento:
 *   - Imprime en la consola los comandos que el usuario puede utilizar,
 *     junto con una breve descripción de cada uno.
 *   - Incluye comandos para inicializar un repositorio, mostrar la versión,
 *     establecer configuraciones, crear commits, agregar archivos, y más.
 */
void ugit_help()
{
    printf("Lista de Comandos\n");
    printf("'ugit init'\t\tInicializa un nuevo repositorio de uGit en el directorio actual.\n");
    printf("'ugit version'\tMuestra la version actual del uGit.\n");
    printf("'ugit config'\t\tEstablece configuraciones del uGit.\n");
    printf("\tugit config user.name <Tu Nombre>\n");
    printf("\tugit config user.email <tu@email.com>\n");
    printf("'ugit commit <mensaje>'\tPermite crear commit con un mensaje especifico.\n");
    printf("'ugit add <archivo>'\tAgrega un archivo al area de preparacion.\n");
    printf("'ugit info'\t\tMuestra la informacion del usuario.\n");
    printf("'ugit help'\t\tMuestra la lista de comandos del uGit.\n");
    printf("'ugit log\t\tMuestra la lista de commit's realizados en el repositorio.\n");
    printf("'exit'\t\t\tSale de uGit.\n");
}