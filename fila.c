#include "fila.h"
#include <stdlib.h>

struct Fila {
  int UT;

  struct Processo* inicio;
  struct Processo* fim;
};

Fila* criarFila(int UT, Processo* primeiroProcesso, Processo* ultimoProcesso) {
  Fila* f = malloc(sizeof(Fila));

  f->UT = UT;
  f->inicio = primeiroProcesso;
  f->fim = ultimoProcesso;

  return f;
}

int pegarUT(Fila *f) {
  return f->UT;
}

Processo* pegarInicio(Fila* f) {
  return f->inicio;
}

Processo* pegarFinal(Fila* f) {
  return f->fim;
}

void inserirInicio(Fila* f, Processo* p) {
  // fila vazia
  if (f->inicio == NULL) {
    f->inicio = p;
    f->fim = p;
    
    return;
  }

  definirProximo(p, f->inicio);

  f->inicio = p;
}

void inserirFinal(Fila* f, Processo* p) {
  // fila vazia
  if (f->fim == NULL) {
    f->inicio = p;
    f->fim = p;

    return;
  }

  definirProximo(f->fim, p);
  definirProximo(p, NULL);
  
  f->fim = p;

}

void removerInicio(Fila* f) {
  if (f->inicio != NULL) {
    f->inicio = pegarProximo(f->inicio);
  }
}

int vazia(Fila* f) {
  if (f->inicio == NULL) {
    return 1;
  }

  return 0;
}