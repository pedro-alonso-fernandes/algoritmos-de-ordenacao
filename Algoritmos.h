#ifndef ALGORITMOS_H
#define ALGORITMOS_H

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

long long* ordenarNumeros(Algoritmo algoritmo);
void selectionSort(int* vetor, int qtdNums, long long* registro);
void heapify(int* vetor, int tamanho, int raiz, long long* registro);
void heapSort(int* vetor, int tamanho, long long* registro);
void quickSortFim(int* vetor, int inicio, int fim, long long* registro);
void quickSortCentroLomuto(int* vetor, int inicio, int fim, long long* registro);
void quickSortCentroHoare(int* vetor, int inicio, int fim, long long* registro);

void bolha(int* vetor, int qtdNums, long long* registro);
void bolhaComParada(int* vetor, int qtdNums, long long* registro);
void insercaoDireta(int* vetor, int qtdNums, long long* registro);
void insercaoBinaria(int* vetor, int qtdNums, long long* registro);
void insercaoTernaria(int* vetor, int qtdNums, long long* registro);
void shellSort(int* vetor, int qtdNums, long long* registro);

#endif