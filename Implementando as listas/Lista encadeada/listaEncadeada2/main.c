#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

int main()
{
    Nolista *Lista;
    criarLista(&Lista);
    imprimirLista(&Lista);
    printf ("\n");
    inserirOrdenado(&Lista,69);
    inserirOrdenado(&Lista,19);
    inserirOrdenado(&Lista,13);
    inserirOrdenado(&Lista,45);
    inserirOrdenado(&Lista,2);
    inserirOrdenado(&Lista,65);
    inserirOrdenado(&Lista,67);
    inserirOrdenado(&Lista,9);
    imprimirLista(&Lista);
    printf ("Quantidade de elementos da lista: %d\n", contadora(&Lista));
    printf ("\n");
    removerElemento(&Lista,100);
    removerElemento(&Lista,67);
    removerElemento(&Lista,45);
    imprimirLista(&Lista);
    printf ("\n");
    buscarElemento(&Lista,13);
    buscarElemento(&Lista,45);
    printf ("Quantidade de elementos da lista: %d\n", contadora(&Lista));
    printf ("Ultimo Elemento da lista: %d\n", ultimoElemento(&Lista));

    return 0;
}
