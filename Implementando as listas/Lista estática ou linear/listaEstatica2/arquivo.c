#ifndef ARQUIVO_C_INCLUDED
#define ARQUIVO_C_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include "arquivo.h" //nome da minha biblioteca .h

Lista *criarLista(){
    Lista *l = (Lista*)malloc (sizeof(Lista));
    l->n=0;
}

int estaVazia(Lista *l){
    if (l->n==0){
        return 1;
    }
    else {
        return 0;
    }
}

int estaCheia(Lista *l){
    if (l->n==MAX){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElemento(Lista *l, int v){
    if (!estaCheia(l)){
        l->info[l->n] = v;
        l->n++;
    }
    else {
        printf ("Lista cheia!\n");
    }
}

void removerElemento(Lista *l, int v){
    if (!estaVazia(l)){
        int i;
        for (i=0;i<l->n && l->info[i] != v;i++);
            if(i<l->n){
                int x;
                for (x=i;x<l->n;x++){
                    l->info[x]=l->info[x+1];
                }
                l->n--;
            }
            else {
                printf ("Elemento nao encontrado!\n");
            }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void buscarElemento(Lista *l, int v){
    if (!estaVazia(l)){
        int i;
        for (i=0;i<l->n && l->info[i] != v; i++);
        if (i<l->n){
            printf ("O elemento foi encontrado! %d\n", l->info[i]);
        }
        else {
            printf ("Elemento nao encontrado!\n");
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void imprimirLista(Lista *l){
    if (!estaVazia(l)){
        int i;
        for (i=0;i<l->n;i++){
            printf ("%d\n", l->info[i]);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

#endif // ARQUIVO_C_INCLUDED
