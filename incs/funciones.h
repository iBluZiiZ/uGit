#ifndef FUNCIONES_H
#define FUNCIONES_H

// Autor: Oscar Cifuentes y Javier Carcamo
// Este archivo contiene las definiciones de estructuras y la declaración de funciones para el sistema 'µGit'. 
// Se gestionan commits, ramas, configuración de usuario y comandos básicos como 'init', 'commit', 'add', etc.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 100    // Variable para Maximo Tamano
#define MAX_TEXT 256    // Maximo Texto

typedef struct {
    char nombre[50];
    char email[50];
} infoUsuario;

typedef struct {
    int name;
    int email;
    int repositorio;
} Flag;

typedef struct {
    char descripcion[MAX_TEXT];
    long id;
    char archivos[MAX_SIZE][MAX_TEXT];
    int num_archivos;
} Commit;

typedef struct {
    char nombre[MAX_TEXT];
    int num_commit;
    Commit commit[MAX_SIZE];
} Branch;

void ugit_version();
void ugit_help();
void config_nombre(infoUsuario* infoUser, const char* nombre, Flag* Flag);
void config_email(infoUsuario* infoUser, const char* email, Flag* Flag);
void ugit_info(infoUsuario* infoUser, Flag* Flag);
int ugit_init(Flag* Flag, Branch* branch);
int create_branch_init(Branch* branch);
unsigned int hash(const char *nameBranch);
void ugit_commit(Branch* branch, const char* descripcion, int index);
void ugit_add(Branch* branch, int index, const char* archivo);
void ugit_log(Branch* branch, infoUsuario* User, int index);
#endif