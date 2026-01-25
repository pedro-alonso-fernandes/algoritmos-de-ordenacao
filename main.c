#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "geranum.h"
#include "algoritmos.h"

int main(int argc, char** argv){

	srand(time(NULL));

	clock_t inicio, fim;
	double tempo;

	printf("\n");
	printf("--------------------------------------------------------\n");
	

	gerarNumeros(10000, CRESCENTE);

	inicio = clock();
	long long* registro = ordenarNumeros(HEAPSORT);
	fim = clock();

	tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

	printf("Qtd Comparações: %lld\n", registro[0]);
	printf("Qtd trocas: %lld\n", registro[1]);
	printf("Tempo de execução: %.6f segundos\n", tempo);

	printf("--------------------------------------------------------\n");
	printf("\n");

	free(registro);
	return 0;
}