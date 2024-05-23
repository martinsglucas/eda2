/*
 * Dois professores (PA e PB) combinaram de encontrar-se no Centro Politécnico (CP) às 15h00 numa quarta-feira. Como os professores são grandes estudiosos de movimentos retilíneos uniformes, pensaram em aplicar um de seus estudos mais recentes. Os dois professores dividiram o CP em um grande quadriculado. A cada passo, cada professor escolhe uma direção (Norte, Sul, Leste ou Oeste) e anda até o quadrado imediatamente vizinho na direção escolhida. O quadriculado do CP é um plano cartesiano com origem em (1,1) como sendo o limite inferior esquerdo e as direções Norte e Sul andam no eixo Y, e as direções Leste e Oeste no eixo X. As direções Norte e Leste incrementam a posição de seus respectivos eixos e Sul e Oeste fazem o oposto. Dada uma sequência de passos, você deve dizer se os professores se encontraram em algum momento, i.e, se eles ficaram no mesmo quadrado ao mesmo tempo, se algum professor saiu do CP ou se eles não se encontraram.
 * A primeira linha da entrada contém dois inteiros N e M que indicam respectivamente o número de colunas e o número de linhas do CP
 * A segunda linha contém um inteiro P que indica quantos movimentos cada professor fez. Depois são apresentadas P linhas contendo dois números inteiros A e B, indicando a direção tomada pelos professores PA e PB, respectivamente, naquele passo. Os inteiros A e B.
 * podem assumir os seguintes valores:
    1 (Norte),
    2 (Sul),
    3 (Leste) e
    4 (Oeste)
 * O professor PA começa na posição (1,1) e o professor PB na posição (N,M).
 * O programa deve imprimir
 * Caso os professores tenham se encontrado: as coordenadas do encontro e o passo em que ocorreu. Exemplo: Encontraram-se na posicao (5,1) no passo 4
 * Caso o(s) professor(es) tenha(m) saído do CP: as coordenadas em que saíram e o passo em que ocorreu. Se ambos professores saíram no mesmo passo imprima apenas a informação sobre o professor PA. Exemplo: PA saiu na posicao (0,3) no passo 3
 * Caso nenhuma das anteriores ocorra, imprimir: “Nao se encontraram”.
 */

# include <stdio.h>
# include <stdlib.h>

typedef struct {
    int x;
    int y;
} Professor;

int main(){
    int N, M, P;
    scanf("%d %d", &N, &M);
    scanf("%d", &P);
    Professor PA = {1, 1};
    Professor PB = {N, M};
    for (int i = 1; i <= P; i++){
        int A, B;
        scanf("%d %d", &A, &B);
        switch (A){
            case 1:
                PA.y++;
                break;
            case 2:
                PA.y--;
                break;
            case 3:
                PA.x++;
                break;
            case 4:
                PA.x--;
                break;
        }
        switch (B){
            case 1:
                PB.y++;
                break;
            case 2:
                PB.y--;
                break;
            case 3:
                PB.x++;
                break;
            case 4:
                PB.x--;
                break;
        }
        if (PA.x == PB.x && PA.y == PB.y){
            printf("Encontraram-se na posicao (%d,%d) no passo %d\n", PA.x, PA.y, i);
            return 0;
        }
        if (PA.x < 1 || PA.x > N || PA.y < 1 || PA.y > M){
            printf("PA saiu na posicao (%d,%d) no passo %d\n", PA.x, PA.y, i);
            return 0;
        }
        if (PB.x < 1 || PB.x > N || PB.y < 1 || PB.y > M){
            printf("PB saiu na posicao (%d,%d) no passo %d\n", PB.x, PB.y, i);
            return 0;
        }
    }
    printf("Nao se encontraram\n");
    return 0;
}