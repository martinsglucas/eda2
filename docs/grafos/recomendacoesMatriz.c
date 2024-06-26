#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **adj;
    int n;
} grafo;

grafo *cria_grafo(int n)
{
    grafo *g = (grafo *)malloc(sizeof(grafo));
    g->n = n;
    g->adj = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        g->adj[i] = (int *)calloc(n, sizeof(int));
    }
    return g;
}

void insere_aresta(grafo *g, int u, int v)
{
    g->adj[u][v] = g->adj[v][u] = 1;
}

void imprime_recomendacoes(grafo *g, int u)
{
    int *rec = calloc(g->n, sizeof(int));
    for (int v = 0; v < g->n; v++)
    {
        if (g->adj[v][u])
        {
            for (int w = 0; w < g->n; w++)
            {
                if (g->adj[w][v] && !g->adj[w][u])
                {
                    rec[w] = 1; // se quisermos guardar a intensidade da recomendação podemos incrementar rec[w]
                }
            }
        }
    }
    for (int w = 0; w < g->n; w++)
    {
        if (rec[w])
        {
            printf("%d ", w);
        }
    }
    printf("\n");
    free(rec);
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

    // Free the graph
    for (int i = 0; i < g->n; i++)
    {
        free(g->adj[i]);
    }
    free(g->adj);
    free(g);

    return 0;
}
