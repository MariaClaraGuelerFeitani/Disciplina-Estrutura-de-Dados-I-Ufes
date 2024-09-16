#include <stdio.h>
#include <stdlib.h>
#define MAX 10
#include "arquivo.h"

int main()
{
    Lista *Lista = criarLista();
    imprimirLista(Lista);
    printf ("\n");
    inserirElemento(Lista, 2);
    inserirElemento(Lista, 20);
    inserirElemento(Lista, 45);
    inserirElemento(Lista, 78);
    inserirElemento(Lista, 43);
    inserirElemento(Lista, 11);
    imprimirLista(Lista);
    printf ("\n");
    removerElemento(Lista,78);
    removerElemento(Lista,2);
    imprimirLista(Lista);
    printf ("\n");
    buscarElemento(Lista,78);
    buscarElemento(Lista,11);

    return 0;
}
