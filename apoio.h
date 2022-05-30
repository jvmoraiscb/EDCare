#if !defined(APOIO_H)
#define APOIO_H

typedef struct st_apoio Apoio;

Apoio* Inicializa_apoio();
void Carrega_idosos_apoio(Apoio* apoio);
void Atualiza_idosos_apoio(Apoio* apoio, int instante);
void Carrega_cuidadores_apoio(Apoio* apoio);
void Atualiza_cuidadores_apoio(Apoio* apoio, int instante);
void Verifica_idosos_apoio(Apoio* apoio);
void Imprime_apoio(Apoio* apoio);

#endif // APOIO_H
