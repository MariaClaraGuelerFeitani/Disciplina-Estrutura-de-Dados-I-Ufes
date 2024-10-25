#include <stdio.h>
#include <stdlib.h>

typedef struct arvore {
    int info;
    struct arvore *esq;
    struct arvore *dir;
}Arvore;

Arvore *criarArvoreVazia(){
    return NULL;
}

int estaVazia(Arvore *a){
    if (a==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

Arvore *inserirElemento(Arvore *a, int v){
    if (estaVazia(a)){
        a=(Arvore*)malloc(sizeof(Arvore));
        if (a!=NULL){
            a->info=v;
            a->esq=NULL;
            a->dir=NULL;
            return a;
        }
        else {
            printf ("Nao foi possivel alocar espaco!\n");
        }
    }
    else {
        if (v<=a->info){
            a->esq=inserirElemento(a->esq,v);
        }
        else {
            a->dir=inserirElemento(a->dir,v);
        }
    }
}

Arvore *busca(Arvore *a, int v){
    if (estaVazia(a)){
        return NULL;
    }
    else {
        if (a->info==v){
            return a;
        }
        else if(v<a->info){
            return busca(a->esq,v);
        }
        else {
            return busca(a->dir,v);
        }
    }
}

void imprimir(Arvore *a){
    printf ("<");
    if (!estaVazia(a)){
        printf ("%d", a->info);
        imprimir(a->esq);
        imprimir(a->dir);
    }
    printf (">");
}

Arvore *removerElemento(Arvore *a, int v){
    if (estaVazia(a)){
        return NULL;
    }
    else {
        if (v<a->info){
            a->esq=removerElemento(a->esq,v);
        }
        else if (v>a->info){
            a->dir=removerElemento(a->dir,v);
        }
        else { //achou o elemento
            if (a->esq==NULL && a->dir==NULL){ //vou retirar uma folha (sem filhos)
                free(a);
                a=NULL;
            }
            else if (a->esq==NULL){ // 1 filho a direita
                Arvore *t = a->dir;
                free(a);
                a=t;
            }
            else if (a->dir==NULL){ //1 filho a esquerda
                Arvore *t = a->esq;
                free(a);
                a=t;
            }
            else { //2 filhos
                Arvore *t=a->esq;
                while (t->dir!=NULL){
                    t=t->dir;
                }
                a->info=t->info;
                t->info=v;
                a->esq=removerElemento(a->esq,v);
            }
        }
        return a;
    }
}

int impares (Arvore *a){
    if (estaVazia(a)){
        return 0;
    }
    else {
        if (a->info%2!=0){
            return 1 + impares(a->esq) + impares (a->dir);
        }
        else {
            return impares (a->esq) + impares (a->dir);
        }
    }
}

int main()
{
    Arvore *arvore = criarArvoreVazia();
    arvore = inserirElemento(arvore,45);
    arvore = inserirElemento(arvore,5);
    arvore = inserirElemento(arvore,23);
    arvore = inserirElemento(arvore,2);
    arvore = inserirElemento(arvore,90);
    arvore = inserirElemento(arvore,67);
    arvore = inserirElemento(arvore,34);
    arvore = inserirElemento(arvore,12);
    imprimir(arvore);
    printf ("\n");
    removerElemento(arvore,67);
    imprimir(arvore);
    printf ("\n");
    printf ("Busca: %p\n", busca(arvore,90));
    printf ("Busca: %p\n", busca(arvore,102));
    printf ("Impares: %d\n", impares(arvore));
    return 0;
}
