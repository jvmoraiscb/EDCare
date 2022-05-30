#if !defined (IDOSO_H)
#define IDOSO_H

typedef struct st_idoso Idoso;

Idoso* Constroi_idoso(char* nome);
void Destroi_idoso(Idoso* idoso);
char* Retorna_nome_idoso(Idoso* idoso);
unsigned long int Retorna_latitude_idoso(Idoso* idoso);
unsigned long int Retorna_longitude_idoso(Idoso* idoso);
float Retorna_temperatura_idoso(Idoso* idoso);
int Retorna_queda_idoso(Idoso* idoso);
void* Retorna_amigos_idoso(Idoso* idoso);
void* Retorna_cuidadores_idoso(Idoso* idoso);

#endif // IDOSO_H