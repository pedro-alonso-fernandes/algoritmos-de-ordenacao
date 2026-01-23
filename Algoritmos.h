#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef enum{
	SELECTION_SORT,
	HEAPSORT,
	QUICKSORT_CENTRO,
	QUICKSORT_FIM,
	QUICKSORT_MEIDANA,
	MERGESORT,
	RADIXSORT,
	BUCKETSORT,
	BOLHA,
	BOLHA_COM_PARADA,
	INSERCAO_DIRETA,
	INSERCAO_BINARIA,
	INSERCAO_TERNARIA,
	SHELL_SORT
}Algoritmo;

int* ordenarNumeros(Algoritmo algoritmo);
void selectionSort(int* vetor, int qtdNums, int* registro);
void heapify(int* vetor, int tamanho, int raiz, int* registro);
void heapSort(int* vetor, int tamanho, int* registro);

void bolha(int* vetor, int qtdNums, int* registro);
void bolhaComParada(int* vetor, int qtdNums, int* registro);
void insercaoDireta(int* vetor, int qtdNums, int* registro);
void insercaoBinaria(int* vetor, int qtdNums, int* registro);
void insercaoTernaria(int* vetor, int qtdNums, int* registro);
void shellSort(int* vetor, int qtdNums, int* registro);

#endif