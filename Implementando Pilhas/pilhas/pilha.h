#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct nolista {
    float info;
    struct nolista *prox;
} Nolista;

typedef struct pilha {
    Nolista *prim;
} Pilha;

Pilha *criarPilha();
int estaVazia(Pilha *p);
void push(Pilha *p, float v);
void imprimir(Pilha *p);
float pop(Pilha *p);
float verTopo(Pilha *p);
void liberarPilha(Pilha *p);



#endif // PILHA_H_INCLUDED
