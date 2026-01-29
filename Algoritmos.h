#ifndef ALGORITMOS_H
#define ALGORITMOS_H

typedef struct{
	long long comparacoes;
	long long trocas;
	double tempo;
}Registro;

void bolha(int* vetor, int qtdNums, Registro* registro);
void bolhaComParada(int* vetor, int qtdNums, Registro* registro);
void insercaoDireta(int* vetor, int qtdNums, Registro* registro);
void insercaoBinaria(int* vetor, int qtdNums, Registro* registro);
void insercaoTernaria(int* vetor, int qtdNums, Registro* registro);
void shellSort(int* vetor, int qtdNums, Registro* registro);
void selectionSort(int* vetor, int qtdNums, Registro* registro);
void heapify(int* vetor, int tamanho, int raiz, Registro* registro);
void heapSort(int* vetor, int tamanho, Registro* registro);
void quickSortFim(int* vetor, int inicio, int fim, Registro* registro);
void quickSortCentroLomuto(int* vetor, int inicio, int fim, Registro* registro);
void quickSortCentroHoare(int* vetor, int inicio, int fim, Registro* registro);
void quickSortMediana(int* vetor, int inicio, int fim, Registro* registro);
void mergeSort(int* vetor, int inicio, int tamanho, Registro* registro);
void radixSort(int* vetor, int tamanho, Registro* registro);
void bucketSort(int* vetor, int tamanho, Registro* registro);


#endif