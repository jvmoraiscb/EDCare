#include "apoio.h"

#include "idoso.h"
#include "lista_idoso.h"
#include "cuidador.h"
#include "lista_cuidador.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct st_apoio{
    Lista_idoso* idosos;
    Lista_cuidador* cuidadores;
};

Apoio* Inicializa_apoio(){
    Apoio* apoio = malloc(sizeof(Apoio));
    apoio->idosos = Inicializa_lista_idoso();
    apoio->cuidadores = Inicializa_lista_cuidador();
    return apoio;
}

void Carrega_apoio(Apoio* apoio){
    FILE* file_apoio = fopen("Entrada/apoio.txt", "r");
    char apoio_txt[30][1000];
    int i0=0;
    /*ARMAZENA O ARQUIVO EM UM VETOR DE STRINGS*/
    while(fscanf(file_apoio, "%999s", apoio_txt[i0]) == 1){
        i0++;
    };
    fclose(file_apoio);
    int j0=0;
    for(j0 = 0; j0 < i0; j0++){
        printf("%s\n", apoio_txt[j0]);
    }
    /*CONSTROI OS IDOSOS E PREENCHE A LISTA_IDOSO*/
    char *string[1000];   
    char delimit[]=" ;\n"; // OS NOMES ESTAO SEPARADOS POR ';' E O ULTIMO POR '\n'
    int i = 0, j = 0;                                  
    string[i]=strtok(apoio_txt[0],delimit); // A PRIMEIRA STRING DEFINE TODOS OS IDOSOS DO APOIO
    while(string[i]!=NULL)                    
    {
      Idoso* novo_idoso = Constroi_idoso(string[i]);
      apoio->idosos = Insere_lista_idoso(apoio->idosos, novo_idoso);
      i++;
      string[i]=strtok(NULL,delimit);
    }
    /*AS PROXIMAS STRINGS DEFINEM AS AMIZADES DE CADA IDOSO*/
    for(i = 1; i < i0; i++){
        Idoso* idoso;
        Idoso* amigo;
        char idoso_nome[100];
        char amigo_nome[100];
        sscanf(apoio_txt[i], "%99[^;];%99s", idoso_nome, amigo_nome);
        idoso = Retorna_idoso(Encontra_lista_idoso(apoio->idosos, idoso_nome));
        amigo = Retorna_idoso(Encontra_lista_idoso(apoio->idosos, amigo_nome));
        Insere_lista_idoso(Retorna_lista_amigos_idoso(idoso), amigo);
    }

}

void Imprime_apoio(Apoio* apoio){
    printf("Idosos cadastrados:\n");
    Imprime_lista_detalhada_idoso(apoio->idosos);
}
