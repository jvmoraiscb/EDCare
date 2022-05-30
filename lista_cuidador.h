#if !defined(LISTA_CUIDADOR_H)
#define LISTA_CUIDADOR_H

#include "cuidador.h"

Lista_cuidador* Inicializa_lista_cuidador();
void Destroi_lista_cuidador(Lista_cuidador* lista);
Lista_cuidador* Insere_lista_cuidador(Lista_cuidador* lista, Cuidador* cuidador);
Lista_cuidador* Encontra_lista_cuidador(Lista_cuidador* lista, char* nome);
Cuidador* Retorna_cuidador(Lista_cuidador* lista);
void Imprime_lista_cuidador(Lista_cuidador* lista);

#endif // LISTA_CUIDADOR_H
