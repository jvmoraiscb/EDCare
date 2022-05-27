#include "ponto.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct st_ponto{
    unsigned long int x;
    unsigned long int y;
};

ponto Constroi_ponto(unsigned long int x, unsigned long int y){
    ponto a;
    a.x = x;
    a.y = y;
    return a;
}

ponto* Constroi_vetor_ponto(int tamanho){
    ponto* a = malloc(sizeof(ponto)*tamanho);
    return a;
}

void Libera_vetor_ponto(ponto* a){
    free(a);
}

double Retorna_distancia_entre_ponto(ponto a, ponto b){
    double distancia;
    distancia = sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
    return distancia;
}
