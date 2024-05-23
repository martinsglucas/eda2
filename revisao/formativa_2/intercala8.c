# include <stdio.h>
# include <stdlib.h>

int *intercala2(int *a, int ta, int *b, int tb)
{
    int *w = (int *)malloc(sizeof(int) * (ta+tb));
    int i = 0, j = 0, k = 0;
    while (i < ta && j < tb)
    {
        if (a[i] < b[j])
            w[k++] = a[i++];
        else
            w[k++] = b[j++];
    }
    while (i < ta) w[k++] = a[i++];
    while (j < tb) w[k++] = b[j++];
    return w;
}

int *intercala4(int *a, int ta, int *b, int tb, int *c, int tc, int *d, int td){
    int *ab = intercala2(a, ta, b, tb);
    int *cd = intercala2(c, tc, d, td);
    int tab = ta+tb, tcd = tc+td;
    int *w = intercala2(ab, tab, cd, tcd);
    return w;
}

int *intercala8(int *a, int ta, int *b, int tb, int *c, int tc, int *d, int td, 
                int *e, int te, int *f, int tf, int *g, int tg, int *h, int th)
{
    int *abcd = intercala4(a, ta, b, tb, c, tc, d, td);
    int *efgh = intercala4(e, te, f, tf, g, tg, h, th);
    int *w = intercala2(abcd, ta+tb+tc+td, efgh, te+tf+tg+th);
    return w;
}

int main(){
    int *v[8];
    int tam[8], tamTotal=0;
    for (int i=0; i<8; i++){
        scanf("%d", &tam[i]);
        tamTotal += tam[i];
        v[i] = malloc(sizeof(int)*tam[i]);
        for (int j=0; j < tam[i]; j++){
            scanf("%d", &v[i][j]);
        }

    }
    int *w = intercala8(v[0], tam[0], v[1], tam[1], v[2], tam[2], v[3], tam[3], v[4], tam[4], v[5], tam[5], v[6], tam[6], v[7], tam[7]);
    
    for (int i=0; i < tamTotal; i++){
        printf("%d ", w[i]);
    }
}