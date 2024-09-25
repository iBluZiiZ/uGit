#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Esta función muestra la información del usuario (nombre y email) si está configurada. 
//              Verifica las banderas para mostrar mensajes apropiados si falta alguna configuración.

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
void ugit_info(infoUsuario* infoUser, Flag* flag) {
    // Verifica si el nombre y el email están configurados
    if (flag->name == 1 && flag->email == 1) {
        printf("Usuario:\t%s\n", infoUser->nombre);
        printf("Email:\t\t%s\n", infoUser->email);
    } else {
        // Si solo el nombre está configurado
        if (flag->name == 1) {
            printf("Usuario:\t%s\n", infoUser->nombre);
            printf("Aún no configuras tu email.\n");
        }
        // Si solo el email está configurado
        else if (flag->email == 1) {
            printf("Aún no configuras tu nombre.\n");
            printf("Email:\t%s\n", infoUser->email);
        } 
        // Si no hay configuraciones
        else {
            printf("Aún no tienes configurada tu información.\n");
        }
    }
}