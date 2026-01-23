#include <stdio.h>
#include <stdlib.h>
#include "geranum.h"
#include "algoritmos.h"

int main(int argc, char** argv){

	printf("\n");
	printf("--------------------------------------------------------\n");
	
	gerarNumeros(100000, ALEATORIO);
	int* registro = ordenarNumeros(BOLHA);

	printf("Qtd Comparações: %d\n", registro[0]);
	printf("Qtd trocas: %d\n", registro[1]);

	printf("--------------------------------------------------------\n");
	printf("\n");

	return 0;
}