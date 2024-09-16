#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha *criarPilha(){
    Pilha *p=(Pilha*)malloc(sizeof(Pilha));
    p->prim=NULL;
    return p;
}

int estaVazia(Pilha *p){
    if (p->prim==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void push(Pilha *p, float v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        novo->prox=p->prim;
        p->prim=novo;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimir(Pilha *p){
    if (!estaVazia(p)){
        Nolista *t;
        for (t=p->prim;t!=NULL;t=t->prox){
            printf ("%.2f\n", t->info);
        }
    }
    else {
        printf ("Pilha vazia!\n");
    }
}

float pop(Pilha *p){
    if (!estaVazia(p)){
        Nolista *remover=p->prim;
        float v;
        p->prim=remover->prox;
        v = remover->info;
        free(remover);
        return v;

    }
    else {
        return 0;
    }
}

float verTopo(Pilha *p){
    if (!estaVazia(p)){
        Nolista *ver=p->prim;
        float v;
        v=ver->info;
        return v;
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void liberarPilha(Pilha *p){
    if (!estaVazia(p)){
        Nolista *t;
        Nolista *temp;
        for (t=p->prim;t!=NULL;t=temp){
            temp=t->prox;
            free(t);
        }
        free(p);
    }
    else {
        free(p);
    }
}
