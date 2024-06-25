
#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq, *dir;
} no;


no *remover(no *r, int x){


    if (r == NULL) return NULL;

    if (x < r->chave)
    {
        r->esq = remover(r->esq, x);
    }
    else if (x > r->chave)
    {
        r->dir = remover(r->dir, x);
    }
    else {
        if (r->esq != NULL){
            no *p = r, *q = r->esq;
            // encontrar o maior da subárvore esquerda
            while (q->dir != NULL){
                p = q;
                q = q->dir;
            }
            r->chave = q->chave;
            if (p == r) p->esq = q->esq;
            else p->dir = q->esq;
            free(q);
            return r;
        }
        else{
            no *q = r->dir;
            free(r);
            return q;
        }
    }
}

// // Função auxiliar para criar um novo nó
// no *criarNo(int chave)
// {
//     no *novoNo = (no *)malloc(sizeof(no));
//     novoNo->chave = chave;
//     novoNo->esq = NULL;
//     novoNo->dir = NULL;
//     return novoNo;
// }

// // Função auxiliar para inserir um novo nó na árvore
// no *inserir(no *r, int chave)
// {
//     if (r == NULL)
//     {
//         return criarNo(chave);
//     }
//     if (chave < r->chave)
//     {
//         r->esq = inserir(r->esq, chave);
//     }
//     else if (chave > r->chave)
//     {
//         r->dir = inserir(r->dir, chave);
//     }
//     return r;
// }

// // Função auxiliar para imprimir a árvore em ordem
// void imprimirEmOrdem(no *r)
// {
//     if (r != NULL)
//     {
//         imprimirEmOrdem(r->esq);
//         printf("%d ", r->chave);
//         imprimirEmOrdem(r->dir);
//     }
// }

// // Função principal para testar a remoção
// int main()
// {
//     no *r = NULL;
//     r = inserir(r, 50);
//     r = inserir(r, 30);
//     r = inserir(r, 70);
//     r = inserir(r, 20);
//     r = inserir(r, 40);
//     r = inserir(r, 60);
//     r = inserir(r, 80);

//     printf("Árvore em ordem antes da remoção: ");
//     imprimirEmOrdem(r);
//     printf("\n");

//     r = remover(r, 50);

//     printf("Árvore em ordem após a remoção: ");
//     imprimirEmOrdem(r);
//     printf("\n");

//     return 0;
// }
