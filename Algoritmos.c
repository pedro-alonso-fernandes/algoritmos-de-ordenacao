#include <stdio.h>
#include <stdlib.h>

typedef enum{
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
}Algoritmo;

void selectionSort(int* vetor, int tamanho, long long* registro);
void heapSort(int* vetor, int tamanho, long long* registro);
void quickSortFim(int* vetor, int inicio, int fim, long long* registro);
void quickSortCentroLomuto(int* vetor, int inicio, int fim, long long* registro);
void quickSortCentroHoare(int* vetor, int inicio, int fim, long long* registro);

void bolha(int* vetor, int tamanho, long long* registro);
void bolhaComParada(int* vetor, int tamanho, long long* registro);
void insercaoDireta(int* vetor, int tamanho, long long* registro);
void insercaoBinaria(int* vetor, int tamanho, long long* registro);
void insercaoTernaria(int* vetor, int tamanho, long long* registro);
void shellSort(int* vetor, int tamanho, long long* registro);

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
				case QUICKSORT_CENTRO_LOMUTO:
					quickSortCentroLomuto(vetor, 0, qtdLinhas - 1, registro);
					break;
				case QUICKSORT_CENTRO_HOARE:
					quickSortCentroHoare(vetor, 0, qtdLinhas - 1, registro);
					break;
				case QUICKSORT_FIM:
					quickSortFim(vetor, 0, qtdLinhas - 1, registro);
					break;
				case QUICKSORT_MEDIANA:
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
				case SHELLSORT:
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
			registro[0]++;		// Contabiliza comparação
			if(vetor[j] < vetor[indice_menor]){
				indice_menor = j;
			}
		}
	
		registro[0]++;			// Contabiliza comparação
		if(indice_menor != i){
			int aux = vetor[i];
			vetor[i] = vetor[indice_menor];
			vetor[indice_menor] = aux;
			registro[1]++;			// Cotabiliza troca
		}
		
	}

}

void heapify(int* vetor, int tamanho, int raiz, long long* registro){
	int maior = raiz;		// Supõe que a raiz é o maior número
	int esquerda = (2 * raiz) + 1;	// Conta para lidar um array como uma árvore binária. Isso pega o filho à esquerda
	int direita = (2 * raiz) + 2;		// Conta para lidar um array como uma árvore binária. Isso pega o filho à direita

	// Verifica se existe um filho à esquerda, e verifica se o filho da esquerda é maior do que a raiz
	registro[0]++;		// Contabiliza comparação
	if(esquerda < tamanho && vetor[esquerda] > vetor[maior]){
		maior = esquerda;
	}

	// Verifica se existe filho à direita, e verifica se o filho da direita é maior do que o maior número conhecido 
	// até agora (Seja a raiz, ou o filho da esquerda)
	registro[0]++;		// Contabiliza comparação
	if(direita < tamanho && vetor[direita] > vetor[maior]){
		maior = direita;
	}

	// Se o maior valor não for a raiz, troca de posição com a raiz e heapifica (deixar em max heap) a "nova subárvore"
	registro[0]++;		// Contabiliza comparação
	if(maior != raiz){
		int aux = vetor[raiz];
		vetor[raiz] = vetor[maior];
		vetor[maior] = aux;
		registro[1]++;		//Contabiliza troca

		// Heapifica a "nova subárvore" recursivamente
		heapify(vetor, tamanho, maior, registro);
	}

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

int particaoCentroLomuto(int* vetor, int inicio, int fim, long long* registro){
	int centro = inicio + (fim - inicio) / 2;
	int pivo = vetor[centro];
	int posicaoPivo = inicio;

	// Move o pivô para o último elemento do vetor
	int aux = vetor[fim];
	vetor[fim] = vetor[centro];
	vetor[centro] = aux;
	registro[1]++;		// Contabiliza troca

	for(int j = inicio; j < fim; j++){
		
		registro[0]++;		// Contabiliza comparação
		if(vetor[j] <= pivo){
			int aux = vetor[posicaoPivo];
			vetor[posicaoPivo] = vetor[j];
			vetor[j] = aux;
			registro[1]++;		// Contabiliza troca
			posicaoPivo++;
		}
	}
	aux = vetor[posicaoPivo];
	vetor[posicaoPivo] = vetor[fim];
	vetor[fim] = aux;
	registro[1]++;		// Contabiliza troca

	return posicaoPivo;
}

void quickSortCentroLomuto(int* vetor, int inicio, int fim, long long* registro){
	if(inicio < fim){
		int posicaoPivo = particaoCentroLomuto(vetor, inicio, fim, registro);	// Escolhe um pivô e deixa número menores à esquerda e maiores à direita
		quickSortCentroLomuto(vetor, inicio, posicaoPivo - 1, registro);	// Ordena o lado esquerdo do pivô
		quickSortCentroLomuto(vetor, posicaoPivo + 1, fim, registro);		// Ordena o lado direito do pivô
	}
}

int particaoCentroHoare(int* vetor, int inicio, int fim, long long* registro){
	// Escolhe o pivô no centro
    int pivo = vetor[inicio + (fim - inicio) / 2];
    int i = inicio - 1;
    int j = fim + 1;

    while (1) {
        // Move o ponteiro i para a direita enquanto o valor for menor que o pivô
        do {
            i++;
            registro[0]++; // Contabiliza comparação
        } while (vetor[i] < pivo);

        // Move o ponteiro j para a esquerda enquanto o valor for maior que o pivô
        do {
            j--;
            registro[0]++; // Contabiliza comparação
        } while (vetor[j] > pivo);

        // Se os ponteiros se cruzarem, a partição acabou
        if (i >= j) {
            return j;
        }

        // Se encontrou um valor maior à esquerda e um menor à direita, troca-os
        int aux = vetor[j];
		  vetor[j] = vetor[i];
		  vetor[i] = aux;
		  registro[1]++;		// Contabiliza troca
    }
}

void quickSortCentroHoare(int* vetor, int inicio, int fim, long long* registro){
	if(inicio < fim){
		int p = particaoCentroHoare(vetor, inicio, fim, registro);		// Escolhe um pivô e deixa número menores ou iguais à esquerda e maiores à direita
		// Até o indice p, os números do vetor são menores ou iguais ao pivô. Depois dele, os números são maiores que o pivô
		quickSortCentroHoare(vetor, inicio, p, registro);		// Ordena os número menores ou iguais ao pivô
		quickSortCentroHoare(vetor, p + 1, fim, registro);	// Ordena os número maiores que o pivô
	}

}

int particaoFim(int* vetor, int inicio, int fim, long long* registro){
	int pivo = vetor[fim];
	int posicaoPivo = inicio;
	for(int j = inicio; j < fim; j++){
		
		registro[0]++;		// Contabiliza comparação
		if(vetor[j] <= pivo){
			int aux = vetor[posicaoPivo];
			vetor[posicaoPivo] = vetor[j];
			vetor[j] = aux;
			registro[1]++;		// Contabiliza troca
			posicaoPivo++;
		}
	}
	int aux = vetor[posicaoPivo];
	vetor[posicaoPivo] = vetor[fim];
	vetor[fim] = aux;
	registro[1]++;		// Contabiliza troca

	return posicaoPivo;
}

void quickSortFim(int* vetor, int inicio, int fim, long long* registro){
	if(inicio < fim){
		int posicaoPivo = particaoFim(vetor, inicio, fim, registro);	// Escolhe um pivô e deixa número menores à esquerda e maiores à direita
		quickSortFim(vetor, inicio, posicaoPivo - 1, registro);	// Ordena o lado esquerdo do pivô
		quickSortFim(vetor, posicaoPivo + 1, fim, registro);		// Ordena o lado direito do pivô
	}
}

void bolha(int* vetor, int tamanho, long long* registro){

    int aux;
	 
    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = tamanho - 1; i >= 1; i--){
        for(int j = 0; j < i; j++){
			  
			  registro[0]++; // Contabiliza compração
			  if (vetor[j] > vetor[j + 1]) {
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro[1]++; // Contabiliza troca
            }

        }
    }
}

void bolhaComParada(int* vetor, int tamanho, long long* registro){

    int aux;
    int trocou;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = tamanho - 1; i >= 1; i--){
        trocou = 0;

        for(int j = 0; j < i; j++){

			  registro[0]++; // Contabiliza comparação
			  if(vetor[j] > vetor[j + 1]){
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro[1]++; // Contabiliza troca
				  trocou = 1;    // Marcou que houve troca
            }
				
        }

        // Critério de parada
        if(trocou == 0){
            break;
        }
    }
}

void insercaoDireta(int* vetor, int tamanho, long long* registro){

    int aux;
    int j;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = 1; i < tamanho; i++){

        aux = vetor[i];
        j = i - 1;

        while(j >= 0){
			  
			  registro[0]++; // Contabiliza comparação
			  if(aux < vetor[j]){
				  vetor[j + 1] = vetor[j];
				  registro[1]++; // Contabiliza troca
				  j--;
            } else {
					break;
            }
				
        }

        if(j != i - 1){
            vetor[j + 1] = aux; // Essa troca já foi contabilizada dentro do if do while acima
        }
    }
}

void insercaoBinaria(int* vetor, int tamanho, long long* registro){

    int aux;
    int esq, dir, meio;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas 

    for(int i = 1; i < tamanho; i++){

        aux = vetor[i];
        esq = 0;
        dir = i;

        // Busca binária da posição correta
        while(esq < dir){
            meio = (esq + dir) / 2;
				
				registro[0]++; // Contabiliza comparação
            if(vetor[meio] <= aux){
					esq = meio + 1;
            } else {
					dir = meio;
            }
				
        }

        // Deslocando elementos
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j - 1];
            registro[1]++; // Contabiliza troca
        }

        vetor[esq] = aux; // Essa troca já foi contabilizada no for acima
		  
    }
}

void insercaoTernaria(int* vetor, int tamanho, long long* registro){

    int aux;
    int esq, dir;
    int div1, div2;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas

    for(int i = 1; i < tamanho; i++){

        aux = vetor[i];
        esq = 0;
        dir = i;

        // Busca ternária da posição correta
        while(esq < dir){

            div1 = esq + (dir - esq) / 3;
            div2 = esq + 2 * (dir - esq) / 3;

				registro[0]++; // Contabiliza comparação
            if(aux < vetor[div1]){
					dir = div1;
            }
            else{

					registro[0]++; // Contabiliza comparação
					if(aux > vetor[div2]){
						esq = div2 + 1;
					}
					else{
						esq = div1 + 1;
						dir = div2;
					}
					
            }
				
        }

        // Deslocando elementos
        for(int j = i; j > esq; j--){
            vetor[j] = vetor[j - 1];
            registro[1]++; // Contabiliza troca
        }

        vetor[esq] = aux; // Essa troca já foi contabilizada no for acima
    }
}

void shellSort(int* vetor, int tamanho, long long* registro){

    int gap = 1; // Intervalo 
    int aux;
    int j;

    registro[0] = 0; // Comparações
    registro[1] = 0; // Trocas

    // Geração do intervalo
    while(gap < tamanho){
        gap = 3 * gap + 1;
    }

    while(gap > 1){
        gap = gap / 3;

        for(int i = gap; i < tamanho; i++){
            aux = vetor[i];
            j = i - gap;

            while(j >= 0){
					
					registro[0]++; // Contabiliza comparação
					if(aux < vetor[j]){
						vetor[j + gap] = vetor[j];
						registro[1]++; // Contabiliza troca
						j = j - gap;
					} else {
						break;
					}
					
            }

            vetor[j + gap] = aux; // Essa troca já foi contabilizada dentro do if do while acima
			
        }
    }
}

