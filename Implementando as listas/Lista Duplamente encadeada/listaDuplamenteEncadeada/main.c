#include <stdio.h>
#include <stdlib.h>

typedef struct nolista {
    int info;
    struct nolista *prox;
    struct nolista *ant;
} Nolista;

void criarLista(Nolista **l){
    *l = NULL;
}

int estaVazia(Nolista **l){
    if (*l == NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElementoInicio(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        if (*l==NULL){
            novo->ant=NULL;
            novo->prox= *l;
            *l = novo;
        }
        else {
            novo->ant=NULL;
            novo->prox= *l;
            novo->prox->ant=novo;
            *l = novo;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void inserirElementoFim(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        Nolista *p;
        Nolista *anterior = NULL;
        for (p=*l;p!=NULL;p=p->prox){
            anterior = p;
        }
        if (anterior==NULL){
            novo->ant=NULL;
            novo->prox=*l;
            *l=novo;
        }
        else{
            novo->prox=NULL;
            novo->ant=anterior;
            anterior->prox=novo;
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
        Nolista *anterior;
        for (p=*l;p!=NULL;p=p->prox){
            anterior=p;
        }
    return anterior;
    }
    else {
        return NULL;
    }
}

void imprimirListaInversa(Nolista **l){
    if (!estaVazia(l)){
        Nolista *ult=ultimoElemento(l);
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
        Nolista *anterior;
        for (p=*l;p!=NULL && p->info!=v;p=p->prox){
            anterior=p;
        }
        if (p==NULL){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            if (anterior==NULL){ //removendo o primeiro elemento
                p->prox->ant=p->ant;
                *l=p->prox;
                free(p);
            }
            else {
                if (p->prox!=NULL){//retirando no meio
                    p->prox->ant=anterior;
                    p->ant->prox=p->prox;
                    free(p);
                }
                else{ //retirando no final
                    p->ant->prox=p->prox;
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

void liberarLista(Nolista **l){
    Nolista *p;
    Nolista *temp;
    for (p=*l;p!=NULL;p=temp){
        temp=p->prox;
        free(p);
    }
}

int main()
{
    Nolista *lista;
    criarLista(&lista);
    imprimirLista(&lista);
    printf ("\n");
   // inserirElementoFim(&lista,90);
    inserirElementoInicio(&lista,56);
    inserirElementoInicio(&lista,6);
    inserirElementoFim(&lista,12);
    inserirElementoInicio(&lista,5);
    inserirElementoInicio(&lista,51);
    inserirElementoFim(&lista,34);
    inserirElementoFim(&lista,3);
    imprimirLista(&lista);
    printf ("\n");
    imprimirListaInversa(&lista);
    printf ("\n");
    removerElemento(&lista,6);
    removerElemento(&lista,34);
    imprimirLista(&lista);
    printf ("\n");
    imprimirListaInversa(&lista);
    printf ("\n");
    buscarElemento(&lista,56);
    buscarElemento(&lista,34);

    return 0;
}
