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

void selectionSort(int* vetor, int tamanho, int* registro);
void heapSort(int* vetor, int tamanho, int* registro);

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
					heapSort(vetor, qtdLinhas, registro);
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

void selectionSort(int* vetor, int tamanho, int* registro){
	for(int i = 0; i < (tamanho - 1); i++){
		int indice_menor = i;
		
		for(int j = i + 1; j < tamanho; j++){
			if(vetor[j] < vetor[indice_menor]){
				indice_menor = j;
			}
			registro[0]++;		// Contabiliza comparação
		}
	
		if(indice_menor != i){
			int aux = vetor[i];
			vetor[i] = vetor[indice_menor];
			vetor[indice_menor] = aux;
			registro[1]++;			// Cotabiliza troca
		}
		registro[0]++;			// Contabiliza comparação
		
	}

}

void heapify(int* vetor, int tamanho, int raiz, int* registro){
	int maior = raiz;		// Supõe que a raiz é o maior número
	int esquerda = (2 * raiz) + 1;	// Conta para lidar um array como uma árvore binária. Isso pega o filho à esquerda
	int direita = (2 * raiz) + 2;		// Conta para lidar um array como uma árvore binária. Isso pega o filho à direita

	// Verifica se existe um filho à esquerda, e verifica se o filho da esquerda é maior do que a raiz
	if(esquerda < tamanho && vetor[esquerda] > vetor[maior]){
		maior = esquerda;
	}
	registro[0]++;		// Contabiliza comparação

	// Verifica se existe filho à direita, e verifica se o filho da direita é maior do que o maior número conhecido 
	// até agora (Seja a raiz, ou o filho da esquerda)
	if(direita < tamanho && vetor[direita] > vetor[maior]){
		maior = direita;
	}
	registro[0]++;		// Contabiliza comparação

	// Se o maior valor não for a raiz, troca de posição com a raiz e heapifica (deixar em max heap) a "nova subárvore"
	if(maior != raiz){
		int aux = vetor[raiz];
		vetor[raiz] = vetor[maior];
		vetor[maior] = aux;
		registro[1]++;		//Contabiliza troca

		// Heapifica a "nova subárvore" recursivamente
		heapify(vetor, tamanho, maior, registro);
	}

	registro[0]++;		// Contabiliza comparação
}

void heapSort(int* vetor, int tamanho, int* registro){
	// Deixa toda a árvore em max heap, chamando o heapify em todo ramo que possui filho
	for(int i = (tamanho / 2) - 1; i >= 0; i--)
		heapify(vetor, tamanho, i, registro);

	// Pega o maior elemento da árvore (raiz), coloca por último no vetor e subtrai 1 do tamanho da árvore.
	// Assim sucessivamente até o vetor estar ordenado
	for(int i = tamanho - 1; i >= 0; i--){
		int aux = vetor[i];
		vetor[i] = vetor[0];
		vetor[0] = aux;
		registro[1]++;		// Contabiliza troca

		// Deixa a nova árvore em max heap
		heapify(vetor, i, 0, registro);
	}
}