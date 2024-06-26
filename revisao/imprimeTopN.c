# include <stdio.h>
# include <stdlib.h>

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
int particiona(int *v, int e, int d)
{
    int p = v[d], j, k;
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
int quickselect(int *v, int e, int d, int k)
{
    if (e < d)
    {
        int j = particiona(v, e, d);
        if (k == j) return v[j];
        if (k < j)
            quickselect(v, e, j - 1, k);
        if (k > j)
            quickselect(v, j + 1, d, k);
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
void imprimeTopN(int *v, int n, int m){
    int mEsimo = quickselect(v, 0, n-1, n-m);
    mergesort(v, mEsimo, n-1);
    for (int i=mEsimo; i < n; i++){
        printf("%d, ", v[i]);
    }
}

int main(){
    int v[] = {9,5,7,2,8,10,1};
    imprimeTopN(v, 7, 3);
}