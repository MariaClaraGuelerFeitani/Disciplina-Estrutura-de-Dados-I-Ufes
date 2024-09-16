#include <stdio.h>
#include <stdlib.h>

typedef struct nolista{
    int info;
    struct nolista *prox;
    struct nolista *ant;
} Nolista;

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

void inserirElementoOrdenado(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
            novo->info=v;
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *anterior=NULL;
        for (p=*l;p!=NULL && p->info<v;p=p->prox){
            anterior=p;
        }
        if (anterior==NULL){ //inserindo no início
            novo->ant=NULL;
            p->ant=novo;
            *l=novo;
        }
        else {
            if (p==NULL){ //inserindo no final
                novo->prox=NULL;
                anterior->prox=novo;
                anterior->prox->ant=anterior;
            }
            else { //inserindo no meio
                novo->prox=p;
                novo->ant=anterior;
                anterior->prox=novo;
                p->ant=novo;
            }
        }
    }
    else {
        novo->ant=NULL;
        novo->prox=NULL;
        *l=novo;
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

Nolista *ultimoElemento(Nolista **l){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *anterior = NULL;
        for (p=*l;p!=NULL;p=p->prox){
            anterior=p;
        }
        return anterior;
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void imprimeListaInversa(Nolista **l){
    if (!estaVazia(l)){
        Nolista *ult = ultimoElemento(l);
        Nolista *p;
        for (p=ult;p!=NULL;p=p->ant){
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
        Nolista *anterior = NULL;
        for (p=*l;p!=NULL && p->info!=v;p=p->prox){
            anterior=p;
        }
        if (p==NULL){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            if (anterior==NULL){ //removendo no início
                p->prox->ant=p->ant;
                *l=p->prox;
                free(p);
            }
            else {
                if (p->prox==NULL){ //retirando no final
                    p->ant->prox=p->prox;
                    free(p);
                }
                else { //removendo do meio
                    p->ant->prox=p->prox;
                    p->prox->ant=p->ant;
                    free(p);
                }
            }
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void buscarElemento(Nolista **l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=*l;p!=NULL && p->info!=v;p=p->prox);
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

int main()
{
    Nolista *lista;
    criarLista(&lista);
    imprimeListaInversa(&lista);
    printf ("\n");
    inserirElementoOrdenado(&lista,23);
    inserirElementoOrdenado(&lista,3);
    inserirElementoOrdenado(&lista,2);
    inserirElementoOrdenado(&lista,90);
    inserirElementoOrdenado(&lista,15);
    inserirElementoOrdenado(&lista,44);
    imprimirLista(&lista);
    printf ("\n");
    imprimeListaInversa(&lista);
    printf ("\n");
    removerElemento(&lista,15);
    imprimirLista(&lista);
    printf ("\n");
    imprimeListaInversa(&lista);
    printf ("\n");
    buscarElemento(&lista,3);
    buscarElemento(&lista,67);

    return 0;
}
