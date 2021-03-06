#if !defined(APOIO_H)
#define APOIO_H

typedef struct st_apoio Apoio;

/*ALOCA MEMORIA E INICIALIZA UMA LISTA DE IDOSOS (VAZIA) E UMA LISTA DE CUIDADORES (VAZIA)*/
Apoio* Inicializa_apoio();
/*LIBERA TODA A MEMORIA ALOCADA, INCLUSIVE OS IDOSOS E CUIDADORES*/
void Destroi_apoio(Apoio* apoio);

/*EFETUA A LEITURA DO ARQUIVO "apoio.txt", PREENCHE A LISTA DE IDOSOS COM TODOS OS IDOSOS E PREENCHE A LISTA DE AMIGOS DE CADA IDOSO*/
void Carrega_idosos_apoio(Apoio* apoio);
/*EFETUA A LEITURA DO ARQUIVO "cuidadores.txt" E PREENCHE A LISTA DE CUIDADORES COM TODOS OS CUIDADORES*/
void Carrega_cuidadores_apoio(Apoio* apoio);

/*PERCORRE A LISTA DE IDOSOS, PARA CADA UM DELES EFETUA A LEITURA DA LINHA CORRESPONDENTE AO INSTANTE NO ARQUIVO "nome_idoso.txt" E ATUALIZA AS VARIAVEIS*/
void Atualiza_idosos_apoio(Apoio* apoio, int instante);
/*PERCORRE A LISTA DE CUIDADORES, PARA CADA UM DELES EFETUA A LEITURA DA LINHA CORRESPONDENTE AO INSTANTE NO ARQUIVO "nome_cuidador.txt" E ATUALIZA AS VARIAVEIS*/
void Atualiza_cuidadores_apoio(Apoio* apoio, int instante);

/*PERCORRE A LISTA DE IDOSOS, PARA CADA UM DELES EFETUA A ESCRITA DA SITUACAO DELE (UMA LINHA POR VEZ QUE A FUNCAO E CHAMADA) NO ARQUIVO "Saida/nome_idoso-saida.txt*/
void Verifica_idosos_apoio(Apoio* apoio);

/*BUSCA O NOME NA LISTA DE IDOSOS, PERCORRE A LISTA DE IDOSOS E REMOVE ELE DA LISTA DE AMIGOS DE CADA OUTRO IDOSO, DEPOIS REMOVE DA LISTA DE IDOSOS E POR FIM LIBERA A MEMORIA*/
void Remove_falecido_apoio(Apoio* apoio, char* nome);

/*IMPRIME OS IDOSOS E OS CUIDADORES CADASTRADOS NO APOIO*/
void Imprime_apoio(Apoio* apoio);

#endif
