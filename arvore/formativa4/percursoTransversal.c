#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int buscar(char arr[], int inicio, int fim, char valor)
{
    for (int i = inicio; i <= fim; i++)
    {
        if (arr[i] == valor)
            return i;
    }
    return -1;
}

void imprimirPos(char em[], char pre[], int inicio, int fim, int *indicePre)
{
    if (inicio > fim)
        return;

    int indiceEm = buscar(em, inicio, fim, pre[*indicePre]);

    (*indicePre)++;

    imprimirPos(em, pre, inicio, indiceEm - 1, indicePre);

    imprimirPos(em, pre, indiceEm + 1, fim, indicePre);

    printf("%c", em[indiceEm]);
}

int main()
{

    int casos;
    scanf("%d", &casos);
    for (int i=0; i < casos; i++){
        int numNo;
        char pre[53], em[53];
        scanf("%d %s %s", &numNo, pre, em);
        int indicePre = 0;
        int n = strlen(em);
        imprimirPos(em, pre, 0, n - 1, &indicePre);
        printf("\n");
    }

    return 0;
}
