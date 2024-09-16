#include <stdio.h>
#include <stdlib.h>

typedef struct nolista {
    int info;
    struct nolista *prox;
}Nolista;

typedef struct descritor {
    Nolista *pri;
    Nolista *ult;
    int n;
} Descritor;

Descritor criarLista(){
    Descritor l;
    l.pri=NULL;
    l.ult=NULL;
    l.n=0;
    return l;
}

int estaVazia(Descritor *l){
    if (l->n==0){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElementoInicio(Descritor *l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        if (l->pri==NULL){ //primeiro elemento
            novo->prox=NULL;
            l->pri=novo;
            l->ult=novo;
            l->n++;
        }
        else {
            novo->prox=l->pri;
            l->pri=novo;
            l->n++;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void inserirElementoFim(Descritor *l, int v){
    Nolista *novo=(Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info=v;
        if (l->pri==NULL){ //primeiro elemento a ser alocado
            novo->prox=NULL;
            l->pri=novo;
            l->ult=novo;
            l->n++;
        }
        else {
            Nolista *p;
            Nolista *ant;
            for (p=l->pri;p!=NULL;p=p->prox){
                ant=p;
            }
            novo->prox=ant->prox;
            ant->prox=novo;
            l->ult=novo;
            l->n++;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimirLista (Descritor *l){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=l->pri;p!=NULL;p=p->prox){
            printf ("%d\n", p->info);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void removerElemento(Descritor *l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *ant = NULL;
        for (p=l->pri;p!=NULL && p->info!=v;p=p->prox){
            ant=p;
        }
        if (p==NULL){
            printf ("Elemento nao encontrado!\n");
        }
        else {
            if (l->n==1){//removendo o único elemento da lista
            l->pri=NULL;
            l->ult=NULL;
            free(p);
            l->n--;
        }
        else {
            if (ant==NULL){ //removendo o primeiro elemento da lista
                l->pri=p->prox;
                free(p);
                l->n--;
            }
            else {
                if (p->prox==NULL){//removendo o último elemento
                    ant->prox=p->prox;
                    l->ult=ant;
                    free(p);
                    l->n--;
                }
                else { //removendo do meio
                    ant->prox=p->prox;
                    free(p);
                    l->n--;
                }
            }
        }
        }

        }
    else {
        printf ("Lista vazia!\n");
    }
}

void buscarElemento(Descritor *l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        for (p=l->pri;p!=NULL && p->info!=v;p=p->prox);
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

void liberarLista (Descritor *l){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *temp;
        for (p=l->pri;p!=NULL;p=temp){
            temp=p->prox;
            free(p);
        }
        free(l->pri);
        free(l->ult);
    }
    else {
        free(l->pri);
        free(l->ult);
    }
}

int main()
{
    Descritor lista = criarLista(&lista);
    imprimirLista(&lista);
    printf ("\n");
    inserirElementoInicio(&lista,3);
    inserirElementoInicio(&lista,34);
    inserirElementoFim(&lista,43);
    inserirElementoFim(&lista,90);
    imprimirLista(&lista);
    printf ("\n");
    printf ("Quantidade de elementos da lista: %d\n", lista.n);
    printf ("\n");
    removerElemento(&lista,5);
    removerElemento(&lista,34);
    imprimirLista(&lista);
    printf ("\n");
    printf ("Quantidade de elementos da lista: %d\n", lista.n);
    printf ("\n");
    buscarElemento(&lista,5);
    buscarElemento(&lista,34);
    buscarElemento(&lista,90);
    liberarLista(&lista);
    inserirElementoFim(&lista,89);


    return 0;
}
