#include "processo.h"

typedef struct Fila Fila;
Fila* criarFila(int UT, Processo* primeiroProcesso, Processo* ultimoProcesso);

int pegarUT(Fila* f);

Processo* pegarInicio(Fila* f);
void inserirInicio(Fila* f, Processo* p);

Processo* pegarFinal(Fila* f);
void inserirFinal(Fila* f, Processo* p);

void removerInicio(Fila* f);
void removerFinal(Fila* f);

int vazia(Fila* f);
