#include "idoso.h"
#include "lista_idoso.h"
#include "apoio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    if(argc == 1){
        printf("ERRO: Quantidade de leituras nao informada!\n");
        return 1;
    }
    int i, qtd_leituras = atoi(argv[1]);
    
    Apoio* equipe = Inicializa_apoio();
    Carrega_idosos_apoio(equipe);
    Carrega_cuidadores_apoio(equipe);
    Imprime_apoio(equipe);
    
    for(i = 0; i < qtd_leituras; i++){
        Atualiza_idosos_apoio(equipe, i);
    }

    /*
    Idoso* Joao = Constroi_idoso("Joao");
    Idoso* Celso = Constroi_idoso("Celso");
    Idoso* Talles = Constroi_idoso("Talles");
    Idoso* Ivanor = Constroi_idoso("Ivanor");

    Lista_idoso* asilo = Inicializa_lista_idoso();
    asilo = Insere_lista_idoso(asilo, Joao);
    asilo = Insere_lista_idoso(asilo, Talles);
    asilo = Insere_lista_idoso(asilo, Celso);
    Imprime_lista_idoso(asilo);
    asilo = Remove_lista_idoso(asilo, "Joao");
    asilo = Remove_lista_idoso(asilo, "Talles");
    asilo = Remove_lista_idoso(asilo, "Celso");
    asilo = Remove_lista_idoso(asilo, "Joao");
    Imprime_lista_idoso(asilo);

    asilo = Insere_lista_idoso(asilo, Joao);
    Imprime_lista_idoso(asilo);

    Destroi_lista_idoso(asilo);
    Destroi_idoso(Joao);
    Destroi_idoso(Celso);
    Destroi_idoso(Talles);
    Destroi_idoso(Ivanor);
    */
    

    return 0;
}