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
	BUCKETSORT
}Algoritmo;

int* ordenarNumeros(Algoritmo algoritmo);
void selectionSort(int* vetor, int qtdNums, int* registro);

#endif