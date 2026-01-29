#include <stdio.h>
#include <stdlib.h>

typedef struct{
	long long comparacoes;
	long long trocas;
	double tempo;
}Registro;

void bolha(int* vetor, int tamanho, Registro* registro){

	 int aux;

	 for(int i = tamanho - 1; i >= 1; i--){
		  for(int j = 0; j < i; j++){
			  
			  registro->comparacoes++; // Contabiliza compração
			  if (vetor[j] > vetor[j + 1]) {
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro->trocas++; // Contabiliza troca
				}

		  }
	 }
}

void bolhaComParada(int* vetor, int tamanho, Registro* registro){

	 int aux;
	 int trocou;

	 for(int i = tamanho - 1; i >= 1; i--){
		  trocou = 0;

		  for(int j = 0; j < i; j++){

			  registro->comparacoes++; // Contabiliza comparação
			  if(vetor[j] > vetor[j + 1]){
				  aux = vetor[j];
				  vetor[j] = vetor[j + 1];
				  vetor[j + 1] = aux;
				  registro->trocas++; // Contabiliza troca
				  trocou = 1;    // Marcou que houve troca
				}
				
		  }

		  // Critério de parada
		  if(trocou == 0){
				break;
		  }
	 }
}

void insercaoDireta(int* vetor, int tamanho, Registro* registro){

	int aux;
	int j;

	for(int i = 1; i < tamanho; i++){

		aux = vetor[i];
		j = i - 1;

		while(j >= 0){
				
				registro->comparacoes++; // Contabiliza comparação
				if(aux < vetor[j]){
					vetor[j + 1] = vetor[j];
					registro->trocas++; // Contabiliza troca
					j--;
				} else {
					break;
				}
				
		}

		vetor[j + 1] = aux; // Essa troca já foi contabilizada dentro do if do while acima
	}
}

void insercaoBinaria(int* vetor, int tamanho, Registro* registro){

	 int aux;
	 int esq, dir, meio;

	 for(int i = 1; i < tamanho; i++){

		  aux = vetor[i];
		  esq = 0;
		  dir = i;

		  // Busca binária da posição correta
		  while(esq < dir){
				meio = (esq + dir) / 2;
				
				registro->comparacoes++; // Contabiliza comparação
				if(vetor[meio] <= aux){
					esq = meio + 1;
				} else {
					dir = meio;
				}
				
		  }

		  // Deslocando elementos
		  for(int j = i; j > esq; j--){
				vetor[j] = vetor[j - 1];
				registro->trocas++; // Contabiliza troca
		  }

		  vetor[esq] = aux; // Essa troca já foi contabilizada no for acima
		  
	 }
}

void insercaoTernaria(int* vetor, int tamanho, Registro* registro){

	 int aux;
	 int esq, dir;
	 int div1, div2;

	 for(int i = 1; i < tamanho; i++){

		  aux = vetor[i];
		  esq = 0;
		  dir = i;

		  // Busca ternária da posição correta
		  while(esq < dir){

				div1 = esq + (dir - esq) / 3;
				div2 = esq + 2 * (dir - esq) / 3;

				registro->comparacoes++; // Contabiliza comparação
				if(aux < vetor[div1]){
					dir = div1;
				}
				else{

					registro->comparacoes++; // Contabiliza comparação
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
				registro->trocas++; // Contabiliza troca
		  }

		  vetor[esq] = aux; // Essa troca já foi contabilizada no for acima
	 }
}

void shellSort(int* vetor, int tamanho, Registro* registro){

	 int gap = 1; // Intervalo 
	 int aux;
	 int j;

	 

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
					
					registro->comparacoes++; // Contabiliza comparação
					if(aux < vetor[j]){
						vetor[j + gap] = vetor[j];
						registro->trocas++; // Contabiliza troca
						j = j - gap;
					} else {
						break;
					}
					
				}

				vetor[j + gap] = aux; // Essa troca já foi contabilizada dentro do if do while acima
			
		  }
	 }
}

void selectionSort(int* vetor, int tamanho, Registro* registro){
	
    registro->comparacoes = 0; // Comparações
    registro->trocas = 0; // Trocas 

	for(int i = 0; i < (tamanho - 1); i++){
		int indice_menor = i;
		
		for(int j = i + 1; j < tamanho; j++){
			registro->comparacoes++;		// Contabiliza comparação
			if(vetor[j] < vetor[indice_menor]){
				indice_menor = j;
			}
		}
	
		registro->comparacoes++;			// Contabiliza comparação
		if(indice_menor != i){
			int aux = vetor[i];
			vetor[i] = vetor[indice_menor];
			vetor[indice_menor] = aux;
			registro->trocas++;			// Cotabiliza troca
		}
		
	}

}

void heapify(int* vetor, int tamanho, int raiz, Registro* registro){
	int maior = raiz;		// Supõe que a raiz é o maior número
	int esquerda = (2 * raiz) + 1;	// Conta para lidar um array como uma árvore binária. Isso pega o filho à esquerda
	int direita = (2 * raiz) + 2;		// Conta para lidar um array como uma árvore binária. Isso pega o filho à direita

	// Verifica se existe um filho à esquerda, e verifica se o filho da esquerda é maior do que a raiz
	registro->comparacoes++;		// Contabiliza comparação
	if(esquerda < tamanho && vetor[esquerda] > vetor[maior]){
		maior = esquerda;
	}

	// Verifica se existe filho à direita, e verifica se o filho da direita é maior do que o maior número conhecido 
	// até agora (Seja a raiz, ou o filho da esquerda)
	registro->comparacoes++;		// Contabiliza comparação
	if(direita < tamanho && vetor[direita] > vetor[maior]){
		maior = direita;
	}

	// Se o maior valor não for a raiz, troca de posição com a raiz e heapifica (deixar em max heap) a "nova subárvore"
	registro->comparacoes++;		// Contabiliza comparação
	if(maior != raiz){
		int aux = vetor[raiz];
		vetor[raiz] = vetor[maior];
		vetor[maior] = aux;
		registro->trocas++;		//Contabiliza troca

		// Heapifica a "nova subárvore" recursivamente
		heapify(vetor, tamanho, maior, registro);
	}

}

void heapSort(int* vetor, int tamanho, Registro* registro){
	// Deixa toda a árvore em max heap, chamando o heapify em todo ramo que possui filho
	for(int i = (tamanho / 2) - 1; i >= 0; i--)
		heapify(vetor, tamanho, i, registro);

	// Pega o maior elemento da árvore (raiz), coloca por último no vetor e subtrai 1 do tamanho da árvore.
	// Assim sucessivamente até o vetor estar ordenado
	for(int i = tamanho - 1; i >= 0; i--){
		int aux = vetor[i];
		vetor[i] = vetor[0];
		vetor[0] = aux;
		registro->trocas++;		// Contabiliza troca

		// Deixa a nova árvore em max heap
		heapify(vetor, i, 0, registro);
	}
}

int particaoCentroLomuto(int* vetor, int inicio, int fim, Registro* registro){
	int centro = inicio + (fim - inicio) / 2;
	int pivo = vetor[centro];
	int posicaoPivo = inicio;

	// Move o pivô para o último elemento do vetor
	int aux = vetor[fim];
	vetor[fim] = vetor[centro];
	vetor[centro] = aux;
	registro->trocas++;		// Contabiliza troca

	for(int j = inicio; j < fim; j++){
		
		registro->comparacoes++;		// Contabiliza comparação
		if(vetor[j] <= pivo){
			int aux = vetor[posicaoPivo];
			vetor[posicaoPivo] = vetor[j];
			vetor[j] = aux;
			registro->trocas++;		// Contabiliza troca
			posicaoPivo++;
		}
	}
	aux = vetor[posicaoPivo];
	vetor[posicaoPivo] = vetor[fim];
	vetor[fim] = aux;
	registro->trocas++;		// Contabiliza troca

	return posicaoPivo;
}

void quickSortCentroLomuto(int* vetor, int inicio, int fim, Registro* registro){
	if(inicio < fim){
		int posicaoPivo = particaoCentroLomuto(vetor, inicio, fim, registro);	// Escolhe um pivô e deixa número menores à esquerda e maiores à direita
		quickSortCentroLomuto(vetor, inicio, posicaoPivo - 1, registro);	// Ordena o lado esquerdo do pivô
		quickSortCentroLomuto(vetor, posicaoPivo + 1, fim, registro);		// Ordena o lado direito do pivô
	}
}

int particaoCentroHoare(int* vetor, int inicio, int fim, Registro* registro){
	// Escolhe o pivô no centro
	int centro = inicio + (fim - inicio) / 2;
	int pivo = vetor[centro];
	int i = inicio - 1;
	int j = fim + 1;

	while (1) {
		// Move o ponteiro i para a direita enquanto o valor for menor que o pivô
		do {
			i++;
			registro->comparacoes++; // Contabiliza comparação
		} while (vetor[i] < pivo);

		// Move o ponteiro j para a esquerda enquanto o valor for maior que o pivô
		do {
			j--;
			registro->comparacoes++; // Contabiliza comparação
		} while (vetor[j] > pivo);

		// Se os ponteiros se cruzarem, a partição acabou
		if (i >= j) {
			return j;
		}

		// Se encontrou um valor maior à esquerda e um menor à direita, troca-os
		int aux = vetor[j];
		vetor[j] = vetor[i];
		vetor[i] = aux;
		registro->trocas++;		// Contabiliza troca
	}
}

void quickSortCentroHoare(int* vetor, int inicio, int fim, Registro* registro){
	if(inicio < fim){
		int p = particaoCentroHoare(vetor, inicio, fim, registro);		// Escolhe um pivô e deixa número menores ou iguais à esquerda e maiores à direita
		// Até o indice p, os números do vetor são menores ou iguais ao pivô. Depois dele, os números são maiores que o pivô
		quickSortCentroHoare(vetor, inicio, p, registro);		// Ordena os número menores ou iguais ao pivô
		quickSortCentroHoare(vetor, p + 1, fim, registro);	// Ordena os número maiores que o pivô
	}

}

int particaoFim(int* vetor, int inicio, int fim, Registro* registro){
	int pivo = vetor[fim];
	int posicaoPivo = inicio;
	for(int j = inicio; j < fim; j++){
		
		registro->comparacoes++;		// Contabiliza comparação
		if(vetor[j] <= pivo){
			int aux = vetor[posicaoPivo];
			vetor[posicaoPivo] = vetor[j];
			vetor[j] = aux;
			registro->trocas++;		// Contabiliza troca
			posicaoPivo++;
		}
	}
	int aux = vetor[posicaoPivo];
	vetor[posicaoPivo] = vetor[fim];
	vetor[fim] = aux;
	registro->trocas++;		// Contabiliza troca

	return posicaoPivo;
}

void quickSortFim(int* vetor, int inicio, int fim, Registro* registro){
	if(inicio < fim){
		int posicaoPivo = particaoFim(vetor, inicio, fim, registro);	// Escolhe um pivô e deixa número menores à esquerda e maiores à direita
		quickSortFim(vetor, inicio, posicaoPivo - 1, registro);	// Ordena o lado esquerdo do pivô
		quickSortFim(vetor, posicaoPivo + 1, fim, registro);		// Ordena o lado direito do pivô
	}
}

int particaoMediana(int* vetor, int inicio, int fim, Registro* registro){
	
	int meio = inicio + (fim - inicio) / 2;
	
	// Ordena o primeiro, o do meio e o último elemento. Ao final, a mediana estará no meio.
	registro->comparacoes++;		// Contabiliza comparação
	if(vetor[inicio] > vetor[meio]){
		int aux = vetor[meio];
		vetor[meio] = vetor[inicio];
		vetor[inicio] = aux;
		registro->trocas++;		// Contabiliza troca
	}

	registro->comparacoes++;		// Contabiliza comparação
	if(vetor[inicio] > vetor[fim]){
		int aux = vetor[fim];
		vetor[fim] = vetor[inicio];
		vetor[inicio] = aux;
		registro->trocas++;		// Contabiliza troca
	}

	registro->comparacoes++;		// Contabiliza comparação
	if(vetor[meio] > vetor[fim]){
		int aux = vetor[fim];
		vetor[fim] = vetor[meio];
		vetor[meio] = aux;
		registro->trocas++;		// Contabiliza troca
	}

	// A mediana agora está no meio
	int pivo = vetor[meio];
	int i = inicio - 1;
	int j = fim + 1;

	while (1) {
		// Move o ponteiro i para a direita enquanto o valor for menor que o pivô
		do {
			i++;
			registro->comparacoes++; // Contabiliza comparação
		} while (vetor[i] < pivo);

		// Move o ponteiro j para a esquerda enquanto o valor for maior que o pivô
		do {
			j--;
			registro->comparacoes++; // Contabiliza comparação
		} while (vetor[j] > pivo);

		// Se os ponteiros se cruzarem, a partição acabou
		if (i >= j) {
			return j;
		}

		// Se encontrou um valor maior à esquerda e um menor à direita, troca-os
		int aux = vetor[j];
		vetor[j] = vetor[i];
		vetor[i] = aux;
		registro->trocas++;		// Contabiliza troca
	}
}

void quickSortMediana(int* vetor, int inicio, int fim, Registro* registro){
	if(inicio < fim){
		int p = particaoMediana(vetor, inicio, fim, registro);		// Escolhe um pivô e deixa número menores ou iguais à esquerda e maiores à direita
		// Até o indice p, os números do vetor são menores ou iguais ao pivô. Depois dele, os números são maiores que o pivô
		quickSortMediana(vetor, inicio, p, registro);		// Ordena os número menores ou iguais ao pivô
		quickSortMediana(vetor, p + 1, fim, registro);	// Ordena os número maiores que o pivô
	}
}
/*
 Tem que alterar sistema de contabilização de trocas. Não está coerente!
*/
void merge(int* vetor, int inicio, int meio, int tamanho, Registro* registro){
	// Separa o vetor em dois vetores
	int tam_esquerda = meio - inicio;
	int tam_direita = tamanho - meio;
	int* vetor_esquerda = (int*) malloc(tam_esquerda * sizeof(int));	
	int* vetor_direita = (int*) malloc(tam_direita * sizeof(int));	
	
	for(int i = 0; i < tam_esquerda; i++){
		vetor_esquerda[i] = vetor[inicio + i];
	}

	for(int i = 0; i < tam_direita; i++){
		vetor_direita[i] = vetor[meio + i];
	}

	// Ordena o vetor principal de acordo com os outros dois vetores
	int topo_esquerda = 0;
	int topo_direita = 0;
	int k = inicio;

	// Enquanto houver elementos nos dois vetores simultâneamente, eles serão comparados e ordenados no vetor principal
	while (topo_esquerda < tam_esquerda && topo_direita < tam_direita) {
      
		registro->comparacoes++; 	// Contabiliza comparação
        if (vetor_esquerda[topo_esquerda] <= vetor_direita[topo_direita]) {
            vetor[k] = vetor_esquerda[topo_esquerda];
            topo_esquerda++;
        } else {
            vetor[k] = vetor_direita[topo_direita];
            topo_direita++;
        }
		  registro->trocas++;	// Contabiliza trocas
        k++;
    }

    // Copia os elementos do vetor em que sobrou elementos
    while (topo_esquerda < tam_esquerda) {
        vetor[k] = vetor_esquerda[topo_esquerda];
        topo_esquerda++;
		  registro->trocas++;	// Contabiliza trocas
        k++;
    }

    while (topo_direita < tam_direita) {
        vetor[k] = vetor_direita[topo_direita];
        topo_direita++;
		  registro->trocas++;	// Contabiliza trocas
        k++;
    }

    free(vetor_esquerda);
    free(vetor_direita);
}

void mergeSort(int* vetor, int inicio, int tamanho, Registro* registro){
	// Divide o vetor em vetores menores (até chegar em um vetor de 1 elemento) e os reagrupa em um vetor ordenado
	if(tamanho - inicio > 1){
		int meio = inicio + (tamanho - inicio) / 2;
		mergeSort(vetor, inicio, meio, registro);
		mergeSort(vetor, meio, tamanho, registro);
		merge(vetor, inicio, meio, tamanho, registro);
	}
}

void countingSort(int* vetor, int tamanho, int expoente, Registro* registro){
	int* saida = (int*) malloc(tamanho * sizeof(int));
	int count_digito[10] = {0};

	if(saida != NULL){
		for(int i = 0; i < tamanho; i++){
			int digito = (vetor[i] / expoente) % 10;
			count_digito[digito]++;
		}

		for(int i = 1; i < 10; i++){
			count_digito[i] += count_digito[i - 1];
		}

		for(int i = tamanho - 1; i >= 0; i--){
			int digito = (vetor[i] / expoente) % 10;
			saida[count_digito[digito] - 1] = vetor[i];
			count_digito[digito]--;
		}

		for(int i = 0; i < tamanho; i++){
			vetor[i] = saida[i];
			registro->trocas++;		// Contabiliza troca
		}

		free(saida);
	}
	else
		printf("Erro ao alocar memória para o vetor \"saida\"!\n");

}

void radixSort(int* vetor, int tamanho, Registro* registro){
	int maior = vetor[0];
	for(int i = 1; i < tamanho; i++){
		if(vetor[i] > maior)
			maior = vetor[i];
	}

	for(int expoente = 1; (maior / expoente) > 0; expoente *= 10){
		countingSort(vetor, tamanho, expoente, registro);
	}

}	

// Insercao direta para ordenar os baldes do Bucket Sort
void insertionSortBucket(int* vetor, int inicio, int fim, Registro* registro) {
    for (int i = inicio + 1; i <= fim; i++) {
        int chave = vetor[i];
        int j = i - 1;
        while (j >= inicio) {
            registro->comparacoes++;
            if (vetor[j] > chave) {
                vetor[j + 1] = vetor[j];
                registro->trocas++; // Movimentação interna
                j--;
            } else {
                break;
            }
        }
        vetor[j + 1] = chave;	// Essa troca já foi contabilizada
    }
}

void bucketSort(int* vetor, int tamanho, Registro* registro) {
    if (n <= 0) return;

    // Achar maior e menor para definir o intervalo
    int maior = vetor[0];
	int menor = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) 
			maior = vetor[i];
        else if (vetor[i] < menor) 
			menor = vetor[i];
    }

	// Verifica se todos os elementos do vetor são iguais
    if (maior == menor) 
		return; 

    int num_baldes = tamanho;
    int* cont_baldes = (int*) malloc(num_baldes * sizeof(int));	// Armazenamena quantos elementos tem cada balde
    int* inicio_baldes = (int*) malloc(num_baldes * sizeof(int));	// Armazena o início de cada balde
    int* aux_vetor = (int*) malloc(tamanho * sizeof(int));	// vetor auxiliar que será ordenado

    double elementos_por_baldes = (double)(maior - menor + 1) / num_baldes;
	
	// Calcula um indice do balde para cada elemento do vetor
    for (int i = 0; i < tamanho; i++) {
        
		int indice_balde = (int)((vetor[i] - menor) / elementos_por_baldes);
        
		// Corrigi indice que não é menor que a quantidade de baldes. Isso pode acontecer
		// devido ao truncamento
		if (indice_balde >= num_baldes) {
			indice_balde = num_baldes - 1;
		}
        
		cont_baldes[indice_balde]++;
    }

	// Define início de cada balde
    inicio_baldes[0] = 0;
    for (int i = 1; i < num_baldes; i++) {
        inicio_baldes[i] = inicio_baldes[i - 1] + cont_baldes[i - 1];
    }

    // Vetor temporário para não perder os índices originais durante a distribuição
    int* aux_inicio_baldes = (int*) malloc(num_baldes * sizeof(int));
    for(int i = 0; i < num_baldes; i++){ 
		aux_inicio_baldes[i] = inicio_baldes[i];
	}

    // Distribuir os elementos nos baldes
    for (int i = 0; i < tamanho; i++) {
        int indice_balde = (int)((vetor[i] - menor) / elementos_por_baldes);
        
		if (indice_balde >= num_baldes){
			indice_balde = num_baldes - 1;
		}
        aux_vetor[aux_inicio_baldes[indice_balde]] = vetor[i];
        aux_inicio_baldes[indice_balde]++;
        registro->trocas++; // Movimentação para o auxiliar
    }

    // Ordena cada balde
    for (int i = 0; i < num_baldes; i++) {
        int inicio_balde = inicio_baldes[i];
        int fim_balde = aux_inicio_baldes[i] - 1;
        if (inicio_balde < fim_balde) {
            insercaoDireta(aux_vetor, inicio_balde, fim_balde, registro);
        }
    }

    // Copia os baldes já ordenados para o vetor principal
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = aux_vetor[i];
        registro->trocas++; // Movimentação de volta
    }

    free(cont_baldes);
    free(inicio_baldes);
    free(aux_inicio_baldes);
    free(aux_vetor);
}
