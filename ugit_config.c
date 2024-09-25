#include "funciones.h"
// Autor: Oscar Cifuentes y Javier Carcamo
// La función `config_nombre` configura el nombre del usuario en la estructura `infoUsuario`, actualizando 
// la bandera correspondiente y marcando el repositorio como inicializado si el nombre y el email están configurados.

// La función `config_email` configura el email del usuario en la estructura `infoUsuario`, actualizando la
// bandera correspondiente y marcando el repositorio como inicializado si el nombre y el email están configurados.

void config_nombre(infoUsuario* infoUser, const char* nombre, Flag* Flag)
{
    strncpy(infoUser->nombre, nombre, sizeof(infoUser->nombre) - 1);
    infoUser->nombre[sizeof(infoUser->nombre) - 1] = '\0';
    printf("Nombre: %s\n", infoUser->nombre);
    Flag->name = 1;
    if (Flag->name == 1 && Flag->email == 1) {
        Flag->repositorio = 1;
    } else{}
}

void config_email(infoUsuario* infoUser, const char* email, Flag* Flag)
{
    strncpy(infoUser->email, email, sizeof(infoUser->email) - 1);
    infoUser->email[sizeof(infoUser->email) - 1] = '\0';
    printf("Email: %s\n", infoUser->email);
    Flag->email = 1;
    if (Flag->name == 1 && Flag->email == 1) {
        Flag->repositorio = 1;
    } else{}
}