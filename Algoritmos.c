#include <stdio.h>
#include <stdlib.h>

typedef enum{
	SELECTION_SORT,
	HEAPSORT,
	QUICKSORT_CENTRO,
	QUICKSORT_FIM,
	QUICKSORT_MEIDANA,
	MERGESORT,
	RADIXSORT,
	BUCKETSORT
}Algoritmo;

void selectionSort(int* vetor, int qtdNums, int* registro);

// Abre o arquivo "entrada.txt", carrega os valores para um vetor, e manda para algum algoritmo de ordenação
int* ordenarNumeros(Algoritmo algoritmo){
	// Utilizarei o vetor registro para registrar a quantidade de comparações e trocas dentro dos algoritmos
	int* registro = (int*) malloc(2 * sizeof(int));
	registro[0] = 0;	// A posição 0 do vetor salva as comparações
	registro[1] = 0;	// A posição 1 do vetor salva as trocas
	
	FILE *arq_entrada = fopen("entrada.txt", "r");

	if(arq_entrada != NULL){
		int qtdLinhas = 0;
		int temp;
		while(fscanf(arq_entrada, "%d\n", &temp) == 1)
			qtdLinhas++;

		int* vetor = (int*) malloc(qtdLinhas * sizeof(int));

		if(vetor != NULL){
			rewind(arq_entrada);

			for(int i = 0; i < qtdLinhas; i++)
				fscanf(arq_entrada, "%d\n", &vetor[i]);

			switch (algoritmo){
				case SELECTION_SORT:
					selectionSort(vetor, qtdLinhas, registro);
					break;
				case HEAPSORT:
					// Chama a função
					break;
				case QUICKSORT_CENTRO:
					// Chama a função
					break;
				case QUICKSORT_FIM:
					// Chama a função
					break;
				case QUICKSORT_MEIDANA:
					// Chama a função
					break;
				case MERGESORT:
					// Chama a função
					break;
				case RADIXSORT:
					// Chama a função
					break;
				case BUCKETSORT:
					// Chama a função
					break;
			}

			// Cria o arquivo que conterá os elementos ordenados
			FILE *arq_saida = fopen("saida.txt", "w");

			if(arq_saida != NULL){
				for(int i = 0; i < qtdLinhas; i++){
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

void selectionSort(int* vetor, int qtdNums, int* registro){
	for(int i = 0; i < (qtdNums - 1); i++){
		int indice_menor = i;
		
		for(int j = i + 1; j < qtdNums; j++){
			if(vetor[j] < vetor[indice_menor]){
				registro[0]++;		// Contabiliza comparação
				indice_menor = j;
			}
		}
	
		if(indice_menor != i){
			registro[0]++;			// Contabiliza comparação
			int aux = vetor[i];
			vetor[i] = vetor[indice_menor];
			vetor[indice_menor] = aux;
			registro[1]++;			// Cotabiliza troca
		}
		
	}

}