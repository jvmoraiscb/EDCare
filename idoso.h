#if !defined (IDOSO_H)
#define IDOSO_H

#include "cuidador.h"

typedef struct st_idoso Idoso;
typedef struct st_lista_idoso Lista_idoso;

Idoso* Constroi_idoso(char* nome);
void Destroi_idoso(Idoso* idoso);
char* Retorna_nome_idoso(Idoso* idoso);
unsigned long int Retorna_latitude_idoso(Idoso* idoso);
void Modifica_latitude_idoso(Idoso*idoso, unsigned long int latitude);
unsigned long int Retorna_longitude_idoso(Idoso* idoso);
void Modifica_longitude_idoso(Idoso* idoso, unsigned long int longitude);
float Retorna_temperatura_idoso(Idoso* idoso);
void Modifica_temperatura_idoso(Idoso* idoso, float temperatura);
int Retorna_queda_idoso(Idoso* idoso);
void Modifica_queda_idoso(Idoso* idoso, int queda);
void Insere_amigo_idoso(Idoso* idoso, Idoso* amigo);
void Remove_amigo_idoso(Idoso* idoso, char* nome);
void Insere_cuidador_idoso(Idoso* idoso, Cuidador* cuidador);
void Atualiza_leituras_idoso(Idoso* idoso, unsigned long int latitude, unsigned long int longitude, float temperatura, int queda);
Lista_idoso* Retorna_amigos_idoso(Idoso* idoso);
Lista_cuidador* Retorna_cuidadores_idoso(Idoso* idoso);

#endif // IDOSO_H