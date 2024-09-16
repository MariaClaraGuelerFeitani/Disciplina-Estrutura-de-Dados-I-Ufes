#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct lista {
    int info[MAX];
    int n; //contador
}Lista;

Lista *criarLista();

int estaVazia(Lista *l);

int estaCheia(Lista *l);

void inserirElemento(Lista *l, int v);

void removerElemento(Lista *l, int v);

void buscarElemento(Lista *l, int v);

void imprimirLista(Lista *l);
