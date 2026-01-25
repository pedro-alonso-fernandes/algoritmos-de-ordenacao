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
	SHELLSORT
}Algoritmo;

long long* ordenarNumeros(Algoritmo algoritmo);
void selectionSort(int* vetor, int qtdNums, long long* registro);
void heapify(int* vetor, int tamanho, int raiz, long long* registro);
void heapSort(int* vetor, int tamanho, long long* registro);

void bolha(int* vetor, int qtdNums, long long* registro);
void bolhaComParada(int* vetor, int qtdNums, long long* registro);
void insercaoDireta(int* vetor, int qtdNums, long long* registro);
void insercaoBinaria(int* vetor, int qtdNums, long long* registro);
void insercaoTernaria(int* vetor, int qtdNums, long long* registro);
void shellSort(int* vetor, int qtdNums, long long* registro);

#endif