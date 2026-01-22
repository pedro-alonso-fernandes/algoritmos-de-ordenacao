all: compila executa clean

compila: GeraNum.o Algoritmos.o main.o
	gcc GeraNum.o Algoritmos.o main.o -o executavel

GeraNum.o: GeraNum.c 
	gcc -c GeraNum.c

Algoritmos.o: Algoritmos.c
	gcc -c Algoritmos.c

main.o: main.c
	gcc -c main.c

executa: executavel
	./executavel

clean:
	rm -f GeraNum.o Algoritmos.o main.o executavel