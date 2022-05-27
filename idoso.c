#include "idoso.h"

#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"
#include "cuidador.h"

struct st_idoso{
    char* nome;
    ponto* posicoes;
    float* temperaturas;
    int* quedas;
    lista_idoso* amigos;
    lista_cuidador* cuidadores;
};

struct st_lista_idoso{
    idoso* idoso;
    lista_idoso* prox;
};



