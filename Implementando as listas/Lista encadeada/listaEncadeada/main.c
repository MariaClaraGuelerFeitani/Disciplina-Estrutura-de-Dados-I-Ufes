#include <stdio.h>
#include <stdlib.h>

//LISTA ENCADEADA

typedef struct nolista{
    int info;
    struct nolista *prox;
}Nolista;

void criarLista(Nolista **l){
    *l=NULL; //criei uma lista nula
}

int estaVazia(Nolista **l){
    if (*l==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

void inserirElementoInicio(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){ //conferindo se aloucou espaço para o nó
        novo->info = v;
        novo->prox = *l;
        *l = novo;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
        exit(1); //força a saída da função
    }
}

void inserirElementoFim(Nolista **l, int v){
    Nolista *novo = (Nolista*)malloc(sizeof(Nolista));
    if (novo!=NULL){
        novo->info = v;
        Nolista *p;
        Nolista *ant = NULL;
        for (p=*l;p!=NULL;p=p->prox){
            ant = p;
        }
        if (ant==NULL){ //primeiro elemento da lista
            *l = novo;
            novo->prox = p;
        }
        else {
            ant->prox = novo;
            novo->prox = p;
        }
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimeElementos(Nolista **l){
    if (!estaVazia(l)){
        for (Nolista *p=*l; p != NULL; p = p-> prox){
            printf ("%d\n", p->info);
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
        if (p!=NULL){ //encontrou o elemento
            printf ("O elemento foi encontrado! %d\n", p->info);
        }
        else {
            printf ("O elemento nao foi encontrado!\n");
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void removerElemento(Nolista **l, int v){
    if (!estaVazia(l)){
        Nolista *p;
        Nolista *ant=NULL;
        for (p=*l; p!= NULL && p->info != v; p=p->prox){
            ant = p;
        }
        if (p!=NULL){ //elemento encontrado
            if (ant!=NULL){ //removendo no início
                ant->prox = p->prox;
            }
            else {
                *l=p->prox;
            }
            free(p);
        }
        else {
            printf ("Elemento nao encontrado!\n");
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

int main()
{
    Nolista *Lista;
    criarLista(&Lista);
    imprimeElementos(&Lista);
    printf("\n");
    inserirElementoInicio(&Lista,1);
    inserirElementoInicio(&Lista,20);
    inserirElementoFim(&Lista,9);
    inserirElementoInicio(&Lista,78);
    inserirElementoInicio(&Lista,45);
    inserirElementoFim(&Lista,23);
    inserirElementoInicio(&Lista,3);
    inserirElementoFim(&Lista,90);
    imprimeElementos(&Lista);
    printf("\n");
    removerElemento(&Lista,45);
    imprimeElementos(&Lista);
    printf("\n");
    buscarElemento(&Lista,3);
    buscarElemento(&Lista,45);
    return 0;
}
