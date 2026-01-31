#include <stdio.h>
#include <stdlib.h>
#include "geranum.h"
#include "sort.h"

// Importa as bibliotecas necessárias de acordo com o Sistema Operacional
#ifdef _WIN32
	#include <io.h>		// Importa o _access
	#include <direct.h>	// Importa o _mkdir
	#define EXISTE_PASTA(caminho) (_access(caminho, 0) == 0)
	#define CRIAR_PASTA(nome) _mkdir(nome)
#else
	#include <unistd.h>		//	Importa o access
	#include <sys/stat.h>	// Importa o mkdir
	#include <sys/types.h>	// Importei por garantia
	#define EXISTE_PASTA(caminho) (access(caminho, F_OK) == 0)
	#define CRIAR_PASTA(nome) mkdir(nome, 0755)	// 0755 é a permisão da pasta: Dono pode tudo e o resto pode ler e abrir

#endif

int main(int argc, char** argv){

	// Caso não exista, cria pasta que ficarão os arquivos de resultado do código
	if(!EXISTE_PASTA("resultados")){
		CRIAR_PASTA("resultados");
		CRIAR_PASTA("resultados/aleatorio");
		CRIAR_PASTA("resultados/crescente");
		CRIAR_PASTA("resultados/decrescente");
	}
	else {
		if(!EXISTE_PASTA("resultados/aleatorio")){
			CRIAR_PASTA("resultados/aleatorio");
		}
		if(!EXISTE_PASTA("resultados/crescente")){
			CRIAR_PASTA("resultados/crescente");
		}
		if(!EXISTE_PASTA("resultados/decrescente")){
			CRIAR_PASTA("resultados/decrescente");
		}
	}

	
	printf("\n");
	printf("--------------------------------------------------------\n\n");

	Algoritmo algoritmos[15] = {
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
	};

	int escolha = -1;
	while(escolha != 0){
		printf("Escolha um método de geração de números:\n");
		printf("1 - Aleatório\n");
		printf("2 - Crescente\n");
		printf("3 - Decrescente\n");
		printf("0 - Encerrar programa\n");
		printf("\n");
		printf("Digite: ");
		scanf("%d", &escolha);
		printf("\n");
		
		if(escolha == 0)
			continue;
		else if(escolha != 1 && escolha != 2 && escolha != 3){
			printf("--------------------------------------------------------\n");
			printf("Opção inválida! Escolha uma opção válida\n");
			printf("--------------------------------------------------------\n\n");
			continue;
		}

	
	
		printf("--------------------------------------------------------\n\n");

		MetodoGeracao metodo;
		switch(escolha){
			case 1:
				metodo = ALEATORIO;
				break;
			case 2:
				metodo = CRESCENTE;
				break;
			case 3:
				metodo = DECRESCENTE;
				break;
		}
		
		int qtdNums = 10000;	// 10 mil
		char* string_metodo = getStringMetodoGeracao(metodo);
		char nomeArquivo[42];
		snprintf(nomeArquivo, sizeof(nomeArquivo), "resultados/%s/%s.csv", string_metodo, string_metodo);
		FILE* arquivo = fopen(nomeArquivo, "w");
		fprintf(arquivo, "Algoritmo,Tamanho,Comparacoes,Trocas,Tempo_(s)\n");

		// For para utilizar 10 mil, 100 mil e 500 mil como qtdNums
		for(int j = 0; j < 3; j++){
			if(j == 1){
				qtdNums *= 10;
				fprintf(arquivo, "\n");
			}
			else if(j == 2){
				fprintf(arquivo, "\n");
				qtdNums *= 5;
			}	
			
			printf("%s - %d mil:\n\n", string_metodo, qtdNums / 1000);

			gerarNumeros(qtdNums, metodo);
			// For para utilizar todos os algoritmos
			for(int k = 0; k < 15; k++){
				Registro* registro = ordenarNumeros(algoritmos[k], string_metodo);
				printf("Algoritmo: %s\n", registro->nome_algoritmo);
				printf("Qtd Comparações: %lld\n", registro->comparacoes);
				printf("Qtd trocas: %lld\n", registro->trocas);
				printf("Tempo de execução: %f segundos\n", registro->tempo);
				printf("\n");
				
				fprintf(arquivo, "%s,%d,%lld,%lld,%f\n", registro->nome_algoritmo, qtdNums, registro->comparacoes, 
				registro->trocas, registro->tempo);
				free(registro);
			}
			printf("\n");

		}

		fclose(arquivo);
		free(string_metodo);
	}
	printf("--------------------------------------------------------\n");

	printf("\n");

	return 0;
}