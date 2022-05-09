#include "processo.h"
#include <stdlib.h>

struct Processo {
  ESTADO estado;

  int tmpProcessamento;
  Processo* proximo;
};

Processo* criarProcesso(ESTADO estado, int tmpProcessamento, Processo* prox) {
  Processo* p = malloc(sizeof(Processo));
  p->estado = estado;
  p->tmpProcessamento = tmpProcessamento;
  p->proximo = prox;

  return p;
}

ESTADO pegarEstado(Processo* p) {
  return p->estado;
}

void definirEstado(Processo* p, ESTADO estado) {
  p->estado = estado;
}

int pegarTmpProcessamento(Processo* p) {
  return p->tmpProcessamento;
}

void definirTmpProcessamento(Processo* p, int tmp) {
  p->tmpProcessamento = tmp;
}

Processo* pegarProximo(Processo* p){
  return p->proximo;
}

void definirProximo(Processo* p, Processo* prox) {
  p->proximo = prox;
}