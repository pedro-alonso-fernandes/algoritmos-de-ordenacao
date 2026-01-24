#include <stdio.h>
#include <stdlib.h>

typedef enum{
	SELECTION_SORT,
	HEAPSORT,
	QUICKSORT_CENTRO,
	QUICKSORT_FIM,
	QUICKSORT_MEIDANA,
	MERGESORT,
	RADIXSORT,
	BUCKETSORT,
	BOLHA,
	BOLHA_COM_PARADA,
	INSERCAO_DIRETA,
	INSERCAO_BINARIA,
	INSERCAO_TERNARIA,
   SHELL_SORT
}Algoritmo;

void selectionSort(int* vetor, int tamanho, long long* registro);
void heapSort(int* vetor, int tamanho, long long* registro);

void bolha(int* vetor, int qtdNums, long long* registro);
void bolhaComParada(int* vetor, int qtdNums, long long* registro);
void insercaoDireta(int* vetor, int qtdNums, long long* registro);
void insercaoBinaria(int* vetor, int qtdNums, long long* registro);
void insercaoTernaria(int* vetor, int qtdNums, long long* registro);
void shellSort(int* vetor, int qtdNums, long long* registro);

// Abre o arquivo "entrada.txt", carrega os valores para um vetor, e manda para algum algoritmo de ordenação
long long* ordenarNumeros(Algoritmo algoritmo){
	// Utilizarei o vetor registro para registrar a quantidade de comparações e trocas dentro dos algoritmos
	long long* registro = (long long*) malloc(2 * sizeof(long long));
	registro[0] = 0;	// A posição 0 do vetor salva as comparações
	registro[1] = 0;	// A posição 1 do vetor salva as trocas
	
	FILE *arq_entrada = fopen("entrada.txt", "r");

	if(arq_entrada != NULL){
		int qtdLinhas = 0;
		int temp;
		while(fscanf(arq_entrada, "%d\n", &temp) == 1)
			qtdLinhas++;

		int* vetor = (int*) malloc(qtdLinhas * sizeof(int));

		if(vetor != NULL){
			rewind(arq_entrada);

			for(int i = 0; i < qtdLinhas; i++)
				fscanf(arq_entrada, "%d\n", &vetor[i]);

			switch (algoritmo){
				case SELECTION_SORT:
					selectionSort(vetor, qtdLinhas, registro);
					break;
				case HEAPSORT:
					heapSort(vetor, qtdLinhas, registro);
					break;
				case QUICKSORT_CENTRO:
					// Chama a função
					break;
				case QUICKSORT_FIM:
					// Chama a função
					break;
				case QUICKSORT_MEIDANA:
					// Chama a função
					break;
				case MERGESORT:
					// Chama a função
					break;
				case RADIXSORT:
					// Chama a função
					break;
				case BUCKETSORT:
					// Chama a função
					break;
				case BOLHA:
					bolha(vetor, qtdLinhas, registro);
					break;
				case BOLHA_COM_PARADA:
					bolhaComParada(vetor, qtdLinhas, registro);
					break;
				case INSERCAO_DIRETA:
					insercaoDireta(vetor, qtdLinhas, registro);
					break;
				case INSERCAO_BINARIA:
					insercaoBinaria(vetor, qtdLinhas, registro);
					break;
				case INSERCAO_TERNARIA:
					insercaoTernaria(vetor, qtdLinhas, registro);
					break;
            case SHELL_SORT:
               shellSort(vetor, qtdLinhas, registro);
               break;
			}

			// Cria o arquivo que conterá os elementos ordenados
			FILE *arq_saida = fopen("saida.txt", "w");

			if(arq_saida != NULL){
				for(int i = 0; i < qtdLinhas; i++){
					fprintf(arq_saida, "%d\n", vetor[i]);
				}
			}
			else
				printf("Erro ao criar e abrir o arquivo \"saida.txt\"!\n");

			fclose(arq_saida);
			free(vetor);
		}
		else
			printf("Erro ao alocar memória!\n");
	}
	else
		printf("Erro ao abrir o arquivo \"entrada.txt\"!\n");

	fclose(arq_entrada);

	return registro;
}

void selectionSort(int* vetor, int tamanho, long long* registro){
	
    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

	for(int i = 0; i < (tamanho - 1); i++){
		int indice_menor = i;
		
		for(int j = i + 1; j < tamanho; j++){
			if(vetor[j] < vetor[indice_menor]){
				indice_menor = j;
			}
			registro[0]++;		// Contabiliza comparação
		}
	
		if(indice_menor != i){
			int aux = vetor[i];
			vetor[i] = vetor[indice_menor];
			vetor[indice_menor] = aux;
			registro[1]++;			// Cotabiliza troca
		}
		registro[0]++;			// Contabiliza comparação
		
	}

}

void heapify(int* vetor, int tamanho, int raiz, long long* registro){
	int maior = raiz;		// Supõe que a raiz é o maior número
	int esquerda = (2 * raiz) + 1;	// Conta para lidar um array como uma árvore binária. Isso pega o filho à esquerda
	int direita = (2 * raiz) + 2;		// Conta para lidar um array como uma árvore binária. Isso pega o filho à direita

	// Verifica se existe um filho à esquerda, e verifica se o filho da esquerda é maior do que a raiz
	if(esquerda < tamanho && vetor[esquerda] > vetor[maior]){
		maior = esquerda;
	}
	registro[0]++;		// Contabiliza comparação

	// Verifica se existe filho à direita, e verifica se o filho da direita é maior do que o maior número conhecido 
	// até agora (Seja a raiz, ou o filho da esquerda)
	if(direita < tamanho && vetor[direita] > vetor[maior]){
		maior = direita;
	}
	registro[0]++;		// Contabiliza comparação

	// Se o maior valor não for a raiz, troca de posição com a raiz e heapifica (deixar em max heap) a "nova subárvore"
	if(maior != raiz){
		int aux = vetor[raiz];
		vetor[raiz] = vetor[maior];
		vetor[maior] = aux;
		registro[1]++;		//Contabiliza troca

		// Heapifica a "nova subárvore" recursivamente
		heapify(vetor, tamanho, maior, registro);
	}

	registro[0]++;		// Contabiliza comparação
}

void heapSort(int* vetor, int tamanho, long long* registro){
	// Deixa toda a árvore em max heap, chamando o heapify em todo ramo que possui filho
	for(int i = (tamanho / 2) - 1; i >= 0; i--)
		heapify(vetor, tamanho, i, registro);

	// Pega o maior elemento da árvore (raiz), coloca por último no vetor e subtrai 1 do tamanho da árvore.
	// Assim sucessivamente até o vetor estar ordenado
	for(int i = tamanho - 1; i >= 0; i--){
		int aux = vetor[i];
		vetor[i] = vetor[0];
		vetor[0] = aux;
		registro[1]++;		// Contabiliza troca

		// Deixa a nova árvore em max heap
		heapify(vetor, i, 0, registro);
	}
}

void bolha(int* vetor, int qtdNums, long long* registro){

    int aux;
	 
    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = qtdNums - 1; i >= 1; i--){
        for(int j = 0; j < i; j++){
			  
			  if (vetor[j] > vetor[j + 1]) {
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro[1]++; // Contabiliza troca
            }

				registro[0]++; // Contabiliza compração
        }
    }
}

void bolhaComParada(int* vetor, int qtdNums, long long* registro){

    int aux;
    int trocou;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = qtdNums - 1; i >= 1; i--){
        trocou = 0;

        for(int j = 0; j < i; j++){

			  if(vetor[j] > vetor[j + 1]){
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro[1]++; // Contabiliza troca
				  trocou = 1;    // Marcou que houve troca
            }
				
				registro[0]++; // Contabiliza comparação
        }

        // Critério de parada
        if(trocou == 0){
            break;
        }
    }
}

void insercaoDireta(int* vetor, int qtdNums, long long* registro){

    int aux;
    int j;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = 1; i < qtdNums; i++){

        aux = vetor[i];
        j = i - 1;

        while(j >= 0){
			  
			  if(aux < vetor[j]){
				  vetor[j + 1] = vetor[j];
				  registro[1]++; // Contabiliza troca
				  j--;
            } else {
					registro[0]++; // Contabiliza comparação, pois vai sair do while e não vai chegar no "registro[0]++" abaixo
					break;
            }
				
				registro[0]++; // Contabiliza comparação
        }

        if(j != i - 1){
            vetor[j + 1] = aux;

				/*
				Não precisa do código abaixo, essa troca já foi contabilizada dentro do while 
            registro[1]++; // Contabiliza troca (insere o "aux" no seu devido lugar) - inserção final
				*/
        }
    }
}

void insercaoBinaria(int* vetor, int qtdNums, long long* registro){

    int aux;
    int esq, dir, meio;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = 1; i < qtdNums; i++){

        aux = vetor[i];
        esq = 0;
        dir = i;

        // Busca binária da posição correta
        while(esq < dir){
            meio = (esq + dir) / 2;
				
            if(vetor[meio] <= aux){
					esq = meio + 1;
            } else {
					dir = meio;
            }
				
				registro[0]++; // Contabiliza comparação
        }

        // Deslocando elementos
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j - 1];
            registro[1]++; // Contabiliza troca
        }

        vetor[esq] = aux;
		  /*
		  Essa troca já foi contabilizada no for acima
        registro[1]++; // Contabiliza troca - inserção final
		  */
    }
}

void insercaoTernaria(int* vetor, int qtdNums, long long* registro){

    int aux;
    int esq, dir;
    int div1, div2;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas

    for(int i = 1; i < qtdNums; i++){

        aux = vetor[i];
        esq = 0;
        dir = i;

        // Busca ternária da posição correta
        while(esq < dir){

            div1 = esq + (dir - esq) / 3;
            div2 = esq + 2 * (dir - esq) / 3;

            if(aux < vetor[div1]){
					dir = div1;
            }
            else{
					if(aux > vetor[div2]){
						esq = div2 + 1;
					}
					else{
						esq = div1 + 1;
						dir = div2;
					}
					
					registro[0]++; // Contabiliza comparação
            }
				
				registro[0]++; // Contabiliza comparação
        }

        // Deslocando elementos
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j - 1];
            registro[1]++; // Contabiliza troca
        }

        vetor[esq] = aux;
		  /*
		  Essa troca já foi contabilizada no for acima
        registro[1]++; // Contabiliza troca - inserção final
		  */
    }
}

void shellSort(int* vetor, int qtdNums, long long* registro){

    int h = 1; // Intervalo
    int aux;
    int j;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas

    // Geração do intervalo
    while(h < qtdNums){
        h = 3 * h + 1;
    }

    while(h > 1){
        h = h / 3;

        for(int i = h; i < qtdNums; i++){
            aux = vetor[i];
            j = i - h;

            while(j >= 0){
					
					if(aux < vetor[j]){
						vetor[j + h] = vetor[j];
						registro[1]++; // Contabiliza troca
						j = j - h;
					} else {
						registro[0]++; // Contabiliza comparação, pois vai sair do while e não vai chegar no "registro[0]++" abaixo
						break;
					}
					
					registro[0]++; // Contabiliza comparação
            }

            vetor[j + h] = aux;
				/*
				Essa troca já foi contabilizada dentro do if do while acima
            registro[1]++; // Contabiliza troca - inserção final
				*/
        }
    }
}

