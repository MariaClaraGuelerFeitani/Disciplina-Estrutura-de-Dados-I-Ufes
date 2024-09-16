#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef struct nolista {
    int info;
    struct nolista *prox;
}Nolista;

void criarLista(Nolista **l);

int estaVazia(Nolista **l);

void inserirOrdenado(Nolista **l, int v);

void imprimirLista(Nolista **l);

void removerElemento(Nolista **l, int v);

void buscarElemento(Nolista **l, int v);

void liberaLista(Nolista **l);

int contadora(Nolista **l);

Nolista *ultimoElemento(Nolista **l);


#endif // ARQUIVO_H_INCLUDED
