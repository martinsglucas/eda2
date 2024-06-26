# include <stdio.h>
# include <stdlib.h>

int min(int a, int b){
    return a < b ? a : b;
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertionSort(int *v, int e, int d)
{
    for (int i = e + 1; i <= d; i++)
    {
        int j = i;
        int key = v[j];
        while (j > e && v[j-1] > key)
        {
            v[j] = v[j-1];
            j--;
        }
        v[j] = key;
    }
}

int mediana3(int *v, int e, int d)
{
    int mediana = e + (d - e) / 2;
    if (v[mediana] < v[e])
    {
        troca(&v[e], &v[mediana]);
    }
    if (v[d] < v[mediana])
    {
        troca(&v[mediana], &v[d]);
    }
    if (v[mediana] < v[e])
    {
        troca(&v[e], &v[mediana]);
    }
    return mediana;
}

int particiona(int *v, int e, int d)
{
    int p, j, k;
    int indicePivo = mediana3(v, e, d);
    p = v[indicePivo];
    troca(&v[indicePivo], &v[d]);
    for (k = e, j = e; k < d; k++)
    {
        if (v[k] <= p)
        {
            troca(&v[k], &v[j]);
            j++;
        }
    }
    troca(&v[j], &v[d]);
    return j;
}

void quickselect(int *v, int e, int d, int k)
{
    if (e < d)
    {
        int j = particiona(v, e, d);
        if (k == j)
            return;
        if (k < j)
            quickselect(v, e, j - 1, k);
        if (k > j)
            quickselect(v, j + 1, d, k);
    }
}

void quicksort(int *v, int e, int d)
{
    if (e < d)
    {
        if (d - e < 32){
            insertionSort(v, e, d);
            return;
        }
        int j = particiona(v, e, d);
        quicksort(v, e, j - 1);
        quicksort(v, j + 1, d);
    }
}

void intercala(int *v, int e, int m, int d)
{
    int *w = (int *)malloc(sizeof(int) * (d - e + 1));
    int i = e, j = m + 1, k = 0;
    while (i <= m && j <= d)
    {
        if (v[i] < v[j])
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

void mergesort(int *v, int e, int d)
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
    int N, P, X;
    scanf("%d %d %d", &N, &P, &X);
    int ID[N];
    for (int i=0; i<N; i++){
        scanf("%d", &ID[i]);
    }
    int inicio = min(N-1, P*X);
    int fim = min(N-1, P*X+(X-1));
    quickselect(ID, 0, N-1, inicio);
    quickselect(ID, 0, N-1, fim);
    quicksort(ID, inicio, fim); 
    for (int i = inicio; i < min(N, P*X+X); i++)
    {
        printf("%d\n", ID[i]);
    }
    return 0;
}