#include <stdio.h>
#include <stdlib.h>
#include "geranum.h"
#include "algoritmos.h"

int main(int argc, char** argv){

	printf("\n");
	printf("--------------------------------------------------------\n");
	

	gerarNumeros(100, ALEATORIO);
	double tempo = 0;
	long long* registro = ordenarNumeros(MERGESORT, &tempo);

	printf("Qtd Comparações: %lld\n", registro[0]);
	printf("Qtd trocas: %lld\n", registro[1]);
	printf("Tempo de execução: %f segundos\n", tempo);

	printf("--------------------------------------------------------\n");
	printf("\n");

	free(registro);
	return 0;
}