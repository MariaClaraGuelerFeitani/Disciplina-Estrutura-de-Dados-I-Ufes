#include <stdio.h>
#include <stdlib.h>

//vou implementar a árvore: <a<b<><d<><>>><c<e<><>><f<><>>>>

typedef struct arvore {
    char info;
    struct arvore *dir;
    struct arvore *esq;
}Arvore;

Arvore *criarVazia(){
    return NULL;
}

int estaVazia (Arvore *a){
    if (a==NULL){
        return 1;
    }
    else {
        return 0;
    }
}

Arvore *criarArvore(char c, Arvore *sae, Arvore *sad){
    Arvore *a=(Arvore*)malloc(sizeof(Arvore));
    if (a!=NULL){
        a->info=c;
        a->dir=sad;
        a->esq=sae;
        return a;
    }
    else {
        printf ("Nao foi possivel alocar espaco!\n");
    }
}

void imprimir (Arvore *a){
    printf ("<");
    if(!estaVazia(a)){
        printf ("%c", a->info);
        imprimir(a->esq);
        imprimir(a->dir);
    }
    printf (">");
}

Arvore *liberarArvore(Arvore *a){
    if (!estaVazia(a)){
        liberarArvore(a->esq);
        liberarArvore(a->dir);
        free(a);
    }
    return NULL;
}

int pertenceArvore(Arvore *a, char c){
    if (!estaVazia(a)){
        if (a->info==c){
            return 1;
        }
        else {
            return pertenceArvore(a->esq,c) || pertenceArvore(a->dir,c);
        }
    }
    else {
        return 0;
    }
}

int contNos(Arvore *a){
    if (!estaVazia(a)){
        return 1 + contNos(a->esq) + contNos(a->dir);
    }
    else {
        return 0;
    }
}

int alturaArvore(Arvore *a){ //Altura da árvore vazia (sem nó raiz) = -1 / Altura da árvore só com o nó raiz = 0
    if (estaVazia(a)){
        return -1;
    }
    else if (a->esq==NULL && a->dir==NULL){
        return 0;
    }
    else {
        int he = alturaArvore(a->esq);
        int hd = alturaArvore(a->dir);

        if (he >= hd){
            return he + 1; //tem que somar um, já que a->esq é considerado o nó raiz nessa recursividade, portanto não foi contado
        }
        else {
            return hd + 1;
        }
    }
}

int main()
{
    Arvore *e=criarArvore('e', criarVazia(), criarVazia());
    Arvore *f=criarArvore('f', criarVazia(), criarVazia());
    Arvore *d=criarArvore('d', criarVazia(), criarVazia());
    Arvore *c=criarArvore('c', e, f);
    Arvore *b=criarArvore('b', criarVazia(), d);
    Arvore *a=criarArvore('a', b, c);
    imprimir(a);
    printf ("\n");

    int x = pertenceArvore(a, 'e');
    if (x==0){
        printf ("Nao pertence!\n");
    }
    else {
        printf ("Pertence!\n");
    }

    int y = pertenceArvore(a, 'h');
    if (y==0){
        printf ("Nao pertence!\n");
    }
    else {
        printf ("Pertence!\n");
    }

    printf ("Quantidade de nos da arvore: %d\n", contNos(a));
    printf ("Altura da arvore: %d\n", alturaArvore(a));

    return 0;
}
