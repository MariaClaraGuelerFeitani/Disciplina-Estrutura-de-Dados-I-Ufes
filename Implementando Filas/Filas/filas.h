#ifndef FILAS_H_INCLUDED
#define FILAS_H_INCLUDED

typedef struct nolista {
    float info;
    struct nolista *prox;
}Nolista;

typedef struct fila {
    Nolista *ini;
    Nolista *fim;
}Fila;

Fila *criarFila();
int estaVazia(Fila *f);
void inserirElemento(Fila *f, float v);
void imprimir (Fila *f);
float remover (Fila *f);
float primeiroElemento(Fila *f);
void furaFila(Fila *f, float v);
void liberarFila(Fila *f);



#endif // FILAS_H_INCLUDED
