#include <stdio.h>
#include <stdlib.h>

typedef struct nolista {
    int info;
    struct nolista *prox;
}Nolista;

typedef struct lista {
    Nolista *cab;
    Nolista *cau;
}Lista;

Lista criarLista(){
    Lista l;
    l.cab = (Nolista*)malloc(sizeof(Nolista));
    l.cau = (Nolista*)malloc(sizeof(Nolista));
    l.cab->prox = l.cau;
    l.cau->prox = NULL;
    return l;
}

int estaVazia(Lista *l){
    if (l->cab->prox==l->cau){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElementoInicio(Lista *l, int v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        novo->prox=l->cab->prox;
        l->cab->prox=novo;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void inserirElementoFim(Lista *l, int v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        Nolista *p;
        Nolista *ant;
        for (p=l->cab->prox;p!=l->cau;p=p->prox){
            ant=p;
        }
        novo->prox=ant->prox;
        ant->prox=novo;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimirLista(Lista *l){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=l->cab->prox;p!=l->cau;p=p->prox){
            printf ("%d\n", p->info);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }

}

void removerElemento(Lista *l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *ant=l->cab;
        for (p=l->cab->prox; p!=l->cau && p->info!=v; p=p->prox){
            ant = p;
        }
        if (p==l->cau){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            ant->prox=p->prox;
            free(p);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void buscarElemento(Lista *l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=l->cab->prox;p!=l->cau && p->info!=v;p=p->prox);
        if (p==l->cau){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            printf ("Elemento encontrado! %d\n", p->info);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void liberarLista(Lista *l){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *temp;
        for (p=l->cab->prox;p!=NULL;p=temp){
            temp=p->prox;
            free(p);
        }
        free(l->cab);
        free(l->cau);
    }
    else {
        free(l->cab);
        free(l->cau);
    }
}

int main()
{
    Lista lista = criarLista();
    imprimirLista(&lista);
    printf ("\n");
    inserirElementoInicio(&lista,34);
    inserirElementoInicio(&lista,3);
    inserirElementoInicio(&lista,4);
    inserirElementoFim(&lista,90);
    inserirElementoFim(&lista,6);
    inserirElementoFim(&lista,23);
    imprimirLista(&lista);
    printf ("\n");
    removerElemento(&lista,23);
    removerElemento(&lista,34);
    removerElemento(&lista,67);
    imprimirLista(&lista);
    printf ("\n");
    inserirElementoFim(&lista,102);
    inserirElementoFim(&lista,65);
    imprimirLista(&lista);
    printf ("\n");
    buscarElemento(&lista,102);
    buscarElemento(&lista,34);
    liberarLista(&lista);
    imprimirLista(&lista);

    return 0;
}
