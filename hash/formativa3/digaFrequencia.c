#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int c, quantidade;
} no;

no *criaVetor(){
    no *vetor = (no *) calloc(128, sizeof(no));
    for (int i=0; i < 128; i++){
        vetor[i].c = i;
    }
    return vetor;
}

void intercala(no *v, int e, int m, int d)
{
    no *w = (no *)malloc(sizeof(no) * (d - e + 1));
    int i = e, j = m + 1, k = 0;
    while (i <= m && j <= d)
    {
        if (v[i].quantidade < v[j].quantidade ||
            (v[i].quantidade == v[j].quantidade && v[i].c < v[j].c))
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i <= m)
        w[k++] = v[i++];
    while (j <= d)
        w[k++] = v[j++];
    for (k = 0, i = e; i <= d; i++, k++)
        v[i] = w[k];
    free(w);
}

void mergesort(no *v, int e, int d)
{
    if (e < d)
    {
        int m = (e + d) / 2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}

int main(){
    char texto[1001];
    while (scanf("%s", texto) != EOF)
    {
        no *vetor = criaVetor();
        for (int i=0; i < strlen(texto); i++){
            vetor[texto[i]].quantidade += 1;
        }
        mergesort(vetor, 0, 127);
        for (int j=0; j < 128; j++){
            if (vetor[j].quantidade > 0)
                printf("%d %d\n", vetor[j].c, vetor[j].quantidade);
        }
        printf("\n");
    }
}