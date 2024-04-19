# Tabelas de Dispersão (Hashing)

- Conjunto universo de tamanho S
- Conjunto de dados de tamanho n

>Método entre busca sequencial e acesso direto

Construir uma tabela de tamanho T < S, atentando-se para:
- colisão: duas chaves ocupam a mesma posição na tabela
- função de espalhamento: dado uma chave x, a posição na tabela será hash(x). hash: U -> {0, 1, ..., T-1}
    > a função hash não é bijetora, ou seja, duas chaves distintas podem ter o mesmo hash

## Implementação

Para implementar tabelas hash, precisamos de:
1. uma forma de armazenamento da tabela
2. uma função de espalhamento
3. um método para lidar com colisões

## Função de Espalhamento

A função hash ideal preencheria toda a tabela sem colisões. A primeira colisão aconteceria apenas quando n > T (quando a tabela estivesse cheia). O nome dessa função hash ideal é **hash universal uniforme**

A função hash mais comum segue o método da divisão:

```c
int hash(int x){
    return x % T;
}
```

## Estratégias para armazenamento e lidar com colisões

### Encadeamento separado

Tabela de tamanho T de nós-cabeça. Cada nó-cabeça aponta para uma lista encadeada de elementos.

<!-- ```c
typedef struct _no{
    int chave;
    struct _no *prox;
} No;

typedef struct {
    No *cabeca;
} Tabela[T];
``` -->

#### Implementação

Ideia de uma implementação básica

```c
tydef struct no{
    int dado;
    struct no *prox;
} no;

typedef struct {
    no *tab;
    int T; // tamanho
} TH;

void cria_tabela(TH *h, int T); // alocar o h e a tabela
void destroi_tabela(TH *h); // contrario do cria_tabela
void insere(TH *h, int x);
void remove(TH *h, int x);
int busca(TH *h, int x);


int busca(TH *h, int x){
    no *p = h->tab[hash(x)]->prox;
    while (p != NULL){
        if (p->dado == x) return 1;
        p = p->prox;
    }
    return 0;
} // complexidade O(n/T) no caso médio. Nesse caso o símbolo da complexidade adequado é Θ(n/T) ou O(δ), onde δ é o maior número de colisões na tabela. Se esse δ for limitado, a complexidade é O(1)
```

Portanto, uma boa implementação de hash consiste em **limitar o total de colisões**. Isso pode ser feito:
- escolhendo uma função hash ótima (pode exigir conhecimento sobre o conjunto de dados)
- limitar as colisões na inserção (consequetemente, podemos ter tabela cheia, sendo possível redimensionar a tabela)

### Boas escolhas para T: números primos, preferencialmente bem maior que n

- se a função hash for modular, e o número primo só tem 2 divisores (1 e ele mesmo), a distribuição dos elementos na tabela será mais uniforme, diminuindo a chance de colisões
- Primos de Mersenne: 2^n - 1, onde n é primo
    - tem indício de serem bons números primos

### Endereçamento aberto

Consiste no uso de vetores para implementar tabelas hash

Para resolução de colisões, há algumas técnicas, dentre as quais a mais comum chama-se **sondegem linear**: se houver colisão, procura-se pela próxima "posição livre" no vetor (pensando no conjunto universo de chaves positivas, a posição livre poderia ser o -1)

#### Exemplo

T = 10

chaves = {33, 36, 43, 77, 46, 56, 99}

| insercao | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
|:-:         |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|sit inicial |-1 |-1 |-1 |-1 |-1 |-1 |-1 |-1 |-1 |-1 |
| 1          |-1 |-1 |-1 |33 |-1 |-1 |-1 |-1 |-1 |-1 |
| 2          |-1 |-1 |-1 |33 |-1 |-1 |36 |-1 |-1 |-1 |
| 3          |-1 |-1 |-1 |33 |43 |-1 |36 |-1 |-1 |-1 |
| 4          |-1 |-1 |-1 |33 |43 |-1 |36 |77 |-1 |-1 |
| 5          |-1 |-1 |-1 |33 |43 |-1 |36 |77 |46 |-1 |
| 6          |-1 |-1 |-1 |33 |43 |-1 |36 |77 |46 |56 |
| 7          |99 |-1 |-1 |33 |43 |-1 |36 |77 |46 |56 |


Vai ser boa quando a tabela for esparsa, quando n < T, ou seja, quando possui "muitos" elementos vazios

**Densidade** é a porcentagem de elementos não-vazios do vetor.

$$\text{Densidade} = \frac{\text{qtd de elementos não vazios}}{\text{tamanho da tabela}}$$

Podemos dizer que um vetor é esparso quando a densidade é menor ou igual a 0.3

Na prática, quando a tabela hash atingir uma densidade D < 1, podemos redimensioná-la. Uma boa é dobrar o tamanho.

Ao redimensionar, é necessário reinserir os elementos (pois T muda e, consequentemente, a função hash também muda)

#### Implementação

```c
void insere(int ch){
    pos = hash(ch);
    while (v[pos] != -1){ // pode verificar se v[pos] == ch, caso necessário
        pos = (pos + 1) % T;
    }
    v[pos] = ch;
}
```
```c
int busca(int ch){
    pos = hash(ch);
    while (v[pos] != -1 && v[pos] != ch){
        pos = (pos + 1) % T;
    }
    if (v[pos] == ch) return 1;
}
return 0;
```
```c
void remove(int ch){
    pos = busca(ch);
    if (pos >= 0){
        // v[pos] = -2;
        v[pos] = -1;
        pos = (pos + 1) % T;
        while (v[pos] != -1){
            int elem = v[pos];
            v[pos] = -1;
            insere(elem);
            pos = (pos + 1) % T; 
        }
    }


}
// reinserir na hash todos os elementos à direita até encontrar vazio
// Outra alternativa seria remover e marcar como disponível (posso inserir), mas não-vazio (busca não deve parar)
```
