#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha
{
    no *dado;
    struct pilha *prox;
} pilha;

void push(pilha *topo, no *dado)
{
    pilha *novo = (pilha *)malloc(sizeof(pilha));
    novo->dado = dado;
    novo->prox = topo->prox;
    topo->prox = novo;
}

no *pop(pilha *topo)
{
    pilha *aux = topo->prox;
    no *dado = aux->dado;
    topo->prox = topo->prox->prox;
    free(aux);
    return dado;
}

void em_ordem(no *raiz)
{
    pilha *p = (pilha *)calloc(1, sizeof(pilha));

    while (1)
    {
        while (raiz != NULL)
        {
            push(p, raiz);
            raiz = raiz->esq;
        }

        if (p->prox == NULL)
        {
            break;
        }

        raiz = pop(p);
        printf("%d ", raiz->dado);

        raiz = raiz->dir;   
    }

    free(p);
}

// int main()
// {
//     no *raiz = (no *)malloc(sizeof(no));
//     no *n1 = (no *)malloc(sizeof(no));
//     no *n2 = (no *)calloc(1, sizeof(no));
//     no *n3 = (no *)calloc(1, sizeof(no));
//     no *n4 = (no *)calloc(1, sizeof(no));
//     no *n5 = (no *)calloc(1, sizeof(no));
//     no *n6 = (no *)calloc(1, sizeof(no));
//     no *n7 = (no *)calloc(1, sizeof(no));
//     no *n8 = (no *)calloc(1, sizeof(no));

//     raiz->dado = 2;
//     n1->dado = 5;
//     n2->dado = 7;
//     n3->dado = 3;
//     n4->dado = 8;
//     n5->dado = 1;
//     n6->dado = 6;
//     n7->dado = 4;
//     n8->dado = 9;

//     raiz->esq = n1;
//     raiz->dir = n2;
//     n1->esq = n3;
//     n1->dir = n4;
//     n4->esq = n7;
//     n2->esq = n5;
//     n2->dir = n6;
//     n5->dir = n8;

//     n3->esq = NULL;
//     n3->dir = NULL;
//     n7->esq = NULL;
//     n7->dir = NULL;
//     n8->esq = NULL;
//     n8->dir = NULL;
//     n6->esq = NULL;
//     n6->dir = NULL;

//     em_ordem(raiz);

//     return 0;
// }