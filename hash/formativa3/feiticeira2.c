#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    long int id, quantidade;
    struct no *prox;
} no;

typedef struct
{
    no **tab;
    int T;
} TH;

TH *criaTabela(int T)
{
    TH *h = (TH *)malloc(sizeof(TH));
    h->T = T;
    h->tab = (no **)calloc(T,sizeof(no *));
    return h;
}

void inserir(TH *h, unsigned long int id, long int quantidade)
{
    int pos = id % h->T;

    no *atual = h->tab[pos];

    while (atual != NULL && atual->id != id)
    {
        atual = atual->prox;
    }

    if (atual != NULL)
    {
        atual->quantidade += quantidade;
        if (atual->quantidade < 0)
        {
            atual->quantidade = 0;
        }
    }
    else
    {
        no *novo = (no *)malloc(sizeof(no));
        novo->id = id;
        novo->quantidade = quantidade > 0 ? quantidade : 0;
        novo->prox = h->tab[pos];
        h->tab[pos] = novo;
    }
}

long long int quantidadeItens(TH *h)
{
    long long int quantidade = 0;
    for (int i = 0; i < h->T; i++)
    {
        no *atual = h->tab[i];
        while (atual != NULL)
        {
            quantidade += atual->quantidade;
            atual = atual->prox;
        }
    }
    return quantidade;
}

void liberaTabela(TH *h)
{
    for (int i = 0; i < h->T; i++)
    {
        no *atual = h->tab[i];
        while (atual != NULL)
        {
            no *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(h->tab);
    free(h);
}

int main()
{
    int N;
    unsigned long int idItem;
    long int quantidade;
    scanf("%d", &N);
    TH *h = criaTabela(262147);

    for (int i = 0; i < N; i++)
    {
        scanf("%lu %ld", &idItem, &quantidade);
        inserir(h, idItem, quantidade);
    }

    printf("%lld\n", quantidadeItens(h));
    liberaTabela(h);
    return 0;
}
