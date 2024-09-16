#include <stdio.h>
#include <stdlib.h>
#include "filas.h"

int main()
{
    Fila *fila = criarFila();
    imprimir(fila);
    printf ("\n");
    inserirElemento(fila,34);
    inserirElemento(fila,3);
    inserirElemento(fila,4);
    inserirElemento(fila,90);
    imprimir(fila);
    printf ("\n");
    remover(fila);
    imprimir(fila);
    printf ("\n");
    inserirElemento(fila,76);
    inserirElemento(fila,45);
    inserirElemento(fila,23);
    imprimir(fila);
    printf ("\n");
    remover(fila);
    imprimir(fila);
    printf ("\n");
    inserirElemento(fila,4);
    imprimir(fila);
    printf ("\n");
    remover(fila);
    imprimir(fila);
    printf ("\n");
    printf ("Primeiro elemento da fila: %.2f\n", primeiroElemento(fila));
    printf ("\n");
    furaFila(fila,4);
    imprimir(fila);
    printf ("\n");
    furaFila(fila,45);
    imprimir(fila);
    printf ("\n");

    return 0;
}
