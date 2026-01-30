#include <stdio.h>
#include <stdlib.h>
#include "geranum.h"
#include "sort.h"

int main(int argc, char** argv){

	printf("\n");
	printf("--------------------------------------------------------\n");
	

	gerarNumeros(100, ALEATORIO);
	Registro* registro = ordenarNumeros(BUCKETSORT);

	printf("Qtd Comparações: %lld\n", registro->comparacoes);
	printf("Qtd trocas: %lld\n", registro->trocas);
	printf("Tempo de execução: %f segundos\n", registro->tempo);

	printf("--------------------------------------------------------\n");
	printf("\n");

	free(registro);
	return 0;
}