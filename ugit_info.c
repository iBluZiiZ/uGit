#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// La función `ugit_info` muestra la información del usuario (nombre y email) si está configurada. 
// Verifica las banderas para mostrar mensajes apropiados si falta alguna configuración.

void ugit_info(infoUsuario* infoUser, Flag* flag) {
    if (flag->name == 1 && flag->email == 1) {
        printf("Usuario:\t%s\n", infoUser->nombre);
        printf("Email:\t\t%s\n", infoUser->email);
    } else {
        if (flag->name == 1) {
            printf("Usuario:\t%s\n", infoUser->nombre);
            printf("Aún no configuras tu email.\n");
        } else if (flag->email == 1) {
            printf("Aún no configuras tu nombre.\n");
            printf("Email:\t%s\n", infoUser->email);
        } else {
            printf("Aún no tienes configurada tu información.\n");
        }
    }
}