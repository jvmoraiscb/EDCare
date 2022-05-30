#if !defined (CUIDADOR_H)
#define CUIDADOR_H

typedef struct st_cuidador Cuidador;
typedef struct st_lista_cuidador Lista_cuidador;

Cuidador* Constroi_cuidador(char* nome);
void Destroi_cuidador(Cuidador* cuidador);
char* Retorna_nome_cuidador(Cuidador* cuidador);

#endif // CUIDADOR_H
