# include <stdio.h>
# include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le){
    celula *ptr = le->prox;
    while (ptr != NULL){
        printf("%d -> ", ptr->dado);
        ptr = ptr->prox;
    }
    printf("NULL\n");
}
void imprime_rec(celula *le){
    if (le->prox == NULL){
        printf("NULL\n");
        return;
    }
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);

}