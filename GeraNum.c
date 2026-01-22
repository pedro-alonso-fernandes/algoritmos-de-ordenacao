#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum{
	ALEATORIO,
	CRESCENTE,
	DECRESCENTE
}MetodoGeracao;

void gerarNumeros(int qtd, MetodoGeracao metodo){
	FILE *arq = fopen("entrada.txt", "w");

	if(arq != NULL){
		
		switch(metodo){
			case ALEATORIO:
				srand(time(NULL));
				for(int i = 0; i < qtd; i++){
					int numAleatorio = rand();
					fprintf(arq, "%d\n", numAleatorio);
				}
				break;

			case CRESCENTE:
				for(int i = 1; i <= qtd; i++)
					fprintf(arq, "%d\n", i);
				break;

			case DECRESCENTE:
				for(int i = qtd; i >= 1; i--)
					fprintf(arq, "%d\n", i);
				break;
		}
		
	}
	else
		printf("Erro ao criar e abrir o arquivo \"entrada.txt\"!\n");

	fclose(arq);
}