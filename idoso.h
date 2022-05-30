#if !defined (IDOSO_H)
#define IDOSO_H

#include "cuidador.h"

typedef struct st_idoso Idoso;
typedef struct st_lista_idoso Lista_idoso;

Idoso* Constroi_idoso(char* nome);
void Destroi_idoso(Idoso* idoso);
char* Retorna_nome_idoso(Idoso* idoso);
unsigned long int Retorna_latitude_idoso(Idoso* idoso);
unsigned long int Retorna_longitude_idoso(Idoso* idoso);
float Retorna_temperatura_idoso(Idoso* idoso);
int Retorna_queda_idoso(Idoso* idoso);
void Insere_amigo_idoso(Idoso* idoso, Idoso* amigo);
void Insere_cuidador_idoso(Idoso* idoso, Cuidador* cuidador);
Lista_idoso* Retorna_amigos_idoso(Idoso* idoso);
Lista_cuidador* Retorna_cuidadores_idoso(Idoso* idoso);

#endif // IDOSO_H