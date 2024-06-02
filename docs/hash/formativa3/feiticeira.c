# include <stdio.h>
# include <stdlib.h>
# include <string.h>

// Time Limit Exceeded,50p

/*
ENUNCIADO

ENTRADA
Na primeira linha 𝑁 tal que 1 ≤ 𝑁 ≤ 2 ^18 seja a quantidade de itens. Nas 𝑁 linhas seguintes, para cada item,
separado por espaço será dado: 1. uma identificação única (ID): 𝐾 ∈ 𝑁 tal que -2^29 ≤ 𝐾 ≤ 2^29; 2. quantidade do item tal que
−2^12 ≤ 𝑄 ≤ 2^12, e se 𝑄 < 0, retire da bolsa; senão e 𝑄 > 0, adicione à bolsa.
SAIDA
Imprima a quantidade de itens restantes (𝑀) na bolsa.

*/

typedef struct no{
    long int id, quantidade;
    struct no *prox;
} no;

typedef struct{
    no **tab;
    int T;
} TH;

TH *criaTabela(int T){
    TH *h = (TH *)malloc(sizeof(TH));
    h->T = T;
    h->tab = (no **)malloc(T * sizeof(no *));
    for (int i = 0; i < h->T; i++){
        h->tab[i] = (no *)calloc(1, sizeof(no));
    }
    return h;
}

void inserir(TH *h, unsigned long int id, long int quantidade){
    int pos = id % h->T;
    no *novo = (no *)malloc(sizeof(no));
    novo->id = id;
    novo->quantidade = quantidade;
    novo->prox = NULL;
        
    no *atual = h->tab[pos];
    while(atual->prox != NULL){
        if (atual->prox->id == id){
            atual->prox->quantidade += quantidade;
            atual->prox->quantidade = atual->prox->quantidade < 0 ? 0 : atual->prox->quantidade;
            return;
        }
        atual = atual->prox;
    }
    atual->prox = novo;
}


long long int quantidadeItens(TH *h){
    long long int quantidade = 0;
    for (int i=0; i < h->T; i++){
        no *r = h->tab[i]->prox;
        while (r != NULL){
            quantidade += r->quantidade;
            r = r->prox;
        }
    }
    return quantidade;

}

void liberaTabela(TH *h){
    for (int i = 0; i < h->T; i++){
        no *atual = h->tab[i];
        while (atual != NULL){
            no *temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(h->tab);
    free(h);
}

// void imprimeLista(no *r){
//     while (r != NULL){
//         printf("%ld %ld -> ", r->id, r->quantidade);
//         r = r->prox;
//     }
//     printf("\\");
// }

// void imprimeTH(TH *h){
//     for (int i = 0; i < h->T; i++){
//         imprimeLista(h->tab[i]);
//         printf("\n");
//     }
// }

int main(){
    int N;
    unsigned long int idItem;
    long int quantidade;
    scanf("%d", &N);
    TH *h = criaTabela(262147);

    for (int i=0; i<N; i++){
        scanf("%lu %ld", &idItem, &quantidade);
        inserir(h, idItem, quantidade);

    }
    printf("%lld\n",quantidadeItens(h));
    liberaTabela(h);
}