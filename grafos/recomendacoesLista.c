#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int v;
    struct no *prox;
} no;

typedef struct
{
    no **adj;
    int n;
} grafo;

grafo *cria_grafo(int n)
{
    grafo *g = (grafo *)malloc(sizeof(grafo));
    g->n = n;
    g->adj = (no **)calloc(n, sizeof(no *));
    return g;
}

void insere_aresta(grafo *g, int u, int v)
{
    no *novo_u = (no *)malloc(sizeof(no));
    novo_u->v = v;
    novo_u->prox = NULL;

    if (g->adj[u] == NULL)
    {
        g->adj[u] = novo_u;
    }
    else
    {
        no *ultimo_u = g->adj[u];
        while (ultimo_u->prox != NULL)
        {
            ultimo_u = ultimo_u->prox;
        }
        ultimo_u->prox = novo_u;
    }

    no *novo_v = (no *)malloc(sizeof(no));
    novo_v->v = u;
    novo_v->prox = NULL;

    if (g->adj[v] == NULL)
    {
        g->adj[v] = novo_v;
    }
    else
    {
        no *ultimo_v = g->adj[v];
        while (ultimo_v->prox != NULL)
        {
            ultimo_v = ultimo_v->prox;
        }
        ultimo_v->prox = novo_v;
    }
}

void imprime_recomendacoes(grafo *g, int u)
{
    int *rec = calloc(g->n, sizeof(int));
    for (no *v = g->adj[u]; v != NULL; v = v->prox)
    {
        for (no *w = g->adj[v->v]; w != NULL; w = w->prox)
        {
            rec[w->v] = 1;
        }
        rec[v->v] = 0;
    }
    for (int i = 0; i < g->n; i++)
    {
        if (rec[i])
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    free(rec);
}

void free_grafo(grafo *g)
{
    for (int i = 0; i < g->n; i++)
    {
        no *curr = g->adj[i];
        while (curr != NULL)
        {
            no *temp = curr;
            curr = curr->prox;
            free(temp);
        }
    }
    free(g->adj);
    free(g);
}

int main()
{
    grafo *g = cria_grafo(5);
    insere_aresta(g, 0, 1);
    insere_aresta(g, 0, 2);
    insere_aresta(g, 1, 3);
    insere_aresta(g, 2, 3);
    insere_aresta(g, 3, 4);

    imprime_recomendacoes(g, 0);
    imprime_recomendacoes(g, 1);

    free_grafo(g);

    return 0;
}
