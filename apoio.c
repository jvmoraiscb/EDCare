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

void Carrega_idosos_apoio(Apoio* apoio){
    FILE* file_apoio = fopen("Entrada/apoio.txt", "r");
    char apoio_txt[30][1000];
    int i0=0;
    /*ARMAZENA O ARQUIVO EM UM VETOR DE STRINGS*/
    while(fscanf(file_apoio, "%999s", apoio_txt[i0]) == 1){
        i0++;
    };
    fclose(file_apoio);
    
    /*CONSTROI OS IDOSOS E PREENCHE A LISTA_IDOSO*/
    char *string[1000];   
    char delimit[]=" ;\n"; // OS NOMES ESTAO SEPARADOS POR ';' E O ULTIMO POR '\n'
    int i = 0;                                  
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
        Insere_amigo_idoso(idoso, amigo);
        Insere_amigo_idoso(amigo, idoso);
    }

}

void Carrega_cuidadores_apoio(Apoio* apoio){
    FILE* file_cuidadores = fopen("Entrada/cuidadores.txt", "r");
    char cuidadores_txt[30][1000];
    int i0=0;
    /*ARMAZENA O ARQUIVO EM UM VETOR DE STRINGS*/
    while(fscanf(file_cuidadores, "%999s", cuidadores_txt[i0]) == 1){
        i0++;
    };
    fclose(file_cuidadores);

    /*CONSTROI OS CUIDADORES E PREENCHE A LISTA_CUIDADORES*/
    char *string[1000];   
    char delimit[]=" ;\n"; // OS NOMES ESTAO SEPARADOS POR ';' E O ULTIMO POR '\n'
    int i = 0;                                  
    string[i]=strtok(cuidadores_txt[0],delimit); // A PRIMEIRA STRING DEFINE TODOS OS CUIDADORES DO APOIO
    while(string[i]!=NULL)                    
    {
      Cuidador* novo_cuidador = Constroi_cuidador(string[i]);
      apoio->cuidadores = Insere_lista_cuidador(apoio->cuidadores, novo_cuidador);
      i++;
      string[i]=strtok(NULL,delimit);
    }
    int j;
    Idoso* idoso;
    for(j = 1; j < i0; j++){
        char *string[1000];   
        char delimit[]=" ;\n"; // OS NOMES ESTAO SEPARADOS POR ';' E O ULTIMO POR '\n'
        int i = 0;                                  
        string[i]=strtok(cuidadores_txt[j],delimit); // A PRIMEIRA STRING DEFINE TODOS OS CUIDADORES DO APOIO
        while(string[i]!=NULL)                    
        {
            if(i == 0){
                idoso = Retorna_idoso(Encontra_lista_idoso(apoio->idosos, string[i]));
            }
            else{
                Cuidador* cuidador = Retorna_cuidador(Encontra_lista_cuidador(apoio->cuidadores, string[i]));
                Insere_cuidador_idoso(idoso, cuidador);
            }
            i++;
            string[i]=strtok(NULL,delimit);
        }
    }
}

void Imprime_apoio(Apoio* apoio){
    printf("IDOSOS CADASTRADOS:\n\n");
    Imprime_lista_detalhada_idoso(apoio->idosos);
    printf("CUIDADORES CADASTRADOS:\n\n");
    Imprime_lista_cuidador(apoio->cuidadores);
}
