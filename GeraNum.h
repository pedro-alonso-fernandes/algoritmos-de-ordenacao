#ifndef GERANUM_H
#define GERANUM_H

typedef enum{
	ALEATORIO,
	CRESCENTE,
	DECRESCENTE
}MetodoGeracao;

void gerarNumeros(int qtd, MetodoGeracao metodo);

#endif