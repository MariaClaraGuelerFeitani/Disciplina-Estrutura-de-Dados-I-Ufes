#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

void criarLista(Nolista **l){
    *l=NULL;
}

int estaVazia(Nolista **l){
    if (*l==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirOrdenado(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        Nolista *p;
        Nolista *ant = NULL;
        novo->info = v;
        for (p=*l;p!=NULL && p->info < v; p=p->prox){
            ant = p;
        }
        novo->prox = p;
        if (ant == NULL){
            *l = novo;
        }
        else {
            ant->prox = novo;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimirLista(Nolista **l){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=*l;p!=NULL;p=p->prox){
            printf ("%d\n", p->info);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void removerElemento(Nolista **l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *ant = NULL;
        for (p=*l; p!= NULL && p->info != v; p=p->prox){
            ant = p;
        }
        if (p==NULL){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            if (ant==NULL){ //removendo do início
                *l = p->prox;
            }
            else {
                ant ->prox = p ->prox;
            }
            free(p);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void buscarElemento(Nolista **l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=*l; p!=NULL && p->info != v; p=p->prox);
        if (p==NULL){
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

void liberaLista(Nolista **l){
    Nolista *p;
    Nolista *temp;
    for (p=*l;p!=NULL;p=temp){
        temp = p->prox;
        free(p);
    }
    *l=NULL;
}

int contadora(Nolista **l){
    int cont=0;
    if (!estaVazia(l)){
        Nolista *p;
        for (p=*l; p!=NULL; p=p->prox){
            cont++;
        }
        return cont;
    }
    else {
        return cont;
    }
}

Nolista *ultimoElemento(Nolista **l){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=*l; p!=NULL; p=p->prox){
            if (p->prox == NULL){
                return p->info;
            }
        }
    }
    else {
        printf ("Lista vazia!\n");
        exit(1);
    }
}
