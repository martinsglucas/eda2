/*
 * Sua tarefa nesse exercício é implementar a operação de busca na lista encadeada encabeçada por le. Para tanto, você deve submeter um arquivo contendo apenas:
 * Os #include necessários para execução das instruções utilizadas no seu código.
 * A definição da struct celula.
 * Uma função que procura pela primeira ocorrência do elemento na lista encadeada e devolve um ponteiro para a célula que o contém. O protótipo desta função deve ser: celula *busca (celula *le, int x);
 * Uma função que faz o mesmo que o item 3, mas recursiva, com protótipo: celula *busca_rec (celula *le, int x);
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
} celula;

celula *busca (celula *le, int x){
    celula *pAux = le->prox;
    while (pAux != NULL){
        if (pAux->dado == x){
            return pAux;
        }
        pAux = pAux->prox;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x){
    if (le->prox == NULL){
        return NULL;
    }
    if (le->prox->dado == x){
        return le->prox;
    }
    return busca_rec(le->prox, x);
}