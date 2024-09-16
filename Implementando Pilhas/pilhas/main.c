#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    Pilha *pilha=criarPilha();
    imprimir(pilha);
    printf ("\n");
    push(pilha,45);
    push(pilha,3);
    push(pilha,4);
    push(pilha,78);
    push(pilha,23);
    push(pilha,5);
    push(pilha,90);
    push(pilha,32);
    imprimir(pilha);
    printf ("\n");
    printf ("Remover: %.2f\n", pop(pilha));
    printf ("\n");
    imprimir(pilha);
    printf ("\n");
    printf ("Topo da pilha: %.2f\n", verTopo(pilha));
    printf ("\n");
    printf ("Remover: %.2f\n", pop(pilha));
    printf ("\n");
    imprimir(pilha);
    printf ("\n");
    printf ("Topo da pilha: %.2f\n", verTopo(pilha));
    printf ("\n");

    return 0;
}
