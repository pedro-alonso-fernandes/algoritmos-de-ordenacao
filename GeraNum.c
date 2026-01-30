#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef enum{
	ALEATORIO,
	CRESCENTE,
	DECRESCENTE
}MetodoGeracao;

void gerarNumeros(int qtd, MetodoGeracao metodo){

	// Caso não exista, cria pasta que ficarão os arquivos de resultado do código
	if(!EXISTE_PASTA("resultados")){
		CRIAR_PASTA("resultados");
	}

	FILE *arq = fopen("resultados/entrada.txt", "w");

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