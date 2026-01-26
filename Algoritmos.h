#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef enum{
	BOLHA,
	BOLHA_COM_PARADA,
	INSERCAO_DIRETA,
	INSERCAO_BINARIA,
	INSERCAO_TERNARIA,
   SHELL_SORT,
	SELECTION_SORT,
	HEAPSORT,
	QUICKSORT_CENTRO_LOMUTO,
	QUICKSORT_CENTRO_HOARE,
	QUICKSORT_FIM,
	QUICKSORT_MEIDANA,
	MERGESORT,
	RADIXSORT,
	BUCKETSORT
}Algoritmo;

int* ordenarNumeros(Algoritmo algoritmo);
void selectionSort(int* vetor, int qtdNums, int* registro);
void heapify(int* vetor, int tamanho, int raiz, int* registro);
void heapSort(int* vetor, int tamanho, int* registro);
void quickSortFim(int* vetor, int inicio, int fim, int* registro);
void quickSortCentroLomuto(int* vetor, int inicio, int fim, int* registro);
void quickSortCentroHoare(int* vetor, int inicio, int fim, int* registro);

void bolha(int* vetor, int qtdNums, int* registro);
void bolhaComParada(int* vetor, int qtdNums, int* registro);
void insercaoDireta(int* vetor, int qtdNums, int* registro);
void insercaoBinaria(int* vetor, int qtdNums, int* registro);
void insercaoTernaria(int* vetor, int qtdNums, int* registro);
void shellSort(int* vetor, int qtdNums, int* registro);

#endif