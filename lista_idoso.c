#include "lista_idoso.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_lista_idoso{
    Idoso* idoso;
    Lista_idoso* prox;
    Lista_idoso* anterior;
};

Lista_idoso* Inicializa_lista_idoso(){
    return NULL;
}

void Destroi_lista_idoso(Lista_idoso* lista){
    if(lista == NULL){
        printf("ERRO: Lista vazia!\n");
        return;
    }
    Lista_idoso* lista_temp = lista;
    Lista_idoso* lista_temp_prox = NULL;
    /*PROCURA O ULTIMO ELEMENTO DA LISTA*/
    while(lista_temp != NULL){
        lista_temp_prox = lista_temp->prox;
        free(lista_temp);
        lista_temp = lista_temp_prox;
    }
}

Lista_idoso* Insere_lista_idoso(Lista_idoso* lista, Idoso* idoso){
    Lista_idoso* nova_lista = malloc(sizeof(Lista_idoso));
    nova_lista->idoso = idoso;
    nova_lista->prox = NULL;
    
    /*CASO A LISTA ESTEJA VAZIA*/
    if(lista == NULL){
        lista = nova_lista;
        lista->anterior = NULL;
    }
    else{
        Lista_idoso* lista_temp = lista;
        
        /*PROCURA O ULTIMO ELEMENTO DA LISTA*/
        while(lista_temp->prox != NULL){
            lista_temp = lista_temp->prox;
        }
        /*INSERE A NOVA LISTA*/
        lista_temp->prox = nova_lista;
        nova_lista->anterior = lista_temp;
    }
    return lista;
}

Lista_idoso* Remove_lista_idoso(Lista_idoso* lista, char* nome){
    Lista_idoso* lista_alvo = Encontra_lista_idoso(lista, nome);
    if(lista_alvo != NULL){
        /*CASO SEJA O UNICO DA LISTA*/
        if(lista_alvo->anterior == NULL && lista_alvo->prox == NULL){
            lista = NULL;
        }
        /*CASO SEJA O PRIMEIRO DA LISTA*/
        else if(lista_alvo->anterior == NULL){
            lista = lista_alvo->prox;
            lista->anterior = NULL;
        }
        /*CASO SEJA O ULTIMO DA LISTA*/
        else if(lista_alvo->prox == NULL){
            (lista_alvo->anterior)->prox = NULL;
        }
        else{
            (lista_alvo->anterior)->prox = lista_alvo->prox;
        }
    }
    free(lista_alvo);
    return lista;
}

Lista_idoso* Encontra_lista_idoso(Lista_idoso* lista, char* nome){
    Lista_idoso* lista_temp = lista;
    while(lista_temp != NULL && strcmp(Retorna_nome_idoso(lista_temp->idoso), nome) != 0){
        lista_temp = lista_temp->prox;
    }
    if(lista_temp == NULL){
        printf("ERRO: Idoso nao encontrado!\n");
        return NULL;
    }
    return lista_temp;
}

Idoso* Retorna_idoso(Lista_idoso* lista){
    return lista->idoso;
}

Lista_idoso* Retorna_lista_amigos_idoso(Idoso* idoso){
    return (Lista_idoso*)Retorna_amigos_idoso(idoso);
}

void Imprime_lista_idoso(Lista_idoso* lista){
    Lista_idoso* lista_temp = lista;
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome_idoso(lista_temp->idoso));
        lista_temp = lista_temp->prox;
    }
    printf("\n");
}

void Imprime_lista_detalhada_idoso(Lista_idoso* lista){
    Lista_idoso* lista_temp = lista;
    while(lista_temp != NULL){
        printf("%s\n", Retorna_nome_idoso(lista_temp->idoso));
        Imprime_lista_idoso(Retorna_lista_amigos_idoso(lista_temp->idoso));
        lista_temp = lista_temp->prox;
    }
    printf("\n");
}