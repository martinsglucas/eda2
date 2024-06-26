# include <stdio.h>
# include <stdlib.h>

typedef struct no{
    int chave;
    struct no *esq, *dir;
} no;

no *minimo(no *r){
    while (r->esq != NULL){
        r = r->esq;
    }
    return r;
}

// int main()
// {
//     no *n1 = (no *)calloc(1, sizeof(no));
//     no *n2 = (no *)calloc(1, sizeof(no));
//     no *n3 = (no *)calloc(1, sizeof(no));
//     no *n4 = (no *)calloc(1, sizeof(no));
//     no *n5 = (no *)calloc(1, sizeof(no));
//     no *n6 = (no *)calloc(1, sizeof(no));
//     no *n7 = (no *)calloc(1, sizeof(no));
//     no *n8 = (no *)calloc(1, sizeof(no));
//     no *n9 = (no *)calloc(1, sizeof(no));

//     n1->chave = 1;
//     n2->chave = 2;
//     n3->chave = 3;
//     n4->chave = 4;
//     n5->chave = 5;
//     n6->chave = 6;
//     n7->chave = 7;
//     n8->chave = 8;
//     n9->chave = 9;

//     n5->esq = n3;
//     n5->dir = n8;
//     n3->esq = n2;
//     n2->esq = n1;
//     n3->dir = n4;
//     n8->esq = n6;
//     n6->dir = n7;
//     n8->dir = n9;

//     printf("%d\n", minimo(n5)->chave);

//     return 0;
// }