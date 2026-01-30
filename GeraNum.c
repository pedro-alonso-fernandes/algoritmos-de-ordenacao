#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef enum{
	ALEATORIO,
	CRESCENTE,
	DECRESCENTE
}MetodoGeracao;

char* getStringMetodoGeracao(MetodoGeracao metodo){
	int tam_string = 12;
	char* string = (char*) malloc(tam_string * sizeof(char));
	
	if(string != NULL){
		switch (metodo){
		case ALEATORIO:
			snprintf(string, tam_string, "aleatorio");
			break;
		case CRESCENTE:
			snprintf(string, tam_string, "crescente");
			break;
		case DECRESCENTE:
			snprintf(string, tam_string, "decrescente");
			break;
		}
	}
	else
		printf("Erro ao alocar memória para retornar Método de Geração!\n");

	return string;
}

void gerarNumeros(int qtd, MetodoGeracao metodo){

	char* metodoGeracao = getStringMetodoGeracao(metodo);

	char nomeArquivo[42];
	snprintf(nomeArquivo, sizeof(nomeArquivo), "resultados/%s/entrada.txt", metodoGeracao);
	FILE *arq = fopen(nomeArquivo, "w");

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