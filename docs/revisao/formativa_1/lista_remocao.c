/*
 * Sua tarefa nesse exercício é implementar a operação de remoção da lista encadeada encabeçada por le. Para tanto, você deve submeter um arquivo contendo apenas:
 * Os #include necessários para execução das instruções utilizadas no seu código.
 * A definição da struct celula.
 * Uma função que remove o elemento imediatamente seguinte do ponteiro p, com protótipo int remove_depois (celula *p); Sua função deve ser capaz de lidar com o(s) caso(s) em que não seja possível remover o elemento seguinte a p.
 * Uma função que remove a primeira ocorrência de x da lista encadeada, cujo protótipo é void remove_elemento (celula *le, int x);
 * Uma função que remove todas as ocorrências de x da lista encadeada, cujo protótipo é void remove_todos_elementos (celula *le, int x);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p){
    if (p->prox == NULL){
        return 0;
    }
    celula *lixo = p->prox;
    p->prox = lixo->prox;
    free(lixo);
    return 1;
}

void remove_elemento (celula *le, int x){
    celula *pAux = le;
    while (pAux->prox != NULL){
        if (pAux->prox->dado == x){
            celula *lixo = pAux->prox;
            pAux->prox = lixo->prox;
            free(lixo);
            return;
        }
        pAux = pAux->prox;
    }
}

void remove_todos_elementos (celula *le, int x){
    celula *pAux = le;
    while (pAux->prox != NULL){
        if (pAux->prox->dado == x){
            celula *lixo = pAux->prox;
            pAux->prox = lixo->prox;
            free(lixo);
        } else {
            pAux = pAux->prox;
        }
    }
}
