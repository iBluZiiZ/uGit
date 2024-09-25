#ifndef FUNCIONES_H
#define FUNCIONES_H

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Este archivo contiene las definiciones de estructuras y la declaración de funciones para el sistema 'µGit'.
//              Se gestionan commits, ramas, configuración de usuario y comandos básicos como 'init', 'commit', 'add', etc.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100    // Máximo número de elementos en un array, como archivos por commit o commits por rama.
#define MAX_TEXT 256    // Máximo tamaño para texto, como descripciones de commits o nombres de archivos.

// Estructura que almacena la información del usuario, como nombre y email.
typedef struct {
    char nombre[50];
    char email[50];
} infoUsuario;

// Estructura que maneja las banderas de configuración de usuario.
typedef struct {
    int name;
    int email;
    int repositorio;
} Flag;

// Estructura que almacena los detalles de un commit, incluyendo una descripción, un ID único y los archivos relacionados.
typedef struct {
    char descripcion[MAX_TEXT];
    long id;
    char archivos[MAX_SIZE][MAX_TEXT];
    int num_archivos;
} Commit;

// Estructura que representa una rama (branch), la cual contiene un nombre y un conjunto de commits.
typedef struct {
    char nombre[MAX_TEXT];
    int num_commit;
    Commit commit[MAX_SIZE];
} Branch;


/**
 * Muestra la versión actual del sistema 'uGit'.
 *
 * Comportamiento:
 *   - Imprime en la consola la versión del software.
 */
void ugit_version();

/**
 * Muestra una lista de comandos disponibles en el sistema 'µGit'.
 *
 * Comportamiento:
 *   - Imprime en la consola los comandos que el usuario puede utilizar,
 *     junto con una breve descripción de cada uno.
 *   - Incluye comandos para inicializar un repositorio, mostrar la versión,
 *     establecer configuraciones, crear commits, agregar archivos, y más.
 */
void ugit_help();

/**
 * Configura el nombre del usuario en la estructura `infoUsuario`.
 *
 * Parámetros:
 *   - infoUser: Puntero a la estructura infoUsuario donde se almacenará el nombre.
 *   - nombre: Cadena de texto que representa el nombre del usuario a configurar.
 *   - Flag: Puntero a la estructura Flag que se actualizará al marcar el nombre como configurado.
 *
 * Comportamiento:
 *   - Copia el nombre proporcionado en la estructura infoUser.
 *   - Actualiza la bandera correspondiente a "name" para indicar que se ha configurado el nombre.
 */
void config_nombre(infoUsuario* infoUser, const char* nombre, Flag* Flag);

/**
 * Configura el email del usuario en la estructura `infoUsuario`.
 *
 * Parámetros:
 *   - infoUser: Puntero a la estructura infoUsuario donde se almacenará el email.
 *   - email: Cadena de texto que representa el email del usuario a configurar.
 *   - Flag: Puntero a la estructura Flag que se actualizará al marcar el email como configurado.
 *
 * Comportamiento:
 *   - Copia el email proporcionado en la estructura infoUser.
 *   - Actualiza la bandera correspondiente a "email" para indicar que se ha configurado el email.
 */
void config_email(infoUsuario* infoUser, const char* email, Flag* Flag);

/**
 * Muestra la información del usuario, incluyendo nombre y email, si están configurados.
 *
 * Parámetros:
 *   - infoUser: Puntero a la estructura infoUsuario que contiene el nombre y email del usuario.
 *   - flag: Puntero a la estructura Flag que indica si el nombre y el email están configurados.
 *
 * Comportamiento:
 *   - Si ambos, nombre y email, están configurados, imprime la información del usuario.
 *   - Si falta alguna configuración, imprime un mensaje apropiado indicando qué información no está disponible.
 */
void ugit_info(infoUsuario* infoUser, Flag* Flag);

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
int ugit_init(Flag* Flag, Branch* branch);

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
int create_branch_init(Branch* branch);

/**
 * Calcula un valor hash para el nombre de una rama.
 *
 * Parámetros:
 *   - nameBranch: Cadena de texto que representa el nombre de la rama.
 *
 * Retorna:
 *   - Un entero sin signo que representa el valor hash del nombre de la rama.
 *   - Si el nombre de la rama es NULL, imprime un error y retorna 0.
 */
unsigned int hash(const char *nameBranch);

/**
 * Crea un nuevo commit en la rama especificada con una descripción dada.
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch que contiene la información de la rama.
 *   - descripcion: Cadena de texto que representa la descripción del commit.
 *   - index: Índice de la rama en la que se desea crear el commit.
 *
 * Comportamiento:
 *   - Verifica si los argumentos son válidos y si el mensaje del commit no está vacío.
 *   - Comprueba si se ha superado el límite de commits permitidos.
 *   - Almacena la información del commit en la rama especificada.
 *   - Imprime mensajes de error si no se puede crear el commit.
 */
void ugit_commit(Branch* branch, const char* descripcion, int index);

/**
 * Agrega un archivo al commit en preparación de la rama especificada.
 *
 * Parámetros:
 *   - branch: Puntero a la estructura Branch que contiene la información de la rama.
 *   - index: Índice de la rama en la que se desea agregar el archivo.
 *   - archivo: Cadena de texto que representa el nombre del archivo a agregar.
 *
 * Comportamiento:
 *   - Verifica si la rama y el índice son válidos.
 *   - Comprueba si el archivo ya está presente en el commit actual.
 *   - Busca un espacio vacío en la lista de archivos del commit y lo agrega.
 *   - Imprime mensajes de error si no se puede agregar el archivo.
 */
void ugit_add(Branch* branch, int index, const char* archivo);

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
void ugit_log(Branch* branch, infoUsuario* User, int index);

#endif