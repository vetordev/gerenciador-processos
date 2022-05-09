#include "processo.h"
#include "fila.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Fila* f1;
Fila* f2;
Fila* f3;

int genTmp() {
  int baixo = 1, alto = 35;

  return (rand() % (baixo - alto + 1)) + baixo;
}

void preencherFilas() {
  for (int i = 0; i < 7; i++) {
    Processo* p = criarProcesso(PRONTO, genTmp(), NULL);
    inserirFinal(f1, p);
  }

  for (int i = 0; i < 10; i++) {
    Processo* p = criarProcesso(PRONTO, genTmp(), NULL);
    inserirFinal(f2, p);
  }

  for (int i = 0; i < 17; i++) {
    Processo* p = criarProcesso(PRONTO, genTmp(), NULL);
    inserirFinal(f3, p);
  }
}

void processar(Fila* f) {
  Processo* p = pegarInicio(f);
  if (p == NULL) return;
  
  definirEstado(p, ATIVO);
  
  int UT = pegarUT(f);
  int tmp = pegarTmpProcessamento(p);

  printf("Fila: %d; Processo %d\n", UT, tmp);
  while (tmp != 0) {
    tmp--;
    UT--;

    // interrupçao de relogio
    if (UT == 0 && tmp != 0) {

      definirTmpProcessamento(p, tmp);
      definirEstado(p, PRONTO);
      
      removerInicio(f);
      
      // Insere numa fila de menor prioridade
      if (f == f1) inserirFinal(f2, p);
      else inserirFinal(f3, p);
      
      return;
    }
  }
  
  removerInicio(f);
}

void gerenciar() {
  f1 = criarFila(5, NULL, NULL);
  f2 = criarFila(10, NULL, NULL);
  f3 = criarFila(15, NULL, NULL);

  // teste
  srand(time(0));
  preencherFilas();

  while (!vazia(f1) || !vazia(f2) || !vazia(f3)) {
    Fila* f;
    if (!vazia(f1)) f = f1;
    else if (!vazia(f2)) f = f2;
    else f = f3;

    processar(f);
  }
}
