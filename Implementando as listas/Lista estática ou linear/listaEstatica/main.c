#include <stdio.h>
#include <stdlib.h>
#define MAX 10

//LISTA ESTÁTICA OU LISTA LINEAR

typedef struct lista {
    int n;
    int info[MAX];
} Lista;

Lista* criarLista(){
    Lista *l = (Lista*)malloc(sizeof(Lista));
    l->n=0;
    return l;
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
        l->info[l->n]=v;
        l->n++;
    }
    else {
        printf ("Lista cheia!\n");
    }
}

void imprimirLista(Lista *l){
    if(!estaVazia(l)){
        for (int i=0; i<l->n;i++){
            printf ("%d\n", l->info[i]);
        }
    }
    else {
        printf ("Lista vazia!\n");
    }
}

void removerElemento(Lista *l, int v){ //removendo por elemento
    if(!estaVazia(l)){
        int i;
        for (i=0;i<l->n && l->info[i]!=v;i++);//posicionando o ponteiro
        if (i<l->n){ //o elemento foi encontrado
            for (int x=i;x<l->n;x++){
                l->info[x]=l->info[x+1];
            }
            l->n--;
        }
        else {
            printf ("Elemento nao encontrado!\n");
        }

    }
    else {
        printf ("Lista Vazia!\n");
    }
}

void buscarElemento(Lista *l, int v){
    if (!estaVazia(l)){
        int i;
        for (i=0;i<l->n && l->info[i]!=v;i++);
        if(i<l->n){ //elemento encontrado
            printf ("Elemento encontrado! Posicao: %d\n",i);
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
    Lista *Lista = criarLista();
    imprimirLista(Lista);
    printf ("\n");
    inserirElemento(Lista,1);
    inserirElemento(Lista,23);
    inserirElemento(Lista,56);
    inserirElemento(Lista,89);
    inserirElemento(Lista,4);
    imprimirLista(Lista);
    printf ("\n");
    removerElemento(Lista,23);
    imprimirLista(Lista);
    printf ("\n");
    buscarElemento(Lista,56);
    buscarElemento(Lista,23);

    return 0;
}
