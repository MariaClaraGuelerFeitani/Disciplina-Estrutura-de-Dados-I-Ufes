#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

Fila *criarFila(){
    Fila *f=(Fila*)malloc(sizeof(Fila));
    if (f!=NULL){
        f->ini=NULL;
        f->fim=NULL;
        return f;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

int estaVazia(Fila *f){
    if (f->ini==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElemento(Fila *f, float v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        novo->prox=NULL;
        if (!estaVazia(f)){
            f->fim->prox=novo;
            f->fim=novo;
        }
        else {
            f->ini=novo;
            f->fim=novo;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimir (Fila *f){
    if (!estaVazia(f)){
        Nolista *t;
        for (t=f->ini;t!=NULL;t=t->prox){
            printf ("%.2f\n", t->info);
        }
    }
    else {
        printf ("Fila vazia!\n");
    }
}

float remover (Fila *f){
    if (!estaVazia(f)){
        Nolista *x=f->ini;
        float v;
        v= x->info;
        if (f->ini==NULL){ //1 elemento
            f->ini=NULL;
            f->fim=NULL;
        }
        else {
            f->ini=x->prox;
        }
        return v;
        free(x);
    }
    else {
        return 0;
    }
}

void liberarFila(Fila *f){
    if (!estaVazia(f)){
        Nolista *t;
        Nolista *temp;
        for (t=f->ini;t!=NULL;t=temp){
            temp=t->prox;
            free(t);
        }
        free(f);
    }
    else {
        free(f);
    }
}

float primeiroElemento(Fila *f){
    if (!estaVazia(f)){
        float v;
        v=f->ini->info;
        return v;
    }
    else {
        return 0;
    }
}

void furaFila(Fila *f, float v){
    if (!estaVazia(f)){
        Nolista *t;
        Nolista *ant=NULL;
        for (t=f->ini;t!=NULL && t->info!=v;t=t->prox){
            ant=t;
        }
        if (t==NULL){ //elemento nao encontrado
            return;
        }
        else {//foi encontrado
            if (ant==NULL){ //é o primeiro elemento da fila
                return;
            }
            else {
                ant->prox=t->prox;
                t->prox=f->ini;
                f->ini=t;
            }
        }
    }
    else {
        return;
    }
}
