#include "idoso.h"
#include "lista_idoso.h"
#include "apoio.h"
#include "cuidador.h"
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
    //Imprime_apoio(equipe);
    
    for(i = 0; i < qtd_leituras; i++){
        Atualiza_idosos_apoio(equipe, i);
        Atualiza_cuidadores_apoio(equipe, i);
        printf("---\n");
        Verifica_idosos_apoio(equipe);
        printf("---\n");
    }
    return 0;
}