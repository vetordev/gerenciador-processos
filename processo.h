#ifndef _PROCESSOH_
#define _PROCESSOH_

typedef enum ESTADO {PRONTO, ATIVO, ESPERA} ESTADO;

typedef struct Processo Processo;
Processo* criarProcesso(ESTADO estado, int tmpProcessamento, Processo* prox);

ESTADO pegarEstado(Processo* p);
void definirEstado(Processo *p, ESTADO estado);

int pegarTmpProcessamento(Processo *p);
void definirTmpProcessamento(Processo *p, int tmp);

Processo* pegarProximo(Processo *p);
void definirProximo(Processo *p, Processo* prox);


#endif
