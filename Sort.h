#ifndef SORT_H
#define SORT_H

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

Registro* ordenarNumeros(Algoritmo algoritmo, char* metodoGeracao);

#endif