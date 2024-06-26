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

no *peek(pilha *p){
    return p->prox->dado;
}

int isEmpty(pilha *p){
    return p->prox == NULL ? 1 : 0;
}

void pos_ordem(no *raiz)
{
    pilha *p = (pilha *)calloc(1, sizeof(pilha));
    no *ultimoVisitado = NULL;

    while (!isEmpty(p) || raiz != NULL)
    {
        if (raiz != NULL)
        {
            push(p, raiz);
            raiz = raiz->esq;
        }
        else
        {
            no *topo = peek(p);
            if (topo->dir != NULL && ultimoVisitado != topo->dir)
            {
                raiz = topo->dir;
            }
            else
            {
                printf("%d ", topo->dado);
                ultimoVisitado = pop(p);
            }
        }
    }

    free(p);
}

// void pos_ordem(no *raiz)
// {
//     pilha *p = (pilha *)calloc(1, sizeof(pilha));
//     pilha *r = (pilha *)calloc(1, sizeof(pilha));

//     push(p, raiz);
//     while (p->prox != NULL)
//     {
//         raiz = pop(p);
//         push(r, raiz);

//         if (raiz->esq != NULL)
//             push(p, raiz->esq);
//         if (raiz->dir != NULL)
//             push(p, raiz->dir);
//     }

//     while (r->prox != NULL)
//     {
//         raiz = pop(r);
//         printf("%d ", raiz->dado);
//     }

//     free(p);
//     free(r);
// }

// void posOrdemRecursivo(no *raiz){
//     if (raiz == NULL) return ;
//     posOrdemRecursivo(raiz->esq);
//     posOrdemRecursivo(raiz->dir);
//     printf("%d ", raiz->dado);
// }

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

//     pos_ordem(raiz);
//     printf("\n");
//     posOrdemRecursivo(raiz);
//     printf("\n");

//     return 0;
// }