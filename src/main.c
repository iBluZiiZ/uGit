#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Descripción: Este código implementa una interfaz de línea de comandos para simular comandos básicos de Git en el sistema 'µGit'.
//              El programa acepta comandos del usuario como 'init', 'commit', 'add', 'config', entre otros, y realiza acciones 
//              correspondientes.

int main()
{
    char input[MAX_TEXT] = "";        // Buffer para almacenar la entrada del usuario.
    char prompt[MAX_TEXT];            // Almacena el mensaje de prompt que se mostrará al usuario.
    int index = 0;                    // Índice para rastrear la rama actual.
    infoUsuario infoUser = {"", ""};  // Estructura para almacenar la información del usuario (nombre y email).
    Branch* branch = malloc(sizeof(Branch) * MAX_SIZE); // Arreglo dinámico de ramas.
    Flag flag = {0, 0, 0};            // Inicializa las banderas de configuración del usuario y repositorio.
    
    strcpy(prompt, "uGit> ");         // Establece el prompt para la interfaz de línea de comandos.
    
    // Bucle principal que ejecuta el intérprete de comandos.
    while(1)
    {
        printf("\n%s", prompt);       // Muestra el prompt al usuario.
        fgets(input, sizeof(input), stdin); // Lee la entrada del usuario.
        input[strcspn(input, "\n")] = 0; // Elimina el carácter de nueva línea.

        // Manejo de comandos
        if (strcmp(input, "ugit version") == 0) {
            ugit_version();            // Muestra la versión actual de uGit.
        } else if (strncmp(input, "ugit config user.email", 22) == 0) {
            config_email(&infoUser, input + 23, &flag); // Configura el email del usuario.
        } else if (strncmp(input, "ugit config user.name", 21) == 0) {
            config_nombre(&infoUser, input + 22, &flag); // Configura el nombre del usuario.
        } else if (strcmp(input, "ugit info") == 0) {
            ugit_info(&infoUser, &flag); // Muestra la información del usuario.
        } else if (strcmp(input, "ugit help") == 0) {
            ugit_help();                // Muestra la lista de comandos disponibles.
        } else if (strcmp(input, "ugit init") == 0) {
            index = ugit_init(&flag, branch); // Inicializa un nuevo repositorio.
        } else if (strncmp(input, "ugit commit", 11) == 0) {
            if (flag.repositorio == 1) {
                ugit_commit(branch, input + 12, index); // Crea un nuevo commit con la descripción dada.
            } else {
                printf("No existe un repositorio inicializado.\n"); // Mensaje de error si no hay repositorio.
            }
        } else if (strncmp(input, "ugit add", 8) == 0) {
            if (flag.repositorio == 1) {
                ugit_add(branch, index, input + 9); // Agrega un archivo al commit en preparación.
            } else {
                printf("No existe un repositorio inicializado.\n"); // Mensaje de error si no hay repositorio.
            }
        } else if (strcmp(input, "ugit log") == 0) {
            if (flag.repositorio == 1) {
                ugit_log(branch, &infoUser, index); // Muestra el registro de commits de la rama.
            } else {
                printf("No existe un repositorio inicializado.\n"); // Mensaje de error si no hay repositorio.
            }    
        } else if (strcmp(input, "exit") == 0) {
            printf("Has salido de uGit.\n"); // Mensaje de salida.
            return 0;                    // Sale del programa.
        } else {
            printf("'%s' no es un comando de uGit. Mira 'ugit help'.\n", input); // Mensaje de error para comandos no reconocidos.
        }
    }
    
    return 0; // Retorna 0 al sistema.
}