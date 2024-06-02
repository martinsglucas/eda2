#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    char palavra[17];
    int votos;
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

int hash(char palavra[17]){
    int h=0;
    for (int i=0; i < strlen(palavra); i++){
        h += palavra[i];
    }
    return h;
}

// unsigned long hash(unsigned char *str){
//     unsigned long h = 5381;
//     int c;
//
//     while ((c = *str++)) h = ((h << 5) + h) + c; /* h * 33 + c */
//
//     return h;
// }

void inserir(TH *h, char palavra[17]){
    int pos = hash(palavra) % h->T;
    no *novo = (no *)malloc(sizeof(no));
    novo->votos = 1;
    strcpy(novo->palavra, palavra);
    novo->prox = NULL;

    no *atual = h->tab[pos];
    while (atual != NULL){
        if (strncmp(atual->palavra, palavra, 11) == 0){
            atual->votos += 1;
            free(novo);
            return;
        }
        if (atual->prox == NULL)
            break;
        atual = atual->prox;
    }
    atual->prox = novo;
}

no *buscar(TH *h, char palavra[17]){
    int pos = hash(palavra) % h->T;

    no *atual = h->tab[pos];

    while (atual->prox != NULL){
        if (strncmp(palavra, atual->prox->palavra, 17) == 0){
            return atual->prox;
        }
        atual = atual->prox;
    }
    return NULL;

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

void imprimeLista(no *r){
    while (r != NULL){
        printf("%s %d -> ", r->palavra, r->votos);
        r = r->prox;
    }
    printf("\\");
}

void imprimeTH(TH *h){
    for (int i = 0; i < h->T; i++){
        imprimeLista(h->tab[i]);
        printf("\n");
    }
}

int main(){
    int comando;
    char palavra[17];
    TH *h = criaTabela(65537); // 2^16 + 1

    while (scanf("%d %s", &comando, palavra) != EOF){
        no *p;
        switch (comando){
        case 1:
            inserir(h, palavra);
            break;
        case 2:
            p = buscar(h, palavra);
            if (p != NULL) printf("%d\n", p->votos);
            else printf("0\n");
            break;
        case 3:
            p = buscar(h, palavra);
            if (p != NULL) p->votos = 0;
            break;
        default:
            break;
        }
        // imprimeTH(h);
    }

    liberaTabela(h);
}