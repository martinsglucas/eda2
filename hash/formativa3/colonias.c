# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct no{
    long int id;
    char alimento[11];
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

void inserir(TH *h, long int id, char alimento[11]){
    int pos = id % h->T;
    no *novo = (no *)malloc(sizeof(no));
    novo->id = id;
    strcpy(novo->alimento, alimento);
    novo->prox = NULL;
    if (h->tab[pos] == NULL){
        h->tab[pos] = novo;
    } else {
        no *atual = h->tab[pos];
        while (atual != NULL){
            if (atual->id == id && strncmp(atual->alimento, alimento, 11) == 0){
                printf("%ld\n", id);
                return;
            }
            if (atual->prox == NULL) break;
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

// void inserir(TH *h, long int id, char alimento[11]){
//     int pos = id % h->T;
//     no *novo = (no *)malloc(sizeof(no));
//     novo->id = id;
//     strcpy(novo->alimento, alimento);
//     novo->prox = NULL;
//     if (h->tab[pos] == NULL){
//         h->tab[pos] = novo;
//     } else{
//         no *atual = h->tab[pos];
//         do{
//             if (atual->id == id && strncmp(atual->alimento, alimento, 11) == 0){
//                 printf("%ld\n", id);
//                 free(novo);
//                 return;
//             }
//             if (atual->prox == NULL) break;
//             atual = atual->prox;
//         } while (atual != NULL);
//         atual->prox = novo;
//     }
// }

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
        printf("%ld %s -> ", r->id, r->alimento);
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
    long int idColonia;
    char alimento[11];
    TH *h = criaTabela(1048583);

    while (scanf("%ld %s", &idColonia, alimento) != EOF){
        inserir(h, idColonia, alimento);
        // imprimeTH(h);

    }

    liberaTabela(h);
}