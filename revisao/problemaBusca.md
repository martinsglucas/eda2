[Ir para o Sumário](../README.md)

# O problema de busca

Consiste em determinar de um elemento x pertence ou não a um determinado conjunto

Suponho que temos:
- Um conjunto universo com S elementos
- Um conjunto de dados com N elementos
- Deseja-se realizar M consultas

## 1. Busca Sequencial

```c
int busca(int *v, int n, int x){
    for (int i=0; i < n; i++){
        if (v[i] == x) return 1;
    }
    return 0;
}
// Considerando que queremos realizar M consultas, o custo total é O(M.n)
```

## 2. Busca Binária

```c
// Busca chave no vetor ordenado V[0..n-1]
int buscaBinaria(int *v, int n, int chave){
    int inicio, final, meio;
    inicio = 0;
    final = n - 1;
    while(inicio <= final){
        meio = (inicio + final)/2;
        if (chave == v[meio])
            return meio;
        if (chave < v[meio])
            final = meio - 1; // busca nos valores menores
        else
            inicio = meio + 1; // busca nos valores maiores
    }
    return -1; // chave não encontrada
}
```
Premissa: o conjunto precisa estar ordenado.

Para realizar M consultas:
1. Ordenar v O(n.log n)
2. Aplicar M buscas binárias O(M.log n)
Logo o custo total é: O(n.log n) + O(M.log n) = O((M+n).log n)

> Até o momento [1](#1-busca-sequencial) compensa se m for O(1). Se m for O(log n) são similares. Demais casos, [2](#2-busca-binária) é mais rápido

# 3. Endereçamento direto

1. Uso um vetor V de 0's e 1's de tamanho S
2. Pra cada elemento y do conjunto, marco: V[y-offset] = 1, os demais são 0.
    - offset é o menor valor do conjunto universo 

```c
int busca(char *v, int x){
    return v[x-OFFSET];
} // Considerando M consultas, o custo total é O(M) + O(S) de memória auxiliar
```

# 4. Tabela de dispersão (Tabela Hash)

Cada chave é mapeada em uma tabela (vetor ou lista encadeada), cuja posição é determinada por uma função de espalhamento (função hash)

A ideia é que o tamanho da tabela seja menor que o conjunto universo (S). Nesse caso, pode ocorrer uma colisão, ou seja, duas chaves distintas serem mapeadas para a mesma posição da tabela.

> Uma chave pode ocupar uma única posição, mas uma posição pode ser ocupada por várias chaves
> Uma famosa tabela hash da matemática é o círculo trigonométrico