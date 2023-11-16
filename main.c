#include "Ordena.h"

int main() {

    Item* vetor1 = (Item*)malloc(20 * sizeof(Item));
    Item* vetor2 = (Item*)malloc(500 * sizeof(Item));
    Item* vetor3 = (Item*)malloc(5000 * sizeof(Item));
    Item* vetor4 = (Item*)malloc(10000 * sizeof(Item));
    Item* vetor5 = (Item*)malloc(200000 * sizeof(Item)); 
    int i;
    int opcao;
    struct timeval start, end;
    struct timeval start2, end2;
    int comparacoes = 0;
    int movimentacoes = 0;
        
        printf("Selecione uma opcao:\n1- 20 elementos\n2- 500 elementos\n3- 5000 elementos\n4- 10000 elementos\n5- 200000 elementos\n");
        scanf("%d", &opcao);

        switch(opcao){
            case 1:
                printf("\nVoce selecionou o vetor de tamanho 20:\n");
                printf("\nOrdenacao por Selecao: \n");
                //ordem crescente
                long double tempo_crescente[MAX_TAM];
                int comparacoes_crescente[MAX_TAM];
                int movimentacoes_crescente[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                selecao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente[i] = endTime - startTime;
                comparacoes_crescente[i] = comparacoes;
                movimentacoes_crescente[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente = 0.0;
                int media_comparacoes_crescente = 0;
                int media_movimentacoes_crescente = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente += tempo_crescente[i];
                    media_comparacoes_crescente += comparacoes_crescente[i];
                    media_movimentacoes_crescente += movimentacoes_crescente[i];
                }
                media_tempo_crescente /= MAX_TAM;
                media_comparacoes_crescente /= MAX_TAM;
                media_movimentacoes_crescente /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente[MAX_TAM];
                int comparacoes_decrescente[MAX_TAM];
                int movimentacoes_decrescente[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                selecao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente[i] = endTime - startTime;
                comparacoes_decrescente[i] = comparacoes;
                movimentacoes_decrescente[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente = 0.0;
                int media_comparacoes_decrescente = 0;
                int media_movimentacoes_decrescente = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente += tempo_decrescente[i];
                    media_comparacoes_decrescente += comparacoes_decrescente[i];
                    media_movimentacoes_decrescente += movimentacoes_decrescente[i];
                }
                media_tempo_decrescente /= MAX_TAM;
                media_comparacoes_decrescente /= MAX_TAM;
                media_movimentacoes_decrescente /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio[MAX_TAM];
                int comparacoes_aleatorio[MAX_TAM];
                int movimentacoes_aleatorio[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                selecao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio[i] = endTime - startTime;
                comparacoes_aleatorio[i] = comparacoes;
                movimentacoes_aleatorio[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio = 0.0;
                int media_comparacoes_aleatorio = 0;
                int media_movimentacoes_aleatorio = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio += tempo_aleatorio[i];
                media_comparacoes_aleatorio += comparacoes_aleatorio[i];
                media_movimentacoes_aleatorio += movimentacoes_aleatorio[i];
                }
                media_tempo_aleatorio /= MAX_TAM;
                media_comparacoes_aleatorio /= MAX_TAM;
                media_movimentacoes_aleatorio /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio);
                printf("\n");
                
                //Ordenação por inserção
               
               //ordem crescente
               printf("\nOrdencao por Insercao:\n");
                long double tempo_crescente1[MAX_TAM];
                int comparacoes_crescente1[MAX_TAM];
                int movimentacoes_crescente1[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                insercao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime1 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime1 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente1[i] = endTime1 - startTime1;
                comparacoes_crescente1[i] = comparacoes;
                movimentacoes_crescente1[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente1 = 0.0;
                int media_comparacoes_crescente1 = 0;
                int media_movimentacoes_crescente1 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente1 += tempo_crescente1[i];
                    media_comparacoes_crescente1 += comparacoes_crescente1[i];
                    media_movimentacoes_crescente1 += movimentacoes_crescente1[i];
                }
                media_tempo_crescente1 /= MAX_TAM;
                media_comparacoes_crescente1 /= MAX_TAM;
                media_movimentacoes_crescente1 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente1);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente1);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente1);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente1[MAX_TAM];
                int comparacoes_decrescente1[MAX_TAM];
                int movimentacoes_decrescente1[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                insercao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime1 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime1 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente1[i] = endTime1 - startTime1;
                comparacoes_decrescente1[i] = comparacoes;
                movimentacoes_decrescente1[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente1 = 0.0;
                int media_comparacoes_decrescente1 = 0;
                int media_movimentacoes_decrescente1 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente1 += tempo_decrescente1[i];
                    media_comparacoes_decrescente1 += comparacoes_decrescente1[i];
                    media_movimentacoes_decrescente1 += movimentacoes_decrescente1[i];
                }
                media_tempo_decrescente1 /= MAX_TAM;
                media_comparacoes_decrescente1 /= MAX_TAM;
                media_movimentacoes_decrescente1 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente1);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente1);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente1);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio1[MAX_TAM];
                int comparacoes_aleatorio1[MAX_TAM];
                int movimentacoes_aleatorio1[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                insercao(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime1 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime1 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio1[i] = endTime1 - startTime1;
                comparacoes_aleatorio1[i] = comparacoes;
                movimentacoes_aleatorio1[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio1 = 0.0;
                int media_comparacoes_aleatorio1 = 0;
                int media_movimentacoes_aleatorio1 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio1 += tempo_aleatorio1[i];
                media_comparacoes_aleatorio1 += comparacoes_aleatorio1[i];
                media_movimentacoes_aleatorio1 += movimentacoes_aleatorio1[i];
                }
                media_tempo_aleatorio1 /= MAX_TAM;
                media_comparacoes_aleatorio1 /= MAX_TAM;
                media_movimentacoes_aleatorio1 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio);
                printf("\n");
                
                //Ordenação shellsort
                printf("\n");
                printf("Ordencao por Shellsort\n");
                //ordem crescente
                long double tempo_crescente2[MAX_TAM];
                int comparacoes_crescente2[MAX_TAM];
                int movimentacoes_crescente2[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                shellsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime2 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime2 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente2[i] = endTime2 - startTime2;
                comparacoes_crescente2[i] = comparacoes;
                movimentacoes_crescente2[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente2 = 0.0;
                int media_comparacoes_crescente2 = 0;
                int media_movimentacoes_crescente2 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente2 += tempo_crescente2[i];
                    media_comparacoes_crescente2 += comparacoes_crescente2[i];
                    media_movimentacoes_crescente2 += movimentacoes_crescente2[i];
                }
                media_tempo_crescente2 /= MAX_TAM;
                media_comparacoes_crescente2 /= MAX_TAM;
                media_movimentacoes_crescente2 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente2[MAX_TAM];
                int comparacoes_decrescente2[MAX_TAM];
                int movimentacoes_decrescente2[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime2 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime2 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente2[i] = endTime2 - startTime2;
                comparacoes_decrescente2[i] = comparacoes;
                movimentacoes_decrescente2[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente2 = 0.0;
                int media_comparacoes_decrescente2 = 0;
                int media_movimentacoes_decrescente2 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente2 += tempo_decrescente2[i];
                    media_comparacoes_decrescente2 += comparacoes_decrescente2[i];
                    media_movimentacoes_decrescente2 += movimentacoes_decrescente2[i];
                }
                media_tempo_decrescente2 /= MAX_TAM;
                media_comparacoes_decrescente2 /= MAX_TAM;
                media_movimentacoes_decrescente2 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente2);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente2);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente2);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio2[MAX_TAM];
                int comparacoes_aleatorio2[MAX_TAM];
                int movimentacoes_aleatorio2[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                shellsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime2 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime2 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio2[i] = endTime2 - startTime2;
                comparacoes_aleatorio2[i] = comparacoes;
                movimentacoes_aleatorio2[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio2 = 0.0;
                int media_comparacoes_aleatorio2 = 0;
                int media_movimentacoes_aleatorio2 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio2 += tempo_aleatorio2[i];
                media_comparacoes_aleatorio2 += comparacoes_aleatorio2[i];
                media_movimentacoes_aleatorio2 += movimentacoes_aleatorio2[i];
                }
                media_tempo_aleatorio2 /= MAX_TAM;
                media_comparacoes_aleatorio2 /= MAX_TAM;
                media_movimentacoes_aleatorio2 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio);
                printf("\n");
                
                //Ordenação quicksort
                printf("\n");
                printf("Ordencao por QuickSort\n");
                //ordem crescente
                long double tempo_crescente3[MAX_TAM];
                int comparacoes_crescente3[MAX_TAM];
                int movimentacoes_crescente3[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                quicksort(vetor1, 0, 19, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime3 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime3 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente3[i] = endTime3 - startTime3;
                comparacoes_crescente3[i] = comparacoes;
                movimentacoes_crescente3[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente3 = 0.0;
                int media_comparacoes_crescente3 = 0;
                int media_movimentacoes_crescente3 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente3 += tempo_crescente3[i];
                    media_comparacoes_crescente3 += comparacoes_crescente3[i];
                    media_movimentacoes_crescente3 += movimentacoes_crescente3[i];
                }
                media_tempo_crescente3 /= MAX_TAM;
                media_comparacoes_crescente3 /= MAX_TAM;
                media_movimentacoes_crescente3 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente3);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente3);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente3);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente3[MAX_TAM];
                int comparacoes_decrescente3[MAX_TAM];
                int movimentacoes_decrescente3[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                quicksort(vetor1, 0, 19 , &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime3 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime3 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente3[i] = endTime3 - startTime3;
                comparacoes_decrescente3[i] = comparacoes;
                movimentacoes_decrescente3[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente3 = 0.0;
                int media_comparacoes_decrescente3 = 0;
                int media_movimentacoes_decrescente3 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente3 += tempo_decrescente3[i];
                    media_comparacoes_decrescente3 += comparacoes_decrescente3[i];
                    media_movimentacoes_decrescente3 += movimentacoes_decrescente3[i];
                }
                media_tempo_decrescente3 /= MAX_TAM;
                media_comparacoes_decrescente3 /= MAX_TAM;
                media_movimentacoes_decrescente3 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente3);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente3);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente3);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio3[MAX_TAM];
                int comparacoes_aleatorio3[MAX_TAM];
                int movimentacoes_aleatorio3[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                quicksort(vetor1, 0, 19, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime3 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime3 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio3[i] = endTime3 - startTime3;
                comparacoes_aleatorio3[i] = comparacoes;
                movimentacoes_aleatorio3[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio3 = 0.0;
                int media_comparacoes_aleatorio3 = 0;
                int media_movimentacoes_aleatorio3 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio3 += tempo_aleatorio3[i];
                media_comparacoes_aleatorio3 += comparacoes_aleatorio3[i];
                media_movimentacoes_aleatorio3 += movimentacoes_aleatorio3[i];
                }
                media_tempo_aleatorio3 /= MAX_TAM;
                media_comparacoes_aleatorio3 /= MAX_TAM;
                media_movimentacoes_aleatorio3 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio3);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio3);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio3);
                printf("\n");
                
                //Ordenação heapsort
                 printf("\n");
                printf("Ordencao por HeapSort\n");
                //ordem crescente
                long double tempo_crescente4[MAX_TAM];
                int comparacoes_crescente4[MAX_TAM];
                int movimentacoes_crescente4[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                heapsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime4 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime4 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente4[i] = endTime4 - startTime4;
                comparacoes_crescente4[i] = comparacoes;
                movimentacoes_crescente4[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente4 = 0.0;
                int media_comparacoes_crescente4 = 0;
                int media_movimentacoes_crescente4 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente4 += tempo_crescente4[i];
                    media_comparacoes_crescente4 += comparacoes_crescente4[i];
                    media_movimentacoes_crescente4 += movimentacoes_crescente4[i];
                }
                media_tempo_crescente4 /= MAX_TAM;
                media_comparacoes_crescente4 /= MAX_TAM;
                media_movimentacoes_crescente4 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente4);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente4);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente4);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente4[MAX_TAM];
                int comparacoes_decrescente4[MAX_TAM];
                int movimentacoes_decrescente4[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                heapsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime4 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime4 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente4[i] = endTime4 - startTime4;
                comparacoes_decrescente4[i] = comparacoes;
                movimentacoes_decrescente4[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente4 = 0.0;
                int media_comparacoes_decrescente4 = 0;
                int media_movimentacoes_decrescente4 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente4 += tempo_decrescente4[i];
                    media_comparacoes_decrescente4 += comparacoes_decrescente4[i];
                    media_movimentacoes_decrescente4 += movimentacoes_decrescente4[i];
                }
                media_tempo_decrescente4 /= MAX_TAM;
                media_comparacoes_decrescente4 /= MAX_TAM;
                media_movimentacoes_decrescente4 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente4);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente4);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente4);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio4[MAX_TAM];
                int comparacoes_aleatorio4[MAX_TAM];
                int movimentacoes_aleatorio4[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                heapsort(vetor1, 20, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime4 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime4 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio4[i] = endTime4 - startTime4;
                comparacoes_aleatorio4[i] = comparacoes;
                movimentacoes_aleatorio4[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio4 = 0.0;
                int media_comparacoes_aleatorio4 = 0;
                int media_movimentacoes_aleatorio4 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio4 += tempo_aleatorio4[i];
                media_comparacoes_aleatorio4 += comparacoes_aleatorio4[i];
                media_movimentacoes_aleatorio4 += movimentacoes_aleatorio4[i];
                }
                media_tempo_aleatorio4 /= MAX_TAM;
                media_comparacoes_aleatorio4 /= MAX_TAM;
                media_movimentacoes_aleatorio4 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio4);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio4);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio4);
                printf("\n");
                
                //Ordenação mergesort
                printf("\n");
                printf("Ordenacao por Mergesort\n");
                //ordem crescente
                long double tempo_crescente5[MAX_TAM];
                int comparacoes_crescente5[MAX_TAM];
                int movimentacoes_crescente5[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                mergesort(vetor1, 0, 19, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime5 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime5 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente5[i] = endTime5 - startTime5;
                comparacoes_crescente5[i] = comparacoes;
                movimentacoes_crescente5[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente5 = 0.0;
                int media_comparacoes_crescente5 = 0;
                int media_movimentacoes_crescente5 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente5 += tempo_crescente5[i];
                    media_comparacoes_crescente5 += comparacoes_crescente5[i];
                    media_movimentacoes_crescente5 += movimentacoes_crescente5[i];
                }
                media_tempo_crescente5 /= MAX_TAM;
                media_comparacoes_crescente5 /= MAX_TAM;
                media_movimentacoes_crescente5 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente5);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente5);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente5);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente5[MAX_TAM];
                int comparacoes_decrescente5[MAX_TAM];
                int movimentacoes_decrescente5[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 20; j++) {
                    vetor1[j].chave = 20 - j;
                }
                gettimeofday(&start, NULL);
                mergesort(vetor1, 0, 19, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime5 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime5 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente5[i] = endTime5 - startTime5;
                comparacoes_decrescente5[i] = comparacoes;
                movimentacoes_decrescente5[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente5 = 0.0;
                int media_comparacoes_decrescente5 = 0;
                int media_movimentacoes_decrescente5 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente5 += tempo_decrescente5[i];
                    media_comparacoes_decrescente5 += comparacoes_decrescente5[i];
                    media_movimentacoes_decrescente5 += movimentacoes_decrescente5[i];
                }
                media_tempo_decrescente5 /= MAX_TAM;
                media_comparacoes_decrescente5 /= MAX_TAM;
                media_movimentacoes_decrescente5 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente5);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente5);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente5);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio5[MAX_TAM];
                int comparacoes_aleatorio5[MAX_TAM];
                int movimentacoes_aleatorio5[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor1[20];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 20; j++) {
                        vetor1[j].chave = j + 1;
                }
                embaralharVetor(vetor1, 20);
                gettimeofday(&start, NULL);
                mergesort(vetor1, 0, 19, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime5 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime5 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio5[i] = endTime5 - startTime5;
                comparacoes_aleatorio5[i] = comparacoes;
                movimentacoes_aleatorio5[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio5 = 0.0;
                int media_comparacoes_aleatorio5 = 0;
                int media_movimentacoes_aleatorio5 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio5 += tempo_aleatorio5[i];
                media_comparacoes_aleatorio5 += comparacoes_aleatorio5[i];
                media_movimentacoes_aleatorio5 += movimentacoes_aleatorio5[i];
                }
                media_tempo_aleatorio5 /= MAX_TAM;
                media_comparacoes_aleatorio5 /= MAX_TAM;
                media_movimentacoes_aleatorio5 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio5);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio5);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio5);
                printf("\n");
                
                system("PAUSE");
                break;

            case 2:
                printf("Voce selecionou o vetor de tamanho 500:\n");
                printf("\n");
                //Ordenacao por selecao
                printf("Ordenacao por Selecao\n");
                //ordem crescente
                long double tempo_crescente6[MAX_TAM];
                int comparacoes_crescente6[MAX_TAM];
                int movimentacoes_crescente6[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                selecao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime6 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime6 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente[i] = endTime6 - startTime6;
                comparacoes_crescente6[i] = comparacoes;
                movimentacoes_crescente6[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente6 = 0.0;
                int media_comparacoes_crescente6 = 0;
                int media_movimentacoes_crescente6 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente6 += tempo_crescente6[i];
                    media_comparacoes_crescente6 += comparacoes_crescente6[i];
                    media_movimentacoes_crescente6 += movimentacoes_crescente6[i];
                }
                media_tempo_crescente6 /= MAX_TAM;
                media_comparacoes_crescente6 /= MAX_TAM;
                media_movimentacoes_crescente6 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente6);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente6);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente6);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente6[MAX_TAM];
                int comparacoes_decrescente6[MAX_TAM];
                int movimentacoes_decrescente6[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                selecao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime6 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime6 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente[i] = endTime6 - startTime6;
                comparacoes_decrescente6[i] = comparacoes;
                movimentacoes_decrescente6[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente6 = 0.0;
                int media_comparacoes_decrescente6 = 0;
                int media_movimentacoes_decrescente6 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente6 += tempo_decrescente6[i];
                    media_comparacoes_decrescente6 += comparacoes_decrescente6[i];
                    media_movimentacoes_decrescente6 += movimentacoes_decrescente6[i];
                }
                media_tempo_decrescente6 /= MAX_TAM;
                media_comparacoes_decrescente6 /= MAX_TAM;
                media_movimentacoes_decrescente6 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente6);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente6);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente6);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio6[MAX_TAM];
                int comparacoes_aleatorio6[MAX_TAM];
                int movimentacoes_aleatorio6[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                selecao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime6 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime6 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio[i] = endTime6 - startTime6;
                comparacoes_aleatorio6[i] = comparacoes;
                movimentacoes_aleatorio6[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio6 = 0.0;
                int media_comparacoes_aleatorio6 = 0;
                int media_movimentacoes_aleatorio6 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio6 += tempo_aleatorio6[i];
                media_comparacoes_aleatorio6 += comparacoes_aleatorio6[i];
                media_movimentacoes_aleatorio6 += movimentacoes_aleatorio6[i];
                }
                media_tempo_aleatorio6 /= MAX_TAM;
                media_comparacoes_aleatorio6 /= MAX_TAM;
                media_movimentacoes_aleatorio6 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio6);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio6);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio6);
                printf("\n");
                
                //Ordenação por inserção
                //ordem crescente
                printf("\nOrdencao por Insercao:\n");
                long double tempo_crescente7[MAX_TAM];
                int comparacoes_crescente7[MAX_TAM];
                int movimentacoes_crescente7[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                insercao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime7 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime7 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente7[i] = endTime7 - startTime7;
                comparacoes_crescente7[i] = comparacoes;
                movimentacoes_crescente7[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente7 = 0.0;
                int media_comparacoes_crescente7 = 0;
                int media_movimentacoes_crescente7 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente7 += tempo_crescente7[i];
                    media_comparacoes_crescente7 += comparacoes_crescente7[i];
                    media_movimentacoes_crescente7 += movimentacoes_crescente7[i];
                }
                media_tempo_crescente7 /= MAX_TAM;
                media_comparacoes_crescente7 /= MAX_TAM;
                media_movimentacoes_crescente7 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente7);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente7);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente7);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente7[MAX_TAM];
                int comparacoes_decrescente7[MAX_TAM];
                int movimentacoes_decrescente7[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                insercao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime7 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime7 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente7[i] = endTime7 - startTime7;
                comparacoes_decrescente7[i] = comparacoes;
                movimentacoes_decrescente7[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente7 = 0.0;
                int media_comparacoes_decrescente7 = 0;
                int media_movimentacoes_decrescente7 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente7 += tempo_decrescente7[i];
                    media_comparacoes_decrescente7 += comparacoes_decrescente7[i];
                    media_movimentacoes_decrescente7 += movimentacoes_decrescente7[i];
                }
                media_tempo_decrescente7 /= MAX_TAM;
                media_comparacoes_decrescente7 /= MAX_TAM;
                media_movimentacoes_decrescente7 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente7);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente7);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente7);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio7[MAX_TAM];
                int comparacoes_aleatorio7[MAX_TAM];
                int movimentacoes_aleatorio7[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                insercao(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime7 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime7 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio7[i] = endTime7 - startTime7;
                comparacoes_aleatorio7[i] = comparacoes;
                movimentacoes_aleatorio7[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio7 = 0.0;
                int media_comparacoes_aleatorio7 = 0;
                int media_movimentacoes_aleatorio7 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio7 += tempo_aleatorio7[i];
                media_comparacoes_aleatorio7 += comparacoes_aleatorio7[i];
                media_movimentacoes_aleatorio7 += movimentacoes_aleatorio7[i];
                }
                media_tempo_aleatorio7 /= MAX_TAM;
                media_comparacoes_aleatorio7 /= MAX_TAM;
                media_movimentacoes_aleatorio7 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio7);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio7);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio7);
                printf("\n");
                
                //Ordenação shellsort
                printf("\n");
                printf("Ordencao por Shellsort\n");
                //ordem crescente
                long double tempo_crescente8[MAX_TAM];
                int comparacoes_crescente8[MAX_TAM];
                int movimentacoes_crescente8[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                shellsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime8 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime8 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente8[i] = endTime8 - startTime8;
                comparacoes_crescente8[i] = comparacoes;
                movimentacoes_crescente8[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente8 = 0.0;
                int media_comparacoes_crescente8 = 0;
                int media_movimentacoes_crescente8 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente8 += tempo_crescente8[i];
                    media_comparacoes_crescente8 += comparacoes_crescente8[i];
                    media_movimentacoes_crescente8 += movimentacoes_crescente8[i];
                }
                media_tempo_crescente8 /= MAX_TAM;
                media_comparacoes_crescente8 /= MAX_TAM;
                media_movimentacoes_crescente8 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente8);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente8);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente8);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente8[MAX_TAM];
                int comparacoes_decrescente8[MAX_TAM];
                int movimentacoes_decrescente8[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime8 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime8 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente2[i] = endTime8 - startTime8;
                comparacoes_decrescente8[i] = comparacoes;
                movimentacoes_decrescente8[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente8 = 0.0;
                int media_comparacoes_decrescente8 = 0;
                int media_movimentacoes_decrescente8 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente8 += tempo_decrescente2[i];
                    media_comparacoes_decrescente8 += comparacoes_decrescente2[i];
                    media_movimentacoes_decrescente8 += movimentacoes_decrescente2[i];
                }
                media_tempo_decrescente8/= MAX_TAM;
                media_comparacoes_decrescente8 /= MAX_TAM;
                media_movimentacoes_decrescente8 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente8);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente8);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente8);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio8[MAX_TAM];
                int comparacoes_aleatorio8[MAX_TAM];
                int movimentacoes_aleatorio8[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                shellsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime8 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime8 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio8[i] = endTime8 - startTime8;
                comparacoes_aleatorio8[i] = comparacoes;
                movimentacoes_aleatorio8[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio8 = 0.0;
                int media_comparacoes_aleatorio8 = 0;
                int media_movimentacoes_aleatorio8 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio8 += tempo_aleatorio8[i];
                media_comparacoes_aleatorio8 += comparacoes_aleatorio8[i];
                media_movimentacoes_aleatorio8 += movimentacoes_aleatorio8[i];
                }
                media_tempo_aleatorio8 /= MAX_TAM;
                media_comparacoes_aleatorio8 /= MAX_TAM;
                media_movimentacoes_aleatorio8 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio8);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio8);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio8);
                printf("\n");
                
                //Ordenação quicksort
                printf("\n");
                printf("Ordencao por QuickSort\n");
                //ordem crescente
                long double tempo_crescente9[MAX_TAM];
                int comparacoes_crescente9[MAX_TAM];
                int movimentacoes_crescente9[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                quicksort(vetor2, 0, 499, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime9 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime9 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente3[i] = endTime9- startTime9;
                comparacoes_crescente9[i] = comparacoes;
                movimentacoes_crescente9[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente9 = 0.0;
                int media_comparacoes_crescente9 = 0;
                int media_movimentacoes_crescente9 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente9 += tempo_crescente9[i];
                    media_comparacoes_crescente9 += comparacoes_crescente9[i];
                    media_movimentacoes_crescente9 += movimentacoes_crescente9[i];
                }
                media_tempo_crescente9 /= MAX_TAM;
                media_comparacoes_crescente9 /= MAX_TAM;
                media_movimentacoes_crescente9 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente9);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente9);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente9);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente9[MAX_TAM];
                int comparacoes_decrescente9[MAX_TAM];
                int movimentacoes_decrescente9[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                quicksort(vetor2, 0, 499 , &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime9 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime9 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente9[i] = endTime9 - startTime9;
                comparacoes_decrescente9[i] = comparacoes;
                movimentacoes_decrescente9[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente9 = 0.0;
                int media_comparacoes_decrescente9 = 0;
                int media_movimentacoes_decrescente9 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente9 += tempo_decrescente9[i];
                    media_comparacoes_decrescente9 += comparacoes_decrescente9[i];
                    media_movimentacoes_decrescente9 += movimentacoes_decrescente9[i];
                }
                media_tempo_decrescente9 /= MAX_TAM;
                media_comparacoes_decrescente9 /= MAX_TAM;
                media_movimentacoes_decrescente9 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente9);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente9);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente9);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio9[MAX_TAM];
                int comparacoes_aleatorio9[MAX_TAM];
                int movimentacoes_aleatorio9[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                quicksort(vetor2, 0, 499, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime9 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime9 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio9[i] = endTime9 - startTime9;
                comparacoes_aleatorio9[i] = comparacoes;
                movimentacoes_aleatorio9[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio9 = 0.0;
                int media_comparacoes_aleatorio9 = 0;
                int media_movimentacoes_aleatorio9 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio9 += tempo_aleatorio9[i];
                media_comparacoes_aleatorio9 += comparacoes_aleatorio9[i];
                media_movimentacoes_aleatorio9 += movimentacoes_aleatorio9[i];
                }
                media_tempo_aleatorio9/= MAX_TAM;
                media_comparacoes_aleatorio9 /= MAX_TAM;
                media_movimentacoes_aleatorio9 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio9);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio9);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio9);
                printf("\n");
                
                //Ordenação heapsort
                 printf("\n");
                printf("Ordencao por HeapSort\n");
                //ordem crescente
                long double tempo_crescente10[MAX_TAM];
                int comparacoes_crescente10[MAX_TAM];
                int movimentacoes_crescente10[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                heapsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime10 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime10 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente10[i] = endTime10 - startTime10;
                comparacoes_crescente10[i] = comparacoes;
                movimentacoes_crescente10[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente10 = 0.0;
                int media_comparacoes_crescente10 = 0;
                int media_movimentacoes_crescente10 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente10 += tempo_crescente10[i];
                    media_comparacoes_crescente10 += comparacoes_crescente10[i];
                    media_movimentacoes_crescente10 += movimentacoes_crescente10[i];
                }
                media_tempo_crescente10 /= MAX_TAM;
                media_comparacoes_crescente10 /= MAX_TAM;
                media_movimentacoes_crescente10 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente10);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente10);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente10);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente10[MAX_TAM];
                int comparacoes_decrescente10[MAX_TAM];
                int movimentacoes_decrescente10[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                heapsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime10 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime10 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente10[i] = endTime10 - startTime10;
                comparacoes_decrescente10[i] = comparacoes;
                movimentacoes_decrescente10[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente10 = 0.0;
                int media_comparacoes_decrescente10 = 0;
                int media_movimentacoes_decrescente10 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente10 += tempo_decrescente10[i];
                    media_comparacoes_decrescente10 += comparacoes_decrescente10[i];
                    media_movimentacoes_decrescente10 += movimentacoes_decrescente10[i];
                }
                media_tempo_decrescente10 /= MAX_TAM;
                media_comparacoes_decrescente10 /= MAX_TAM;
                media_movimentacoes_decrescente10 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente10);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente10);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente10);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio10[MAX_TAM];
                int comparacoes_aleatorio10[MAX_TAM];
                int movimentacoes_aleatorio10[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                heapsort(vetor2, 500, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime10 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime10 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio10[i] = endTime10 - startTime10;
                comparacoes_aleatorio10[i] = comparacoes;
                movimentacoes_aleatorio10[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio10 = 0.0;
                int media_comparacoes_aleatorio10 = 0;
                int media_movimentacoes_aleatorio10 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio10 += tempo_aleatorio10[i];
                media_comparacoes_aleatorio10 += comparacoes_aleatorio10[i];
                media_movimentacoes_aleatorio10 += movimentacoes_aleatorio10[i];
                }
                media_tempo_aleatorio10 /= MAX_TAM;
                media_comparacoes_aleatorio10 /= MAX_TAM;
                media_movimentacoes_aleatorio10 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio10);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio10);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio10);
                printf("\n");
                
                //Ordenação mergesort
                printf("\n");
                printf("Ordenacao por Mergesort\n");
                //ordem crescente
                long double tempo_crescente11[MAX_TAM];
                int comparacoes_crescente11[MAX_TAM];
                int movimentacoes_crescente11[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                mergesort(vetor2, 0, 499, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime11 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime11 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente11[i] = endTime11 - startTime11;
                comparacoes_crescente11[i] = comparacoes;
                movimentacoes_crescente11[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente11 = 0.0;
                int media_comparacoes_crescente11 = 0;
                int media_movimentacoes_crescente11 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente11+= tempo_crescente11[i];
                    media_comparacoes_crescente11 += comparacoes_crescente11[i];
                    media_movimentacoes_crescente11+= movimentacoes_crescente11[i];
                }
                media_tempo_crescente11 /= MAX_TAM;
                media_comparacoes_crescente11 /= MAX_TAM;
                media_movimentacoes_crescente11 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente11);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente11);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente11);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente11[MAX_TAM];
                int comparacoes_decrescente11[MAX_TAM];
                int movimentacoes_decrescente11[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 500; j++) {
                    vetor2[j].chave = 500 - j;
                }
                gettimeofday(&start, NULL);
                mergesort(vetor2, 0, 499, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime11 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime11 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente11[i] = endTime11 - startTime11;
                comparacoes_decrescente11[i] = comparacoes;
                movimentacoes_decrescente11[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente11 = 0.0;
                int media_comparacoes_decrescente11 = 0;
                int media_movimentacoes_decrescente11 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente11 += tempo_decrescente11[i];
                    media_comparacoes_decrescente11 += comparacoes_decrescente11[i];
                    media_movimentacoes_decrescente11 += movimentacoes_decrescente11[i];
                }
                media_tempo_decrescente11 /= MAX_TAM;
                media_comparacoes_decrescente11 /= MAX_TAM;
                media_movimentacoes_decrescente11 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente11);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente11);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente11);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio11[MAX_TAM];
                int comparacoes_aleatorio11[MAX_TAM];
                int movimentacoes_aleatorio11[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor2[500];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 500; j++) {
                        vetor2[j].chave = j + 1;
                }
                embaralharVetor(vetor2, 500);
                gettimeofday(&start, NULL);
                mergesort(vetor2, 0, 499, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime11 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime11 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio11[i] = endTime11 - startTime11;
                comparacoes_aleatorio11[i] = comparacoes;
                movimentacoes_aleatorio11[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio11 = 0.0;
                int media_comparacoes_aleatorio11 = 0;
                int media_movimentacoes_aleatorio11 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio11 += tempo_aleatorio11[i];
                media_comparacoes_aleatorio11 += comparacoes_aleatorio11[i];
                media_movimentacoes_aleatorio11 += movimentacoes_aleatorio11[i];
                }
                media_tempo_aleatorio11 /= MAX_TAM;
                media_comparacoes_aleatorio11 /= MAX_TAM;
                media_movimentacoes_aleatorio11 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio11);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio11);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio11);
                printf("\n");
                
                system("PAUSE");
                break;

            case 3:
                printf("Voce selecionou o vetor de tamanho 5000:\n");
                printf("\n");
                //Ordenacao por selecao
                printf("Ordenacao por Selecao\n");
                //ordem crescente
                long double tempo_crescente12[MAX_TAM];
                int comparacoes_crescente12[MAX_TAM];
                int movimentacoes_crescente12[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                selecao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime12 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime12 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente[i] = endTime12 - startTime12;
                comparacoes_crescente12[i] = comparacoes;
                movimentacoes_crescente12[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente12 = 0.0;
                int media_comparacoes_crescente12 = 0;
                int media_movimentacoes_crescente12 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente12 += tempo_crescente12[i];
                    media_comparacoes_crescente12 += comparacoes_crescente12[i];
                    media_movimentacoes_crescente12 += movimentacoes_crescente12[i];
                }
                media_tempo_crescente12 /= MAX_TAM;
                media_comparacoes_crescente12 /= MAX_TAM;
                media_movimentacoes_crescente12 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente12);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente12);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente12);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente12[MAX_TAM];
                int comparacoes_decrescente12[MAX_TAM];
                int movimentacoes_decrescente12[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                selecao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime12 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime12 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente12[i] = endTime12 - startTime12;
                comparacoes_decrescente12[i] = comparacoes;
                movimentacoes_decrescente12[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente12 = 0.0;
                int media_comparacoes_decrescente12 = 0;
                int media_movimentacoes_decrescente12 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente12 += tempo_decrescente12[i];
                    media_comparacoes_decrescente12 += comparacoes_decrescente12[i];
                    media_movimentacoes_decrescente12 += movimentacoes_decrescente12[i];
                }
                media_tempo_decrescente12 /= MAX_TAM;
                media_comparacoes_decrescente12 /= MAX_TAM;
                media_movimentacoes_decrescente12 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente12);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente12);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente12);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio12[MAX_TAM];
                int comparacoes_aleatorio12[MAX_TAM];
                int movimentacoes_aleatorio12[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                selecao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime12 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime12 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio12[i] = endTime12 - startTime12;
                comparacoes_aleatorio12[i] = comparacoes;
                movimentacoes_aleatorio12[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio12 = 0.0;
                int media_comparacoes_aleatorio12 = 0;
                int media_movimentacoes_aleatorio12 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio12 += tempo_aleatorio12[i];
                media_comparacoes_aleatorio12 += comparacoes_aleatorio12[i];
                media_movimentacoes_aleatorio12 += movimentacoes_aleatorio12[i];
                }
                media_tempo_aleatorio12 /= MAX_TAM;
                media_comparacoes_aleatorio12 /= MAX_TAM;
                media_movimentacoes_aleatorio12 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio12);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio12);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio12);
                printf("\n");
                
                //Ordenação por inserção
                //ordem crescente
                printf("\nOrdencao por Insercao:\n");
                long double tempo_crescente13[MAX_TAM];
                int comparacoes_crescente13[MAX_TAM];
                int movimentacoes_crescente13[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                insercao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime13 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime13 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente13[i] = endTime13 - startTime13;
                comparacoes_crescente13[i] = comparacoes;
                movimentacoes_crescente13[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente13 = 0.0;
                int media_comparacoes_crescente13 = 0;
                int media_movimentacoes_crescente13 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente13 += tempo_crescente13[i];
                    media_comparacoes_crescente13 += comparacoes_crescente13[i];
                    media_movimentacoes_crescente13 += movimentacoes_crescente13[i];
                }
                media_tempo_crescente13 /= MAX_TAM;
                media_comparacoes_crescente13 /= MAX_TAM;
                media_movimentacoes_crescente13 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente13);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente13);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente13);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente13[MAX_TAM];
                int comparacoes_decrescente13[MAX_TAM];
                int movimentacoes_decrescente13[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                insercao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime13 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime13 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente13[i] = endTime13 - startTime13;
                comparacoes_decrescente13[i] = comparacoes;
                movimentacoes_decrescente13[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente13 = 0.0;
                int media_comparacoes_decrescente13 = 0;
                int media_movimentacoes_decrescente13 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente13 += tempo_decrescente13[i];
                    media_comparacoes_decrescente13 += comparacoes_decrescente13[i];
                    media_movimentacoes_decrescente13 += movimentacoes_decrescente13[i];
                }
                media_tempo_decrescente13 /= MAX_TAM;
                media_comparacoes_decrescente13 /= MAX_TAM;
                media_movimentacoes_decrescente13 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente13);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente13);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente13);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio13[MAX_TAM];
                int comparacoes_aleatorio13[MAX_TAM];
                int movimentacoes_aleatorio13[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                insercao(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime13 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime13 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio13[i] = endTime13 - startTime13;
                comparacoes_aleatorio13[i] = comparacoes;
                movimentacoes_aleatorio13[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio13= 0.0;
                int media_comparacoes_aleatorio13 = 0;
                int media_movimentacoes_aleatorio13 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio13 += tempo_aleatorio13[i];
                media_comparacoes_aleatorio13 += comparacoes_aleatorio13[i];
                media_movimentacoes_aleatorio13 += movimentacoes_aleatorio13[i];
                }
                media_tempo_aleatorio13 /= MAX_TAM;
                media_comparacoes_aleatorio13/= MAX_TAM;
                media_movimentacoes_aleatorio13 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio13);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio13);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio13);
                printf("\n");
                
                //Ordenação shellsort
                printf("\n");
                printf("Ordencao por Shellsort\n");
                //ordem crescente
                long double tempo_crescente14[MAX_TAM];
                int comparacoes_crescente14[MAX_TAM];
                int movimentacoes_crescente14[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                shellsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime14 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime14 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente14[i] = endTime14 - startTime14;
                comparacoes_crescente14[i] = comparacoes;
                movimentacoes_crescente14[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente14 = 0.0;
                int media_comparacoes_crescente14 = 0;
                int media_movimentacoes_crescente14 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente14 += tempo_crescente14[i];
                    media_comparacoes_crescente14 += comparacoes_crescente14[i];
                    media_movimentacoes_crescente14 += movimentacoes_crescente14[i];
                }
                media_tempo_crescente14 /= MAX_TAM;
                media_comparacoes_crescente14 /= MAX_TAM;
                media_movimentacoes_crescente14 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente8);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente8);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente8);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente14[MAX_TAM];
                int comparacoes_decrescente14[MAX_TAM];
                int movimentacoes_decrescente14[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime14 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime14 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente14[i] = endTime14 - startTime14;
                comparacoes_decrescente14[i] = comparacoes;
                movimentacoes_decrescente14[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente14 = 0.0;
                int media_comparacoes_decrescente14 = 0;
                int media_movimentacoes_decrescente14 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente14 += tempo_decrescente14[i];
                    media_comparacoes_decrescente14 += comparacoes_decrescente14[i];
                    media_movimentacoes_decrescente14 += movimentacoes_decrescente14[i];
                }
                media_tempo_decrescente14 /= MAX_TAM;
                media_comparacoes_decrescente14 /= MAX_TAM;
                media_movimentacoes_decrescente14 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente14);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente14);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente14);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio14[MAX_TAM];
                int comparacoes_aleatorio14[MAX_TAM];
                int movimentacoes_aleatorio14[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                shellsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime14 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime14 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio14[i] = endTime14 - startTime14;
                comparacoes_aleatorio14[i] = comparacoes;
                movimentacoes_aleatorio14[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio14 = 0.0;
                int media_comparacoes_aleatorio14 = 0;
                int media_movimentacoes_aleatorio14 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio14 += tempo_aleatorio14[i];
                media_comparacoes_aleatorio14 += comparacoes_aleatorio14[i];
                media_movimentacoes_aleatorio14 += movimentacoes_aleatorio14[i];
                }
                media_tempo_aleatorio14 /= MAX_TAM;
                media_comparacoes_aleatorio14 /= MAX_TAM;
                media_movimentacoes_aleatorio14 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio14);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio14);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio14);
                printf("\n");
                
                //Ordenação quicksort
                printf("\n");
                printf("Ordencao por QuickSort\n");
                //ordem crescente
                long double tempo_crescente15[MAX_TAM];
                int comparacoes_crescente15[MAX_TAM];
                int movimentacoes_crescente15[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                quicksort(vetor3, 0, 4999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime15 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime15 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente15[i] = endTime15 - startTime15;
                comparacoes_crescente15[i] = comparacoes;
                movimentacoes_crescente15[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente15 = 0.0;
                int media_comparacoes_crescente15 = 0;
                int media_movimentacoes_crescente15 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente15 += tempo_crescente15[i];
                    media_comparacoes_crescente15 += comparacoes_crescente15[i];
                    media_movimentacoes_crescente15 += movimentacoes_crescente15[i];
                }
                media_tempo_crescente15 /= MAX_TAM;
                media_comparacoes_crescente15 /= MAX_TAM;
                media_movimentacoes_crescente15 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente15);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente15);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente15);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente15[MAX_TAM];
                int comparacoes_decrescente15[MAX_TAM];
                int movimentacoes_decrescente15[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                quicksort(vetor3, 0, 4999 , &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime15 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime15 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente15[i] = endTime15 - startTime15;
                comparacoes_decrescente15[i] = comparacoes;
                movimentacoes_decrescente15[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente15 = 0.0;
                int media_comparacoes_decrescente15 = 0;
                int media_movimentacoes_decrescente15 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente15 += tempo_decrescente15[i];
                    media_comparacoes_decrescente15 += comparacoes_decrescente15[i];
                    media_movimentacoes_decrescente15 += movimentacoes_decrescente15[i];
                }
                media_tempo_decrescente15 /= MAX_TAM;
                media_comparacoes_decrescente15 /= MAX_TAM;
                media_movimentacoes_decrescente15 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente15);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente15);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente15);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio15[MAX_TAM];
                int comparacoes_aleatorio15[MAX_TAM];
                int movimentacoes_aleatorio15[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                quicksort(vetor3, 0, 4999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime15 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime15 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio15[i] = endTime15 - startTime15;
                comparacoes_aleatorio15[i] = comparacoes;
                movimentacoes_aleatorio15[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio15 = 0.0;
                int media_comparacoes_aleatorio15 = 0;
                int media_movimentacoes_aleatorio15 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio15 += tempo_aleatorio15[i];
                media_comparacoes_aleatorio15 += comparacoes_aleatorio15[i];
                media_movimentacoes_aleatorio15 += movimentacoes_aleatorio15[i];
                }
                media_tempo_aleatorio15/= MAX_TAM;
                media_comparacoes_aleatorio15 /= MAX_TAM;
                media_movimentacoes_aleatorio15 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio15);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio15);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio15);
                printf("\n");
                
                //Ordenação heapsort
                 printf("\n");
                printf("Ordencao por HeapSort\n");
                //ordem crescente
                long double tempo_crescente16[MAX_TAM];
                int comparacoes_crescente16[MAX_TAM];
                int movimentacoes_crescente16[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                heapsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime16 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime16 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente16[i] = endTime16 - startTime16;
                comparacoes_crescente16[i] = comparacoes;
                movimentacoes_crescente16[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente16 = 0.0;
                int media_comparacoes_crescente16 = 0;
                int media_movimentacoes_crescente16 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente16 += tempo_crescente16[i];
                    media_comparacoes_crescente16 += comparacoes_crescente16[i];
                    media_movimentacoes_crescente16 += movimentacoes_crescente16[i];
                }
                media_tempo_crescente16 /= MAX_TAM;
                media_comparacoes_crescente16 /= MAX_TAM;
                media_movimentacoes_crescente16 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente16);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente16);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente16);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente16[MAX_TAM];
                int comparacoes_decrescente16[MAX_TAM];
                int movimentacoes_decrescente16[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                heapsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime16 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime16 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente16[i] = endTime16 - startTime16;
                comparacoes_decrescente16[i] = comparacoes;
                movimentacoes_decrescente16[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente16 = 0.0;
                int media_comparacoes_decrescente16 = 0;
                int media_movimentacoes_decrescente16 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente16 += tempo_decrescente16[i];
                    media_comparacoes_decrescente16 += comparacoes_decrescente16[i];
                    media_movimentacoes_decrescente16 += movimentacoes_decrescente16[i];
                }
                media_tempo_decrescente16 /= MAX_TAM;
                media_comparacoes_decrescente16 /= MAX_TAM;
                media_movimentacoes_decrescente16 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente16);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente16);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente16);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio16[MAX_TAM];
                int comparacoes_aleatorio16[MAX_TAM];
                int movimentacoes_aleatorio16[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                heapsort(vetor3, 5000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime16 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime16 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio16[i] = endTime16 - startTime16;
                comparacoes_aleatorio16[i] = comparacoes;
                movimentacoes_aleatorio16[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio16 = 0.0;
                int media_comparacoes_aleatorio16 = 0;
                int media_movimentacoes_aleatorio16 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio16 += tempo_aleatorio16[i];
                media_comparacoes_aleatorio16 += comparacoes_aleatorio16[i];
                media_movimentacoes_aleatorio16 += movimentacoes_aleatorio16[i];
                }
                media_tempo_aleatorio16 /= MAX_TAM;
                media_comparacoes_aleatorio16 /= MAX_TAM;
                media_movimentacoes_aleatorio16 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio16);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio16);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio16);
                printf("\n");
                
                //Ordenação mergesort
                printf("\n");
                printf("Ordenacao por Mergesort\n");
                //ordem crescente
                long double tempo_crescente17[MAX_TAM];
                int comparacoes_crescente17[MAX_TAM];
                int movimentacoes_crescente17[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                mergesort(vetor3, 0, 4999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime17 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime17 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente17[i] = endTime17 - startTime17;
                comparacoes_crescente17[i] = comparacoes;
                movimentacoes_crescente17[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente17 = 0.0;
                int media_comparacoes_crescente17 = 0;
                int media_movimentacoes_crescente17 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente17+= tempo_crescente17[i];
                    media_comparacoes_crescente17 += comparacoes_crescente17[i];
                    media_movimentacoes_crescente17+= movimentacoes_crescente17[i];
                }
                media_tempo_crescente17 /= MAX_TAM;
                media_comparacoes_crescente17 /= MAX_TAM;
                media_movimentacoes_crescente17 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente17);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente17);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente17);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente17[MAX_TAM];
                int comparacoes_decrescente17[MAX_TAM];
                int movimentacoes_decrescente17[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 5000; j++) {
                    vetor3[j].chave = 5000 - j;
                }
                gettimeofday(&start, NULL);
                mergesort(vetor3, 0, 4999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime17 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime17 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente17[i] = endTime17 - startTime17;
                comparacoes_decrescente17[i] = comparacoes;
                movimentacoes_decrescente17[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente17 = 0.0;
                int media_comparacoes_decrescente17 = 0;
                int media_movimentacoes_decrescente17 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente17 += tempo_decrescente17[i];
                    media_comparacoes_decrescente17 += comparacoes_decrescente17[i];
                    media_movimentacoes_decrescente17 += movimentacoes_decrescente17[i];
                }
                media_tempo_decrescente17 /= MAX_TAM;
                media_comparacoes_decrescente17 /= MAX_TAM;
                media_movimentacoes_decrescente17 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente17);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente17);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente17);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio17[MAX_TAM];
                int comparacoes_aleatorio17[MAX_TAM];
                int movimentacoes_aleatorio17[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor3[5000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 5000; j++) {
                        vetor3[j].chave = j + 1;
                }
                embaralharVetor(vetor3, 5000);
                gettimeofday(&start, NULL);
                mergesort(vetor3, 0, 4999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime17 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime17 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio17[i] = endTime17 - startTime17;
                comparacoes_aleatorio17[i] = comparacoes;
                movimentacoes_aleatorio17[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio17 = 0.0;
                int media_comparacoes_aleatorio17 = 0;
                int media_movimentacoes_aleatorio17 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio17 += tempo_aleatorio17[i];
                media_comparacoes_aleatorio17 += comparacoes_aleatorio17[i];
                media_movimentacoes_aleatorio17 += movimentacoes_aleatorio17[i];
                }
                media_tempo_aleatorio17 /= MAX_TAM;
                media_comparacoes_aleatorio17 /= MAX_TAM;
                media_movimentacoes_aleatorio17 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio17);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio17);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio17);
                printf("\n");
                
                system("PAUSE");
                break;

                case 4:
                printf("Voce selecionou o vetor de tamanho 10000:\n");
                printf("\n");
                //Ordenacao por selecao
                printf("Ordenacao por Selecao\n");
                //ordem crescente
                long double tempo_crescente18[MAX_TAM];
                int comparacoes_crescente18[MAX_TAM];
                int movimentacoes_crescente18[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                selecao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime18 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime18 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente18[i] = endTime18 - startTime18;
                comparacoes_crescente18[i] = comparacoes;
                movimentacoes_crescente18[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente18 = 0.0;
                int media_comparacoes_crescente18 = 0;
                int media_movimentacoes_crescente18 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente18 += tempo_crescente18[i];
                    media_comparacoes_crescente18 += comparacoes_crescente18[i];
                    media_movimentacoes_crescente18 += movimentacoes_crescente18[i];
                }
                media_tempo_crescente18 /= MAX_TAM;
                media_comparacoes_crescente18 /= MAX_TAM;
                media_movimentacoes_crescente18 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente18);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente18);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente18);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente18[MAX_TAM];
                int comparacoes_decrescente18[MAX_TAM];
                int movimentacoes_decrescente18[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                selecao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime18 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime18 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente18[i] = endTime18 - startTime18;
                comparacoes_decrescente18[i] = comparacoes;
                movimentacoes_decrescente18[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente18 = 0.0;
                int media_comparacoes_decrescente18 = 0;
                int media_movimentacoes_decrescente18 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente18 += tempo_decrescente18[i];
                    media_comparacoes_decrescente18+= comparacoes_decrescente18[i];
                    media_movimentacoes_decrescente18 += movimentacoes_decrescente18[i];
                }
                media_tempo_decrescente18 /= MAX_TAM;
                media_comparacoes_decrescente18 /= MAX_TAM;
                media_movimentacoes_decrescente18 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente18);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente18);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente18);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio18[MAX_TAM];
                int comparacoes_aleatorio18[MAX_TAM];
                int movimentacoes_aleatorio18[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                selecao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime18 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime18 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio18[i] = endTime18 - startTime18;
                comparacoes_aleatorio18[i] = comparacoes;
                movimentacoes_aleatorio18[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio18 = 0.0;
                int media_comparacoes_aleatorio18 = 0;
                int media_movimentacoes_aleatorio18 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio18 += tempo_aleatorio18[i];
                media_comparacoes_aleatorio18 += comparacoes_aleatorio18[i];
                media_movimentacoes_aleatorio18 += movimentacoes_aleatorio18[i];
                }
                media_tempo_aleatorio18 /= MAX_TAM;
                media_comparacoes_aleatorio18 /= MAX_TAM;
                media_movimentacoes_aleatorio18 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio18);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio18);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio18);
                printf("\n");
                
                //Ordenação por inserção
                //ordem crescente
                printf("\nOrdencao por Insercao:\n");
                long double tempo_crescente19[MAX_TAM];
                int comparacoes_crescente19[MAX_TAM];
                int movimentacoes_crescente19[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                insercao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime19 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime19 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente19[i] = endTime19 - startTime19;
                comparacoes_crescente19[i] = comparacoes;
                movimentacoes_crescente19[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente19 = 0.0;
                int media_comparacoes_crescente19 = 0;
                int media_movimentacoes_crescente19 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente19 += tempo_crescente19[i];
                    media_comparacoes_crescente19 += comparacoes_crescente19[i];
                    media_movimentacoes_crescente19 += movimentacoes_crescente19[i];
                }
                media_tempo_crescente19 /= MAX_TAM;
                media_comparacoes_crescente19/= MAX_TAM;
                media_movimentacoes_crescente19 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente19);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente19);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente19);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente19[MAX_TAM];
                int comparacoes_decrescente19[MAX_TAM];
                int movimentacoes_decrescente19[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                insercao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime19 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime19 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente19[i] = endTime19 - startTime19;
                comparacoes_decrescente19[i] = comparacoes;
                movimentacoes_decrescente19[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente19 = 0.0;
                int media_comparacoes_decrescente19 = 0;
                int media_movimentacoes_decrescente19 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente19 += tempo_decrescente19[i];
                    media_comparacoes_decrescente19 += comparacoes_decrescente19[i];
                    media_movimentacoes_decrescente19 += movimentacoes_decrescente19[i];
                }
                media_tempo_decrescente19 /= MAX_TAM;
                media_comparacoes_decrescente19 /= MAX_TAM;
                media_movimentacoes_decrescente19 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente19);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente19);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente19);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio19[MAX_TAM];
                int comparacoes_aleatorio19[MAX_TAM];
                int movimentacoes_aleatorio19[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                insercao(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime19 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime19 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio19[i] = endTime19 - startTime19;
                comparacoes_aleatorio19[i] = comparacoes;
                movimentacoes_aleatorio19[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio19= 0.0;
                int media_comparacoes_aleatorio19 = 0;
                int media_movimentacoes_aleatorio19 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio19 += tempo_aleatorio19[i];
                media_comparacoes_aleatorio19 += comparacoes_aleatorio19[i];
                media_movimentacoes_aleatorio19 += movimentacoes_aleatorio19[i];
                }
                media_tempo_aleatorio19 /= MAX_TAM;
                media_comparacoes_aleatorio19/= MAX_TAM;
                media_movimentacoes_aleatorio19 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio19);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio19);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio19);
                printf("\n");
                
                //Ordenação shellsort
                printf("\n");
                printf("Ordencao por Shellsort\n");
                //ordem crescente
                long double tempo_crescente21[MAX_TAM];
                int comparacoes_crescente21[MAX_TAM];
                int movimentacoes_crescente21[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                shellsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime21 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime21 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente21[i] = endTime21 - startTime21;
                comparacoes_crescente21[i] = comparacoes;
                movimentacoes_crescente21[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente21 = 0.0;
                int media_comparacoes_crescente21 = 0;
                int media_movimentacoes_crescente21 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente21 += tempo_crescente21[i];
                    media_comparacoes_crescente21 += comparacoes_crescente21[i];
                    media_movimentacoes_crescente21 += movimentacoes_crescente21[i];
                }
                media_tempo_crescente21 /= MAX_TAM;
                media_comparacoes_crescente21 /= MAX_TAM;
                media_movimentacoes_crescente21/= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente21);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente21);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente21);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente21[MAX_TAM];
                int comparacoes_decrescente21[MAX_TAM];
                int movimentacoes_decrescente21[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime21 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime21 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente21[i] = endTime21 - startTime21;
                comparacoes_decrescente21[i] = comparacoes;
                movimentacoes_decrescente21[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente21 = 0.0;
                int media_comparacoes_decrescente21 = 0;
                int media_movimentacoes_decrescente21 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente21 += tempo_decrescente21[i];
                    media_comparacoes_decrescente21 += comparacoes_decrescente21[i];
                    media_movimentacoes_decrescente21 += movimentacoes_decrescente21[i];
                }
                media_tempo_decrescente21 /= MAX_TAM;
                media_comparacoes_decrescente21 /= MAX_TAM;
                media_movimentacoes_decrescente21 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente21);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente21);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente21);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio21[MAX_TAM];
                int comparacoes_aleatorio21[MAX_TAM];
                int movimentacoes_aleatorio21[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                shellsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime21 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime21 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio21[i] = endTime21 - startTime21;
                comparacoes_aleatorio21[i] = comparacoes;
                movimentacoes_aleatorio21[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio21 = 0.0;
                int media_comparacoes_aleatorio21 = 0;
                int media_movimentacoes_aleatorio21 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio21 += tempo_aleatorio21[i];
                media_comparacoes_aleatorio21 += comparacoes_aleatorio21[i];
                media_movimentacoes_aleatorio21 += movimentacoes_aleatorio21[i];
                }
                media_tempo_aleatorio21 /= MAX_TAM;
                media_comparacoes_aleatorio21 /= MAX_TAM;
                media_movimentacoes_aleatorio21 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio21);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio21);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio21);
                printf("\n");
                
                //Ordenação quicksort
                printf("\n");
                printf("Ordencao por QuickSort\n");
                //ordem crescente
                long double tempo_crescente22[MAX_TAM];
                int comparacoes_crescente22[MAX_TAM];
                int movimentacoes_crescente22[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                quicksort(vetor4, 0, 9999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime22 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime22 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente22[i] = endTime22 - startTime22;
                comparacoes_crescente22[i] = comparacoes;
                movimentacoes_crescente22[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente22 = 0.0;
                int media_comparacoes_crescente22 = 0;
                int media_movimentacoes_crescente22 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente22 += tempo_crescente22[i];
                    media_comparacoes_crescente22 += comparacoes_crescente22[i];
                    media_movimentacoes_crescente22 += movimentacoes_crescente22[i];
                }
                media_tempo_crescente22 /= MAX_TAM;
                media_comparacoes_crescente22 /= MAX_TAM;
                media_movimentacoes_crescente22 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente22);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente22);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente22);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente22[MAX_TAM];
                int comparacoes_decrescente22[MAX_TAM];
                int movimentacoes_decrescente22[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                quicksort(vetor4, 0, 9999 , &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime22 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime22 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente22[i] = endTime22 - startTime22;
                comparacoes_decrescente22[i] = comparacoes;
                movimentacoes_decrescente22[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente22 = 0.0;
                int media_comparacoes_decrescente22 = 0;
                int media_movimentacoes_decrescente22 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente22+= tempo_decrescente22[i];
                    media_comparacoes_decrescente22 += comparacoes_decrescente22[i];
                    media_movimentacoes_decrescente22+= movimentacoes_decrescente22[i];
                }
                media_tempo_decrescente22 /= MAX_TAM;
                media_comparacoes_decrescente22 /= MAX_TAM;
                media_movimentacoes_decrescente22 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente22);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente22);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente22);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio22[MAX_TAM];
                int comparacoes_aleatorio22[MAX_TAM];
                int movimentacoes_aleatorio22[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                quicksort(vetor4, 0, 9999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime22 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime22 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio22[i] = endTime22 - startTime22;
                comparacoes_aleatorio22[i] = comparacoes;
                movimentacoes_aleatorio22[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio22 = 0.0;
                int media_comparacoes_aleatorio22 = 0;
                int media_movimentacoes_aleatorio22 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio22 += tempo_aleatorio22[i];
                media_comparacoes_aleatorio22 += comparacoes_aleatorio22[i];
                media_movimentacoes_aleatorio22 += movimentacoes_aleatorio22[i];
                }
                media_tempo_aleatorio22/= MAX_TAM;
                media_comparacoes_aleatorio22 /= MAX_TAM;
                media_movimentacoes_aleatorio22 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio22);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio22);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio22);
                printf("\n");
                
                //Ordenação heapsort
                 printf("\n");
                printf("Ordencao por HeapSort\n");
                //ordem crescente
                long double tempo_crescente23[MAX_TAM];
                int comparacoes_crescente23[MAX_TAM];
                int movimentacoes_crescente23[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                heapsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime23 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime23 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente23[i] = endTime23 - startTime23;
                comparacoes_crescente23[i] = comparacoes;
                movimentacoes_crescente23[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente23 = 0.0;
                int media_comparacoes_crescente23 = 0;
                int media_movimentacoes_crescente23 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente23 += tempo_crescente23[i];
                    media_comparacoes_crescente23 += comparacoes_crescente23[i];
                    media_movimentacoes_crescente23 += movimentacoes_crescente23[i];
                }
                media_tempo_crescente23 /= MAX_TAM;
                media_comparacoes_crescente23 /= MAX_TAM;
                media_movimentacoes_crescente23 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente23);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente23);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente23);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente23[MAX_TAM];
                int comparacoes_decrescente23[MAX_TAM];
                int movimentacoes_decrescente23[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                heapsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime23 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime23 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente23[i] = endTime23 - startTime23;
                comparacoes_decrescente23[i] = comparacoes;
                movimentacoes_decrescente23[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente23 = 0.0;
                int media_comparacoes_decrescente23 = 0;
                int media_movimentacoes_decrescente23 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente23 += tempo_decrescente23[i];
                    media_comparacoes_decrescente23 += comparacoes_decrescente23[i];
                    media_movimentacoes_decrescente23 += movimentacoes_decrescente23[i];
                }
                media_tempo_decrescente23/= MAX_TAM;
                media_comparacoes_decrescente23 /= MAX_TAM;
                media_movimentacoes_decrescente23 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente23);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente23);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente23);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio23[MAX_TAM];
                int comparacoes_aleatorio23[MAX_TAM];
                int movimentacoes_aleatorio23[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                heapsort(vetor4, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime23= start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime23 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio23[i] = endTime23 - startTime23;
                comparacoes_aleatorio23[i] = comparacoes;
                movimentacoes_aleatorio23[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio23 = 0.0;
                int media_comparacoes_aleatorio23 = 0;
                int media_movimentacoes_aleatorio23 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio23 += tempo_aleatorio23[i];
                media_comparacoes_aleatorio23 += comparacoes_aleatorio23[i];
                media_movimentacoes_aleatorio23 += movimentacoes_aleatorio23[i];
                }
                media_tempo_aleatorio23 /= MAX_TAM;
                media_comparacoes_aleatorio23 /= MAX_TAM;
                media_movimentacoes_aleatorio23 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio23);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio23);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio23);
                printf("\n");
                
                //Ordenação mergesort
                printf("\n");
                printf("Ordenacao por Mergesort\n");
                //ordem crescente
                long double tempo_crescente24[MAX_TAM];
                int comparacoes_crescente24[MAX_TAM];
                int movimentacoes_crescente24[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                mergesort(vetor4, 0, 9999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime24 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime24 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente24[i] = endTime24- startTime24;
                comparacoes_crescente24[i] = comparacoes;
                movimentacoes_crescente24[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente24 = 0.0;
                int media_comparacoes_crescente24 = 0;
                int media_movimentacoes_crescente24 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente24 += tempo_crescente24[i];
                    media_comparacoes_crescente24 += comparacoes_crescente24[i];
                    media_movimentacoes_crescente24 += movimentacoes_crescente24[i];
                }
                media_tempo_crescente24 /= MAX_TAM;
                media_comparacoes_crescente24 /= MAX_TAM;
                media_movimentacoes_crescente24 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente24);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente24);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente24);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente24[MAX_TAM];
                int comparacoes_decrescente24[MAX_TAM];
                int movimentacoes_decrescente24[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 10000; j++) {
                    vetor4[j].chave = 10000 - j;
                }
                gettimeofday(&start, NULL);
                mergesort(vetor4, 0, 9999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime24 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime24 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente24[i] = endTime24 - startTime24;
                comparacoes_decrescente24[i] = comparacoes;
                movimentacoes_decrescente24[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente24 = 0.0;
                int media_comparacoes_decrescente24 = 0;
                int media_movimentacoes_decrescente24 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente24 += tempo_decrescente24[i];
                    media_comparacoes_decrescente24 += comparacoes_decrescente24[i];
                    media_movimentacoes_decrescente24 += movimentacoes_decrescente24[i];
                }
                media_tempo_decrescente24 /= MAX_TAM;
                media_comparacoes_decrescente24 /= MAX_TAM;
                media_movimentacoes_decrescente24 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente24);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente24);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente24);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio24[MAX_TAM];
                int comparacoes_aleatorio24[MAX_TAM];
                int movimentacoes_aleatorio24[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[10000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 10000; j++) {
                        vetor4[j].chave = j + 1;
                }
                embaralharVetor(vetor4, 10000);
                gettimeofday(&start, NULL);
                mergesort(vetor4, 0, 9999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime24 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime24 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio24[i] = endTime24 - startTime24;
                comparacoes_aleatorio24[i] = comparacoes;
                movimentacoes_aleatorio24[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio24 = 0.0;
                int media_comparacoes_aleatorio24 = 0;
                int media_movimentacoes_aleatorio24 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio24 += tempo_aleatorio24[i];
                media_comparacoes_aleatorio24 += comparacoes_aleatorio24[i];
                media_movimentacoes_aleatorio24 += movimentacoes_aleatorio24[i];
                }
                media_tempo_aleatorio24/= MAX_TAM;
                media_comparacoes_aleatorio24 /= MAX_TAM;
                media_movimentacoes_aleatorio24/= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio24);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio24);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio24);
                printf("\n");
                
                system("PAUSE");
                break;
            
            case 5:
                printf("Voce selecionou o vetor de tamanho 200000:\n");
                printf("\n");
                //Ordenacao por selecao
                printf("Ordenacao por Selecao\n");
                //ordem crescente
                long double tempo_crescente25[MAX_TAM];
                int comparacoes_crescente25[MAX_TAM];
                int movimentacoes_crescente25[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                selecao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime25 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime25 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente25[i] = endTime25 - startTime25;
                comparacoes_crescente25[i] = comparacoes;
                movimentacoes_crescente25[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente25 = 0.0;
                int media_comparacoes_crescente25 = 0;
                int media_movimentacoes_crescente25 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente25 += tempo_crescente25[i];
                    media_comparacoes_crescente25 += comparacoes_crescente25[i];
                    media_movimentacoes_crescente25 += movimentacoes_crescente25[i];
                }
                media_tempo_crescente25 /= MAX_TAM;
                media_comparacoes_crescente25 /= MAX_TAM;
                media_movimentacoes_crescente25 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente25);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente25);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente25);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente25[MAX_TAM];
                int comparacoes_decrescente25[MAX_TAM];
                int movimentacoes_decrescente25[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                selecao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime25 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime25 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente25[i] = endTime25 - startTime25;
                comparacoes_decrescente25[i] = comparacoes;
                movimentacoes_decrescente25[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente25 = 0.0;
                int media_comparacoes_decrescente25 = 0;
                int media_movimentacoes_decrescente25 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente25 += tempo_decrescente25[i];
                    media_comparacoes_decrescente25+= comparacoes_decrescente25[i];
                    media_movimentacoes_decrescente25 += movimentacoes_decrescente25[i];
                }
                media_tempo_decrescente25 /= MAX_TAM;
                media_comparacoes_decrescente25 /= MAX_TAM;
                media_movimentacoes_decrescente25 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente25);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente25);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente25);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio25[MAX_TAM];
                int comparacoes_aleatorio25[MAX_TAM];
                int movimentacoes_aleatorio25[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                selecao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime25 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime25 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio25[i] = endTime25 - startTime25;
                comparacoes_aleatorio25[i] = comparacoes;
                movimentacoes_aleatorio25[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio25 = 0.0;
                int media_comparacoes_aleatorio25 = 0;
                int media_movimentacoes_aleatorio25 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio25 += tempo_aleatorio25[i];
                media_comparacoes_aleatorio25 += comparacoes_aleatorio25[i];
                media_movimentacoes_aleatorio25 += movimentacoes_aleatorio25[i];
                }
                media_tempo_aleatorio25/= MAX_TAM;
                media_comparacoes_aleatorio25/= MAX_TAM;
                media_movimentacoes_aleatorio25 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio25);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio25);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio25);
                printf("\n");
                
                //Ordenação por inserção
                //ordem crescente
                printf("\nOrdencao por Insercao:\n");
                long double tempo_crescente26[MAX_TAM];
                int comparacoes_crescente26[MAX_TAM];
                int movimentacoes_crescente26[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                insercao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime26 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime26 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente26[i] = endTime26 - startTime26;
                comparacoes_crescente26[i] = comparacoes;
                movimentacoes_crescente26[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente26 = 0.0;
                int media_comparacoes_crescente26 = 0;
                int media_movimentacoes_crescente26 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente26 += tempo_crescente26[i];
                    media_comparacoes_crescente26 += comparacoes_crescente26[i];
                    media_movimentacoes_crescente26 += movimentacoes_crescente26[i];
                }
                media_tempo_crescente26 /= MAX_TAM;
                media_comparacoes_crescente26/= MAX_TAM;
                media_movimentacoes_crescente26 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente26);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente26);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente26);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente26[MAX_TAM];
                int comparacoes_decrescente26[MAX_TAM];
                int movimentacoes_decrescente26[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                insercao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime26 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime26 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente26[i] = endTime26 - startTime26;
                comparacoes_decrescente26[i] = comparacoes;
                movimentacoes_decrescente26[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente26 = 0.0;
                int media_comparacoes_decrescente26 = 0;
                int media_movimentacoes_decrescente26 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente26 += tempo_decrescente26[i];
                    media_comparacoes_decrescente26 += comparacoes_decrescente26[i];
                    media_movimentacoes_decrescente26 += movimentacoes_decrescente26[i];
                }
                media_tempo_decrescente26 /= MAX_TAM;
                media_comparacoes_decrescente26 /= MAX_TAM;
                media_movimentacoes_decrescente26 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente19);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente19);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente19);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio26[MAX_TAM];
                int comparacoes_aleatorio26[MAX_TAM];
                int movimentacoes_aleatorio26[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                insercao(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime26 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime26 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio26[i] = endTime26 - startTime26;
                comparacoes_aleatorio26[i] = comparacoes;
                movimentacoes_aleatorio26[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio26= 0.0;
                int media_comparacoes_aleatorio26 = 0;
                int media_movimentacoes_aleatorio26 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio26 += tempo_aleatorio26[i];
                media_comparacoes_aleatorio26 += comparacoes_aleatorio26[i];
                media_movimentacoes_aleatorio26 += movimentacoes_aleatorio26[i];
                }
                media_tempo_aleatorio26 /= MAX_TAM;
                media_comparacoes_aleatorio26/= MAX_TAM;
                media_movimentacoes_aleatorio26 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio26);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio26);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio26);
                printf("\n");
                
                //Ordenação shellsort
                printf("\n");
                printf("Ordencao por Shellsort\n");
                //ordem crescente
                long double tempo_crescente27[MAX_TAM];
                int comparacoes_crescente27[MAX_TAM];
                int movimentacoes_crescente27[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                shellsort(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime27 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime27 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente27[i] = endTime27 - startTime27;
                comparacoes_crescente27[i] = comparacoes;
                movimentacoes_crescente27[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente27 = 0.0;
                int media_comparacoes_crescente27 = 0;
                int media_movimentacoes_crescente27 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente27+= tempo_crescente27[i];
                    media_comparacoes_crescente27 += comparacoes_crescente27[i];
                    media_movimentacoes_crescente27 += movimentacoes_crescente27[i];
                }
                media_tempo_crescente27 /= MAX_TAM;
                media_comparacoes_crescente27 /= MAX_TAM;
                media_movimentacoes_crescente27/= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente27);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente27);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente27);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente27[MAX_TAM];
                int comparacoes_decrescente27[MAX_TAM];
                int movimentacoes_decrescente27[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                shellsort(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime27 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime27 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente27[i] = endTime27 - startTime27;
                comparacoes_decrescente27[i] = comparacoes;
                movimentacoes_decrescente27[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente27 = 0.0;
                int media_comparacoes_decrescente27 = 0;
                int media_movimentacoes_decrescente27 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente27+= tempo_decrescente27[i];
                    media_comparacoes_decrescente27 += comparacoes_decrescente27[i];
                    media_movimentacoes_decrescente27 += movimentacoes_decrescente27[i];
                }
                media_tempo_decrescente27 /= MAX_TAM;
                media_comparacoes_decrescente27 /= MAX_TAM;
                media_movimentacoes_decrescente27 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente27);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente27);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente27);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio27[MAX_TAM];
                int comparacoes_aleatorio27[MAX_TAM];
                int movimentacoes_aleatorio27[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                shellsort(vetor5, 10000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime27 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime27 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio27[i] = endTime27 - startTime27;
                comparacoes_aleatorio27[i] = comparacoes;
                movimentacoes_aleatorio27[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio27 = 0.0;
                int media_comparacoes_aleatorio27 = 0;
                int media_movimentacoes_aleatorio27 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio27 += tempo_aleatorio27[i];
                media_comparacoes_aleatorio27 += comparacoes_aleatorio27[i];
                media_movimentacoes_aleatorio27 += movimentacoes_aleatorio27[i];
                }
                media_tempo_aleatorio27 /= MAX_TAM;
                media_comparacoes_aleatorio27 /= MAX_TAM;
                media_movimentacoes_aleatorio27 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio27);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio27);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio27);
                printf("\n");
                
                //Ordenação quicksort
                printf("\n");
                printf("Ordenacao por QuickSort\n");
                //ordem crescente
                long double tempo_crescente28[MAX_TAM];
                int comparacoes_crescente28[MAX_TAM];
                int movimentacoes_crescente28[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                quicksort(vetor5, 0, 99999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime28 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime28 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente28[i] = endTime28 - startTime28;
                comparacoes_crescente28[i] = comparacoes;
                movimentacoes_crescente28[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente28 = 0.0;
                int media_comparacoes_crescente28 = 0;
                int media_movimentacoes_crescente28 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente28 += tempo_crescente28[i];
                    media_comparacoes_crescente28 += comparacoes_crescente28[i];
                    media_movimentacoes_crescente28+= movimentacoes_crescente28[i];
                }
                media_tempo_crescente28 /= MAX_TAM;
                media_comparacoes_crescente28 /= MAX_TAM;
                media_movimentacoes_crescente28 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente28);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente28);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente28);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente28[MAX_TAM];
                int comparacoes_decrescente28[MAX_TAM];
                int movimentacoes_decrescente28[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor4[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                quicksort(vetor5, 0, 99999 , &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime28 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime28 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente28[i] = endTime28- startTime28;
                comparacoes_decrescente28[i] = comparacoes;
                movimentacoes_decrescente28[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente28 = 0.0;
                int media_comparacoes_decrescente28 = 0;
                int media_movimentacoes_decrescente28 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente28+= tempo_decrescente28[i];
                    media_comparacoes_decrescente28+= comparacoes_decrescente28[i];
                    media_movimentacoes_decrescente28+= movimentacoes_decrescente28[i];
                }
                media_tempo_decrescente28 /= MAX_TAM;
                media_comparacoes_decrescente28 /= MAX_TAM;
                media_movimentacoes_decrescente28 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente28);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente28);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente28);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio28[MAX_TAM];
                int comparacoes_aleatorio28[MAX_TAM];
                int movimentacoes_aleatorio28[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                quicksort(vetor5, 0, 99999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime28 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime28 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio28[i] = endTime28 - startTime28;
                comparacoes_aleatorio28[i] = comparacoes;
                movimentacoes_aleatorio28[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio28 = 0.0;
                int media_comparacoes_aleatorio28 = 0;
                int media_movimentacoes_aleatorio28 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio28 += tempo_aleatorio28[i];
                media_comparacoes_aleatorio28+= comparacoes_aleatorio28[i];
                media_movimentacoes_aleatorio28+= movimentacoes_aleatorio28[i];
                }
                media_tempo_aleatorio28/= MAX_TAM;
                media_comparacoes_aleatorio28 /= MAX_TAM;
                media_movimentacoes_aleatorio28 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio28);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio28);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio28);
                printf("\n");
                
                //Ordenação heapsort
                 printf("\n");
                printf("Ordencao por HeapSort\n");
                //ordem crescente
                long double tempo_crescente29[MAX_TAM];
                int comparacoes_crescente29[MAX_TAM];
                int movimentacoes_crescente29[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                heapsort(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime29 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime29 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente29[i] = endTime29 - startTime29;
                comparacoes_crescente29[i] = comparacoes;
                movimentacoes_crescente29[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente29 = 0.0;
                int media_comparacoes_crescente29 = 0;
                int media_movimentacoes_crescente29 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente29 += tempo_crescente29[i];
                    media_comparacoes_crescente29+= comparacoes_crescente29[i];
                    media_movimentacoes_crescente29+= movimentacoes_crescente29[i];
                }
                media_tempo_crescente29/= MAX_TAM;
                media_comparacoes_crescente29/= MAX_TAM;
                media_movimentacoes_crescente29 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente29);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente29);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente29);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente29[MAX_TAM];
                int comparacoes_decrescente29[MAX_TAM];
                int movimentacoes_decrescente29[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                heapsort(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime29 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime29= end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente29[i] = endTime29 - startTime29;
                comparacoes_decrescente29[i] = comparacoes;
                movimentacoes_decrescente29[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente29 = 0.0;
                int media_comparacoes_decrescente29 = 0;
                int media_movimentacoes_decrescente29 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente29 += tempo_decrescente29[i];
                    media_comparacoes_decrescente29 += comparacoes_decrescente29[i];
                    media_movimentacoes_decrescente29 = movimentacoes_decrescente29[i];
                }
                media_tempo_decrescente29 /= MAX_TAM;
                media_comparacoes_decrescente29 /= MAX_TAM;
                media_movimentacoes_decrescente29 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente29);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente29);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente29);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio29[MAX_TAM];
                int comparacoes_aleatorio29[MAX_TAM];
                int movimentacoes_aleatorio29[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                heapsort(vetor5, 200000, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime29= start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime29 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio29[i] = endTime29- startTime29;
                comparacoes_aleatorio29[i] = comparacoes;
                movimentacoes_aleatorio29[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio29 = 0.0;
                int media_comparacoes_aleatorio29 = 0;
                int media_movimentacoes_aleatorio29 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio29+= tempo_aleatorio29[i];
                media_comparacoes_aleatorio29+= comparacoes_aleatorio29[i];
                media_movimentacoes_aleatorio29+= movimentacoes_aleatorio29[i];
                }
                media_tempo_aleatorio29/= MAX_TAM;
                media_comparacoes_aleatorio29/= MAX_TAM;
                media_movimentacoes_aleatorio29 /= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio29);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio29);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio29);
                printf("\n");
                
                //Ordenação mergesort
                printf("\n");
                printf("Ordenacao por Mergesort\n");
                //ordem crescente
                long double tempo_crescente33[MAX_TAM];
                int comparacoes_crescente33[MAX_TAM];
                int movimentacoes_crescente33[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem crescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = j + 1;
                }
                //Calcular tempo gasto
                gettimeofday(&start, NULL);
                mergesort(vetor5, 0, 99999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                long double startTime33 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime33 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_crescente33[i] = endTime33 - startTime33;
                comparacoes_crescente33[i] = comparacoes;
                movimentacoes_crescente33[i] = movimentacoes;
                }
                //Calcular média de tempo, comparações e movimentações
                long double media_tempo_crescente33 = 0.0;
                int media_comparacoes_crescente33 = 0;
                int media_movimentacoes_crescente33 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_crescente33 += tempo_crescente33[i];
                    media_comparacoes_crescente33 += comparacoes_crescente33[i];
                    media_movimentacoes_crescente33 += movimentacoes_crescente33[i];
                }
                media_tempo_crescente33 /= MAX_TAM;
                media_comparacoes_crescente33 /= MAX_TAM;
                media_movimentacoes_crescente33 /= MAX_TAM;

                printf("Resultados para vetor crescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_crescente33);
                printf("Media de comparacoes: %d\n", media_comparacoes_crescente33);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_crescente33);
                printf("\n");

                //Ordem decrescente               
                long double tempo_decrescente33[MAX_TAM];
                int comparacoes_decrescente33[MAX_TAM];
                int movimentacoes_decrescente33[MAX_TAM];
                //Executar a quantidade de vezes necessária para calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem decrescente
                for (int j = 0; j < 200000; j++) {
                    vetor5[j].chave = 200000 - j;
                }
                gettimeofday(&start, NULL);
                mergesort(vetor5, 0, 99999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime33 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime33 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_decrescente33[i] = endTime33 - startTime33;
                comparacoes_decrescente33[i] = comparacoes;
                movimentacoes_decrescente33[i] = movimentacoes;
                }
                //Calcular média
                long double media_tempo_decrescente33= 0.0;
                int media_comparacoes_decrescente33 = 0;
                int media_movimentacoes_decrescente33 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                    media_tempo_decrescente33 += tempo_decrescente33[i];
                    media_comparacoes_decrescente33 += comparacoes_decrescente33[i];
                    media_movimentacoes_decrescente33 += movimentacoes_decrescente33[i];
                }
                media_tempo_decrescente33 /= MAX_TAM;
                media_comparacoes_decrescente33 /= MAX_TAM;
                media_movimentacoes_decrescente33 /= MAX_TAM;

                printf("Resultados para vetor decrescente:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_decrescente33);
                printf("Media de comparacoes: %d\n", media_comparacoes_decrescente33);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_decrescente33);
                printf("\n");

                //Ordem aleatória
                long double tempo_aleatorio33[MAX_TAM];
                int comparacoes_aleatorio33[MAX_TAM];
                int movimentacoes_aleatorio33[MAX_TAM];
                //Executar a quantidade de vezes necessárias para se calcular a média
                for (int i = 0; i < MAX_TAM; i++) {
                    Item vetor5[200000];
                //Criar vetor em ordem aleatória
                for (int j = 0; j < 200000; j++) {
                        vetor5[j].chave = j + 1;
                }
                embaralharVetor(vetor5, 200000);
                gettimeofday(&start, NULL);
                mergesort(vetor5, 0, 99999, &comparacoes, &movimentacoes);
                gettimeofday(&end, NULL);
                //Calcular tempo gasto
                long double startTime33 = start.tv_sec + start.tv_usec / 1000000.0L;
                long double endTime33 = end.tv_sec + end.tv_usec / 1000000.0L;
                tempo_aleatorio33[i] = endTime33 - startTime33;
                comparacoes_aleatorio33[i] = comparacoes;
                movimentacoes_aleatorio33[i] = movimentacoes;
                }
                // Calcular média
                long double media_tempo_aleatorio33 = 0.0;
                int media_comparacoes_aleatorio33 = 0;
                int media_movimentacoes_aleatorio33 = 0;
                for (int i = 0; i < MAX_TAM; i++) {
                media_tempo_aleatorio33 += tempo_aleatorio33[i];
                media_comparacoes_aleatorio33 += comparacoes_aleatorio33[i];
                media_movimentacoes_aleatorio33+= movimentacoes_aleatorio33[i];
                }
                media_tempo_aleatorio33 /= MAX_TAM;
                media_comparacoes_aleatorio33 /= MAX_TAM;
                media_movimentacoes_aleatorio33/= MAX_TAM;

                printf("Resultados para vetor aleatorio:\n");
                printf("Media de tempo: %.6Lf segundos\n", media_tempo_aleatorio33);
                printf("Media de comparacoes: %d\n", media_comparacoes_aleatorio33);
                printf("Media de movimentacoes: %d\n", media_movimentacoes_aleatorio33);
                printf("\n");
                free(vetor5);
                system("PAUSE");
                break;

            default:
                printf("Voce digitou uma opcao nao valida. Tente novamente");
                system("PAUSE");
                break;
        }
      
}
