# include <stdio.h>
# include <stdlib.h>
# include <string.h>
typedef enum { VERMELHO, PRETO } cor;

typedef struct no{
    long int id;
    char alimento[11];
    cor cor;
    struct no *esq, *dir;
} no;

typedef struct{
    no **tab;
    int T;
} TH;

TH *criaTabela(int T){
    TH *h = (TH *)malloc(sizeof(TH));
    h->T = T;
    h->tab = (no **)calloc(T, sizeof(no *));
    // h->tab = (no **)malloc(T * sizeof(no *));
    // for (int i = 0; i < h->T; i++){
    //     h->tab[i] = (no *)calloc(1, sizeof(no));
    // }
    return h;
}

int ehPreto(no *r)
{
    if (r == NULL)
        return 1;
    else
        return r->cor == PRETO;
}
int ehVermelho(no *r)
{
    if (r == NULL)
        return 0;
    else
        return r->cor == VERMELHO;
}
no *rotacaoEsquerda(no *r)
{
    no *x = r->dir;
    x->cor = r->cor;
    r->cor = VERMELHO;
    r->dir = x->esq;
    x->esq = r;
    return x;
}
no *rotacaoDireita(no *r)
{
    no *x = r->esq;
    x->cor = r->cor;
    r->cor = VERMELHO;
    r->esq = x->dir;
    x->dir = r;
    return x;
}
void sobeCor(no *r)
{
    r->esq->cor = r->dir->cor = PRETO;
    r->cor = VERMELHO;
}
no *corrige(no *r)
{
    if (ehPreto(r->esq) && ehVermelho(r->dir))
        r = rotacaoEsquerda(r);
    // o segundo if não tem problema de definição: caso r->esq seja NULL, já retorna Falso
    if (ehVermelho(r->esq) && ehVermelho(r->esq->esq))
        r = rotacaoDireita(r);
    if (ehVermelho(r->esq) && ehVermelho(r->dir))
        sobeCor(r);
    return r;
}
no *insere(no *r, long int id, char alimento[11])
{
    if (r == NULL)
    {
        no *novo = (no *)calloc(1, sizeof(no));
        novo->id = id;
        strncpy(novo->alimento, alimento, 11);
        novo->cor = VERMELHO;
        return novo;
    }
    else if (id == r->id && strncmp(alimento, r->alimento, 11) == 0)
    {
        printf("%ld\n", id);
        return r;
    }
    else if (id < r->id || (id == r->id && strncmp(alimento, r->alimento, 11) < 0))
        r->esq = insere(r->esq, id, alimento);
    else
        r->dir = insere(r->dir, id, alimento);
    /* correção da subárvore com raiz r */
    r = corrige(r);
    return r;
}

no *insere_novo(no *r, long int id, char alimento[11])
{
    r = insere(r, id, alimento);
    r->cor = PRETO;
    return r;
}
void liberaArvore(no *raiz)
{
    if (raiz != NULL)
    {
        liberaArvore(raiz->esq);
        liberaArvore(raiz->dir);
        free(raiz);
    }
}

void liberaTabela(TH *h)
{
    for (int i = 0; i < h->T; i++)
    {
        liberaArvore(h->tab[i]);
    }
    free(h->tab);
    free(h);
}

void imprimeArvore(no *r){
    if (r != NULL){
        imprimeArvore(r->esq);
        printf("(%d %s) ", r->id, r->alimento);
        imprimeArvore(r->dir);
    }
}
void imprimeTH(TH *h){
    for (int i = 0; i < h->T; i++){
        imprimeArvore(h->tab[i]);
        printf("\n");
    }
}

int main(){
    long int idColonia;
    char alimento[11];
    TH *h = criaTabela(1048583);
    // TH *h = criaTabela(10);

    while (scanf("%ld %s", &idColonia, alimento) != EOF){
        // inserir(h, idColonia, alimento);
        int pos = idColonia % h->T;
        // insere(h->tab[pos], idColonia, alimento);
        h->tab[pos] = insere_novo(h->tab[pos], idColonia, alimento);
        // imprimeTH(h);
        // printf("\n");

    }

    liberaTabela(h);
}