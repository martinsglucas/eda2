# include <stdio.h>
# include <stdlib.h>

void intercala (int *v, int e, int m, int d){
    int *vAux = (int *) malloc(sizeof(int)*(d-e+1));
    int i = e, j=m+1, k=0;
    while (i <= m && j <= d){
        if (v[i] < v[j]) vAux[k++] = v[i++];
        else vAux[k++] = v[j++];
    }
    while (i <= m) vAux[k++] = v[i++];
    while (j <= d) vAux[k++] = v[j++];
    for (int k=0, i = e; i <= d; k++, i++) v[i] = vAux[k];
    free(vAux);
}
void merge(int *v, int e, int d){
    if (e < d){
        int m = (e+d)/2;
        merge(v, e, m);
        merge(v, m+1, d);
        intercala(v, e, m, d);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    // int v[n];
    int *v = (int *) malloc(sizeof(int)*n);
    for (int i=0; i < n; i++){
        scanf("%d", &v[i]);
    }
    merge(v, 0, n-1);
    printf("%d", v[0]);
    for (int i=1; i < n; i++){
        printf(" %d", v[i]);
    }
    printf("\n");
}