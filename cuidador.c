#include "cuidador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_cuidador{
    char* nome;
    unsigned long int latitude;
    unsigned long int longitude;
};

Cuidador* Constroi_cuidador(char* nome){
    Cuidador* cuidador = malloc(sizeof(Cuidador));
    cuidador->nome = malloc(sizeof(char)*strlen(nome)+1);
    strcpy(cuidador->nome, nome);
    cuidador->latitude = 0;
    cuidador->longitude = 0;
    return cuidador;
}

void Destroi_cuidador(Cuidador* cuidador){
    free(cuidador->nome);
    free(cuidador);
}

char* Retorna_nome_cuidador(Cuidador* cuidador){
    return cuidador->nome;
}

