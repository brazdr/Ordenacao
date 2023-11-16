#ifndef ORDENA_H
#define ORDENA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#define MAX_TAM 10  //quantas vezes vai rodar o vetor para calcular a média de tempo, comparação e movimentação

// função para registros pequenos
typedef struct {
    int chave;
} Item_leve;

//função para registros grandes
typedef struct {
    int chave;
    char peso_morto[50][50];
} Item_pesado;

// selecionar qual dos dois registros será utilizado, comente o que não for ser utilizado
typedef Item_leve Item; // registro pequeno
//typedef Item_pesado Item; // registro grande

//Troca de elementos
void trocar(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

//Ordenação por Seleção
void selecao(Item vetor[], int tamanho, int* comparacoes, int* movimentacoes) {
    int i, j, min;
    Item x;

    for (i = 0; i < tamanho - 1; i++) {
        min = i;
        for (j = i + 1; j < tamanho; j++) {
            (*comparacoes)++;
            if (vetor[j].chave < vetor[min].chave)
                min = j;
        }
        x = vetor[min];
        vetor[min] = vetor[i];
        vetor[i] = x;
        (*movimentacoes) += 3;
    }
}

//Ordenação por inserção
void insercao(Item vetor[], int tamanho, int* comparacoes, int* movimentacoes) {
    int i, j;
    Item x;

    for (i = 1; i < tamanho; i++) {
        x = vetor[i];
        j = i - 1;
        (*comparacoes)++;

        while (j >= 0 && vetor[j].chave > x.chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
            (*comparacoes)++;
            (*movimentacoes)++;

        }

        vetor[j + 1] = x;
        (*movimentacoes)++;
    }
}

//Shellsort
void shellsort(Item vetor[], int tamanho, int* comparacoes, int* movimentacoes) {
    int i, j;
    int h = 1;
    Item x;

    do h = h * 3 + 1; while (h < tamanho);
    do{
        h /= 3;
        for (i = h+1; i < tamanho; i++){
            x = vetor[i];
            j = i;
            (*comparacoes)++;
            while (vetor[j-h].chave > x.chave){
                vetor[j] = vetor[j-h];
                j -= h;
                (*comparacoes)++;
                (*movimentacoes)++;
                if (j < h) break;
            }
        vetor[j]= x;
        (*movimentacoes)++;
        }
    } 
    while (h != 1);
}

//Auxiliar para quicksort
int particionar(Item vetor[], int esq, int dir, int* comparacoes, int* movimentacoes) {
    int pivo = vetor[dir].chave;
    int i = (esq - 1);

    for (int j = esq; j <= dir - 1; j++) {
        (*comparacoes)++;
        if (vetor[j].chave < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
            (*movimentacoes)++;
        }
    }
    trocar(&vetor[i + 1], &vetor[dir]);
    (*movimentacoes) += 3;
    return (i + 1);
}

//Quicksort
void quicksort(Item vetor[], int esq, int dir, int* comparacoes, int* movimentacoes) {
    if (esq < dir) {
        int pivo = particionar(vetor, esq, dir, comparacoes, movimentacoes);
        quicksort(vetor, esq, pivo - 1, comparacoes, movimentacoes);
        quicksort(vetor, pivo + 1, dir, comparacoes, movimentacoes);
    }
}

//Auxiliar para heapsort
void heapify(Item vetor[], int tamanho, int x, int* comparacoes, int* movimentacoes) {
    int maior = x;
    int esq = 2 * x + 1;
    int dir = 2 * x + 2;
    (*comparacoes)++;

    if (esq < tamanho && vetor[esq].chave > vetor[maior].chave)
        maior = esq;
    (*comparacoes)++;
    if (dir < tamanho && vetor[dir].chave > vetor[maior].chave)
        maior = dir;

    if (maior != x) {
        trocar(&vetor[x], &vetor[maior]);
        (*movimentacoes) += 3;
        heapify(vetor, tamanho, maior, comparacoes, movimentacoes);
    }
}

//Heapsort
void heapsort(Item vetor[], int tamanho, int* comparacoes, int* movimentacoes) {
    for (int i = tamanho / 2 - 1; i >= 0; i--)
        heapify(vetor, tamanho, i, comparacoes, movimentacoes);

    for (int i = tamanho - 1; i >= 0; i--) {
        trocar(&vetor[0], &vetor[i]);
        (*movimentacoes) += 3;
        heapify(vetor, i, 0, comparacoes, movimentacoes);
    }
}

//Auxiliar para mergesort
void merge(Item vetor[], int inicio, int meio, int fim, int* comparacoes, int* movimentacoes) {
    int esq = meio - inicio + 1;
    int dir = fim - meio;

    Item *vetor_esquerda = malloc(esq * sizeof(Item));
    Item *vetor_direita = malloc(dir * sizeof(Item));

    for (int i = 0; i < esq; i++)
        vetor_esquerda[i] = vetor[inicio + i];

    for (int j = 0; j < dir; j++)
        vetor_direita[j] = vetor[meio + 1 + j];

    int i = 0, j = 0, k = inicio;
    
    while (i < esq && j < dir) {
        (*comparacoes)++;
        if (vetor_esquerda[i].chave <= vetor_direita[j].chave) {
            vetor[k] = vetor_esquerda[i];
            i++;
        } else {
            vetor[k] = vetor_direita[j];
            j++;
        }
        (movimentacoes)++;
        k++;
    }

    while (i < esq) {
        vetor[k] = vetor_esquerda[i];
        i++;
        k++;
        (*movimentacoes)++;
    }

    while (j < dir) {
        vetor[k] = vetor_direita[j];
        j++;
        k++;
        (*movimentacoes)++;
    }

    free(vetor_esquerda);
    free(vetor_direita);
}

//Mergesort
void mergesort(Item vetor[], int inicio, int fim, int* comparacoes, int* movimentacoes) {
    int  meio;
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2; // = vecSize
        mergesort(vetor, inicio, meio, comparacoes, movimentacoes);
        mergesort(vetor, meio + 1, fim, comparacoes, movimentacoes); // vetor + meio, vecSize - meio
        merge(vetor, inicio, meio, fim, comparacoes, movimentacoes);
    }
}

//Exibir o vetor de registro pequeno ordenado
void exibirVetor(Item vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i].chave);
    }
    printf("\n");
}

void embaralharVetor(Item vetor[], int tamanho) {
    srand(time(NULL));

    for (int i = tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Item temp = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = temp;
    }
}

float Media(int array[], int tamanho){
    int soma = 0;
    for(int i = 0; i < tamanho;i++){
        soma += array[i];
    }
    return soma /(float)tamanho;
}


#endif