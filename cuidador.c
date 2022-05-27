#include "cuidador.h"

#include <stdio.h>
#include "ponto.h"

struct st_cuidador{
    char* nome;
    ponto* posicoes;
};

struct st_lista_cuidador{
    cuidador* cuidador;
    lista_cuidador* prox;
};

