#if !defined(LISTA_IDOSO_H)
#define LISTA_IDOSO_H

#include "idoso.h"

Lista_idoso* Inicializa_lista_idoso();
void Destroi_lista_idoso(Lista_idoso* lista);
Lista_idoso* Insere_lista_idoso(Lista_idoso* lista, Idoso* idoso);
Lista_idoso* Remove_lista_idoso(Lista_idoso* lista, char* nome);
Lista_idoso* Encontra_lista_idoso(Lista_idoso* lista, char* nome);
Idoso* Retorna_idoso(Lista_idoso* lista);
void Imprime_lista_idoso(Lista_idoso* lista);
void Imprime_lista_detalhada_idoso(Lista_idoso* lista);

#endif // LISTA_IDOSO_H