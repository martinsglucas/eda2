# include <stdio.h>
# include <stdlib.h>

typedef struct no{
    int dado;
    struct no *prox;
} no;

typedef struct {
    no **tab;
    int T;
} TH;

TH *criaTabela(int T)
{
    TH *h = (TH *)malloc(sizeof(TH));
    h->T = T;
    h->tab = (no **)malloc(T * sizeof(no *));
    for (int i=0; i < h->T; i++){
        h->tab[i] = (no *) calloc(1, sizeof(no));
        h->tab[i]->dado = i;
    }
    return h;
}

void inserir(TH *h, int x){
    int pos = x % h->T;
    no *novo = (no *) malloc(sizeof(no));
    novo->dado = x;
    novo->prox = NULL;
    if (h->tab[pos] == NULL){
        h->tab[pos] = novo;
    } else {
        no *atual = h->tab[pos];
        while (atual->prox != NULL)
        {
            atual = atual->prox;
        }
        atual->prox = novo;
    }
}

void imprimeLista(no *r){
    while (r != NULL){
        printf("%d -> ", r->dado);
        r = r->prox;
    }
    printf("\\");
}
void imprimeTH(TH *h){
    for (int i=0; i < h->T; i++){
        imprimeLista(h->tab[i]);
        printf("\n");
    }
}

int main(){
    int casos;
    scanf("%d", &casos);
    for (int i=0; i < casos; i++){
        int tam, chaves;
        scanf("%d %d", &tam, &chaves);
        TH *h = criaTabela(tam);
        for (int j=0; j < chaves; j++){
            int chave;
            scanf("%d", &chave);
            inserir(h, chave);
        }
        imprimeTH(h);
        printf("\n");
    }
}