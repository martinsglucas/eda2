# include <stdio.h>

int main(){
    int n;
    int cont=0;
    scanf("%d", &n);
    long long int v[n], media=0;
    for(int i = 0; i < n; i++){
        scanf("%lld", &v[i]);
        media += v[i];
    }
    media /= n;
    for(int i = 0; i < n; i++){
        if (i == n-1 && v[i] > media){
            printf("%lld\n", v[i]);
            cont++;
            return 0;
        }
        if(v[i] > media){
            printf("%lld ", v[i]);
            cont++;
        }
    }
    if(cont == 0){
        printf("0\n");
    }
    return 0;
}