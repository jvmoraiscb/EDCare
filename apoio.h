#if !defined(APOIO_H)
#define APOIO_H

typedef struct st_apoio Apoio;

Apoio* Inicializa_apoio();
void Carrega_idosos_apoio(Apoio* apoio);
void Carrega_cuidadores_apoio(Apoio* apoio);
void Imprime_apoio(Apoio* apoio);

#endif // APOIO_H
