#include "funciones.h"

// Autor: Oscar Cifuentes y Javier Carcamo
// Fecha: 24-09-2024
// Descripción: Estas funciones configuran el nombre y el email del usuario en la estructura `infoUsuario`,
//              actualizando la bandera correspondiente y marcando el repositorio como inicializado si el 
//              nombre y el email están configurados.

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
void config_nombre(infoUsuario* infoUser, const char* nombre, Flag* Flag)
{
    strncpy(infoUser->nombre, nombre, sizeof(infoUser->nombre) - 1);
    infoUser->nombre[sizeof(infoUser->nombre) - 1] = '\0';  // Asegura que la cadena esté null-terminada
    printf("Nombre: %s\n", infoUser->nombre);
    Flag->name = 1; // Marca que el nombre ha sido configurado
}

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
void config_email(infoUsuario* infoUser, const char* email, Flag* Flag)
{
    strncpy(infoUser->email, email, sizeof(infoUser->email) - 1);   
    infoUser->email[sizeof(infoUser->email) - 1] = '\0';    // Asegura que la cadena esté null-terminada
    printf("Email: %s\n", infoUser->email);
    Flag->email = 1;    // Marca que el email ha sido configurado
}  