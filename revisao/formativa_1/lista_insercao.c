/*
 * Sua tarefa nesse exercício é implementar a operação de inserção na lista encadeada encabeçada por le. Para tanto, você deve submeter um arquivo contendo apenas:
 * Os #include necessários para execução das instruções utilizadas no seu código.
 * A definição da struct celula.
 * Uma função que insere um elemento x no início da lista encadeada, cujo protótipo deve ser: void insere_inicio (celula *le, int x);
 * Uma função que insere um elemento x imediatamente antes da primeira ocorrência de um elemento y na lista encadeada. Se y não estiver na lista encadeada, x deve ser inserido ao final. O protótipo dessa função deve ser void insere_antes (celula *le, int x, int y);
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){
    celula *novoNo = malloc(sizeof(celula));
    novoNo->dado = x;
    novoNo->prox = le->prox;
    le->prox = novoNo;
}

void insere_antes (celula *le, int x, int y){
    celula *pAux = le;
    while (pAux->prox != NULL){
        if (pAux->prox->dado == y){
            celula *novoNo = malloc(sizeof(celula));
            novoNo->dado = x;
            novoNo->prox = pAux->prox;
            pAux->prox = novoNo;
            return;
        }
        pAux = pAux->prox;
    }
    celula *novoNo = malloc(sizeof(celula));
    novoNo->dado = x;
    novoNo->prox = NULL;
    pAux->prox = novoNo;
}