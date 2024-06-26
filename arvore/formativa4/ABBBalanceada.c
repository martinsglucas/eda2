#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int id;
    struct no *esq;
    struct no *dir;
} no;


void adicionaFilho(no *pai, no *filho){
    if (!pai->esq){
        pai->esq = filho;
    } else {
        pai->dir = filho;
    }
}

int altura(no *raiz){
    if (!raiz) return 0;
    int alturaEsq = altura(raiz->esq);
    int alturaDir = altura(raiz->dir);
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int verificaBalanceamento(no *raiz, int *balanceada){
    if (!raiz) return 0;
    int alturaEsq = verificaBalanceamento(raiz->esq, balanceada);
    int alturaDir = verificaBalanceamento(raiz->dir, balanceada);
    if (abs(alturaEsq - alturaDir) > 1) *balanceada = 0;
    return (alturaEsq > alturaDir ? alturaEsq : alturaDir) + 1;
}

int main()
{
    int N;
    scanf("%d", &N);

    no **nos = (no **)malloc(N * sizeof(no *));
    for (int i = 0; i < N; ++i){
        no *novo = (no *)malloc(sizeof(no));
        novo->id = i+1;
        novo->esq = novo->dir = NULL;
        nos[i] = novo;
    }

    for (int i = 1; i < N; ++i){
        int pai;
        scanf("%d", &pai);
        adicionaFilho(nos[pai - 1], nos[i]);
    }

    int balanceada = 1;
    verificaBalanceamento(nos[0], &balanceada);

    if (balanceada) printf("Sim\n");
    else printf("Nao\n");

    for (int i = 0; i < N; ++i)
    {
        free(nos[i]);
    }
    free(nos);

    return 0;
}
