#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Este código implementa una interfaz de línea de comandos para simular comandos básicos de Git en el sistema 'µGit'.
// El programa acepta comandos del usuario como 'init', 'commit', 'add', 'config', entre otros, y realiza acciones 
// correspondientes.

int main()
{
    char input[MAX_TEXT] = "";
    char prompt[MAX_TEXT];
    char nameBranch[MAX_TEXT];
    int index = 0;
    infoUsuario infoUser = {"", ""};
    Branch branch[MAX_SIZE];
    Flag flag = {0, 0, 0, 0};
    strcpy(prompt, "uGit> ");
    printf("\n");
    
    while(strcmp(input,"exit"))
    {
        printf("\n%s", prompt);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = 0;
        if (strcmp(input, "ugit --version") == 0) {
            ugit_version();
        } else if (strncmp(input, "ugit config user.email", 22) == 0) {
            config_email(&infoUser, input + 23, &flag);
        } else if (strncmp(input, "ugit config user.name", 21) == 0) {
            config_nombre(&infoUser, input + 22, &flag);
        } else if (strcmp(input, "ugit info") == 0) {
            ugit_info(&infoUser, &flag);
        } else if (strcmp(input, "ugit help") == 0) {
            ugit_help();
        } else if (strcmp(input, "ugit init") == 0) {
            index = ugit_init(&flag, branch);
        } else if (strncmp(input, "ugit commit", 11 ) == 0) {
            if (flag.repositorio == 1) {
                ugit_commit(branch, input + 12, index);
            }
            else {
                printf("No existe un repositorio inicializado.\n");
            }
        } else if (strncmp(input, "ugit add", 8 ) == 0) {
            if (flag.repositorio == 1) {
                ugit_add(branch, index, input + 9);
            }
            else {
                printf("No existe un repositorio inicializado.\n");
            }
            
        } else if (strcmp(input, "exit") == 0) {
            printf("Has salido de uGit.\n");
        } else {
            printf("'%s' no es un comando de uGit. Mira 'ugit help'.\n", input);
        }
    }
    return 0;
}