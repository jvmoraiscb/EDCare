#if !defined (CUIDADOR_H)
#define CUIDADOR_H

typedef struct st_cuidador Cuidador;
typedef struct st_lista_cuidador Lista_cuidador;

Cuidador* Constroi_cuidador(char* nome);
void Destroi_cuidador(Cuidador* cuidador);
char* Retorna_nome_cuidador(Cuidador* cuidador);
unsigned long int Retorna_latitude_cuidador(Cuidador* cuidador);
void Modifica_latitude_cuidador(Cuidador* cuidador, unsigned long int latitude);
unsigned long int Retorna_longitude_cuidador(Cuidador* cuidador);
void Modifica_longitude_cuidador(Cuidador* cuidador, unsigned long int longitude);

#endif // CUIDADOR_H
