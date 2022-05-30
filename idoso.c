#include "idoso.h"

#include "cuidador.h"
#include "lista_idoso.h"
#include "lista_cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct st_idoso{
    char* nome;
    unsigned long int latitude;
    unsigned long int longitude;
    float temperatura;
    int queda;
    Lista_idoso* amigos;
    Lista_cuidador* cuidadores;
};

Idoso* Constroi_idoso(char* nome){
    Idoso* idoso = malloc(sizeof(Idoso));
    idoso->nome = malloc(sizeof(char)*strlen(nome)+1);
    strcpy(idoso->nome, nome);
    idoso->latitude = 0;
    idoso->longitude = 0;
    idoso->temperatura = 0;
    idoso->queda = 0;
    idoso->amigos = Inicializa_lista_idoso();
    idoso->cuidadores = Inicializa_lista_cuidador();
    return idoso;
}

void Destroi_idoso(Idoso* idoso){
    free(idoso->nome);
    Destroi_lista_idoso(idoso->amigos);
    Destroi_lista_cuidador(idoso->cuidadores);
    free(idoso);
}

void Insere_amigo_idoso(Idoso* idoso, Idoso* amigo){
    idoso->amigos = Insere_lista_idoso(idoso->amigos, amigo);
}

void Insere_cuidador_idoso(Idoso* idoso, Cuidador* cuidador){
    idoso->cuidadores = Insere_lista_cuidador(idoso->cuidadores, cuidador);
}

char* Retorna_nome_idoso(Idoso* idoso){
    return idoso->nome;
}

unsigned long int Retorna_latitude_idoso(Idoso* idoso){
    return idoso->latitude;
}

unsigned long int Retorna_longitude_idoso(Idoso* idoso){
    return idoso->longitude;
}

float Retorna_temperatura_idoso(Idoso* idoso){
    return idoso->temperatura;
}

int Retorna_queda_idoso(Idoso* idoso){
    return idoso->queda;
}

Lista_idoso* Retorna_amigos_idoso(Idoso* idoso){
    return idoso->amigos;
}

Lista_cuidador* Retorna_cuidadores_idoso(Idoso* idoso){
    return idoso->cuidadores;
}