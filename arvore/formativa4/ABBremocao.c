#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int chave;
    struct no *esq, *dir;
} no;

no *encontrarAntecessor(no *r)
{
    no *atual = r->esq;
    while (atual && atual->dir != NULL)
    {
        atual = atual->dir;
    }
    return atual;
}

no *remover(no *r, int x)
{
    if (r == NULL)
    {
        return NULL;
    }

    if (x < r->chave)
    {
        r->esq = remover(r->esq, x);
    }
    else if (x > r->chave)
    {
        r->dir = remover(r->dir, x);
    }
    else
    {
        if (r->esq == NULL)
        {
            // O nó não tem filho esquerdo, substituir pelo filho direito
            no *temp = r->dir;
            free(r);
            return temp;
        }
        else if (r->dir == NULL)
        {
            // O nó não tem filho direito, substituir pelo filho esquerdo
            no *temp = r->esq;
            free(r);
            return temp;
        }

        // O nó tem dois filhos, encontrar o antecessor
        no *antecessor = encontrarAntecessor(r);
        // Substituir o valor do nó pelo valor do antecessor
        r->chave = antecessor->chave;
        // Remover o antecessor
        r->esq = remover(r->esq, antecessor->chave);
    }

    return r;
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
