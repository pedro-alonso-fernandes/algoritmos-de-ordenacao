#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "algoritmos.h"

typedef enum{
	BOLHA,
	BOLHA_COM_PARADA,
	INSERCAO_DIRETA,
	INSERCAO_BINARIA,
	INSERCAO_TERNARIA,
   SHELLSORT,
	SELECTION_SORT,
	HEAPSORT,
	QUICKSORT_CENTRO_LOMUTO,
	QUICKSORT_CENTRO_HOARE,
	QUICKSORT_FIM,
	QUICKSORT_MEDIANA,
	MERGESORT,
	RADIXSORT,
	BUCKETSORT
}Algoritmo;

// Abre o arquivo "entrada.txt", carrega os valores para um vetor, e manda para algum algoritmo de ordenação
Registro* ordenarNumeros(Algoritmo algoritmo){
	
	// Utilizarei a struct registro para registrar a quantidade de comparações, de trocas e o tempo 
	// de execução dentro dos algoritmos
	Registro* registro = (Registro*) malloc(sizeof(Registro));
	registro->comparacoes = 0;
	registro->trocas = 0;
	registro->tempo = 0;

	clock_t cpuClock_inicio;
	clock_t cpuClock_fim;
	
	FILE *arq_entrada = fopen("entrada.txt", "r");

	if(arq_entrada != NULL){
		int qtdNums = 0;
		int temp;
		while(fscanf(arq_entrada, "%d\n", &temp) == 1)
			qtdNums++;

		int* vetor = (int*) calloc(qtdNums, sizeof(int));

		if(vetor != NULL){
			rewind(arq_entrada);		// Retorna o ponteiro do arquivo para a primeira linha

			// Lê o arquivo e guarda no vetor
			for(int i = 0; i < qtdNums; i++)
				fscanf(arq_entrada, "%d\n", &vetor[i]);

			switch (algoritmo){
				case SELECTION_SORT:
					cpuClock_inicio = clock();
					selectionSort(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case HEAPSORT:
					cpuClock_inicio = clock();
					heapSort(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case QUICKSORT_CENTRO_LOMUTO:
					cpuClock_inicio = clock();
					quickSortCentroLomuto(vetor, 0, qtdNums - 1, registro);
					cpuClock_fim = clock();
					break;
				case QUICKSORT_CENTRO_HOARE:
					cpuClock_inicio = clock();
					quickSortCentroHoare(vetor, 0, qtdNums - 1, registro);
					cpuClock_fim = clock();
					break;
				case QUICKSORT_FIM:
					cpuClock_inicio = clock();
					quickSortFim(vetor, 0, qtdNums - 1, registro);
					cpuClock_fim = clock();
					break;
				case QUICKSORT_MEDIANA:
					cpuClock_inicio = clock();
					quickSortMediana(vetor, 0, qtdNums - 1, registro);
					cpuClock_fim = clock();
					break;
				case MERGESORT:
					cpuClock_inicio = clock();
					mergeSort(vetor, 0, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case RADIXSORT:
					cpuClock_inicio = clock();
					radixSort(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case BUCKETSORT:
					cpuClock_inicio = clock();
					bucketSort(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case BOLHA:
					cpuClock_inicio = clock();
					bolha(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case BOLHA_COM_PARADA:
					cpuClock_inicio = clock();
					bolhaComParada(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case INSERCAO_DIRETA:
					cpuClock_inicio = clock();
					insercaoDireta(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case INSERCAO_BINARIA:
					cpuClock_inicio = clock();
					insercaoBinaria(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case INSERCAO_TERNARIA:
					cpuClock_inicio = clock();
					insercaoTernaria(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
				case SHELLSORT:
					cpuClock_inicio = clock();
					shellSort(vetor, qtdNums, registro);
					cpuClock_fim = clock();
					break;
			}

			// Calcula tempo de execução.
			// Usa um cast (double) para contabilizar os números após a vírgula
			registro->tempo = (double) (cpuClock_fim - cpuClock_inicio) / CLOCKS_PER_SEC;		

			// Cria o arquivo que conterá os elementos ordenados
			FILE *arq_saida = fopen("saida.txt", "w");

			if(arq_saida != NULL){
				for(int i = 0; i < qtdNums; i++){
					fprintf(arq_saida, "%d\n", vetor[i]);
				}
			}
			else
				printf("Erro ao criar e abrir o arquivo \"saida.txt\"!\n");

			fclose(arq_saida);
			free(vetor);
		}
		else
			printf("Erro ao alocar memória!\n");
	}
	else
		printf("Erro ao abrir o arquivo \"entrada.txt\"!\n");

	fclose(arq_entrada);

	return registro;
}