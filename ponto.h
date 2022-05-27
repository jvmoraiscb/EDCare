#if !defined(PONTO_H)
#define PONTO_H

typedef struct st_ponto ponto;

ponto Constroi_ponto(unsigned long int x, unsigned long int y);
ponto* Constroi_vetor_ponto(int tamanho);
void Libera_vetor_ponto(ponto* a);
double Retorna_distancia_entre_ponto(ponto a, ponto b);

#endif // PONTO_H
