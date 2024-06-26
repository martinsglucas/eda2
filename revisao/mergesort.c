# include <stdio.h>
# include <stdlib.h>

/**
 * @brief Função para intercalar subarrays em um array para o algoritmo mergesort.
 *
 * @param *v
 * @param e indice da esquerda
 * @param m indice do meio
 * @param d indice da direita
 *
 * @details Esta função intercala dois subarrays de um array de inteiros (v[e..m] e v[m+1..d]) em um único
 * subarray ordenado. Assume-se que os subarrays v[e..m] e v[m+1..d] já estão ordenados.
 */
void intercala(int *v, int e, int m, int d){
    int *w = (int *)malloc(sizeof(int) * (d - e + 1));
    int i = e, j = m + 1, k = 0;
    while (i <= m && j <= d)
    {
        if (v[i] < v[j])
            w[k++] = v[i++];
        else
            w[k++] = v[j++];
    }
    while (i <= m)
        w[k++] = v[i++];
    while (j <= d)
        w[k++] = v[j++];
    // esses ultimos dois laços sao mutuamente exclusivos
    for (k = 0, i = e; i <= d; i++, k++)
        v[i] = w[k];
    free(w);
}

/**
 * @brief Função para ordenar um array de inteiros utilizando o algoritmo mergesort.
 *
 * @param v
 * @param e indice da esquerda
 * @param d indice da direita
 *
 * @details Esta função ordena um array de inteiros utilizando o algoritmo mergesort.
 */
void mergesort(int *v, int e, int d){
    if (e < d)
    {
        int m = (e + d) / 2;
        mergesort(v, e, m);
        mergesort(v, m + 1, d);
        intercala(v, e, m, d);
    }
}