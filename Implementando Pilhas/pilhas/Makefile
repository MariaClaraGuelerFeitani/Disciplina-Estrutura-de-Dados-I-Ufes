all: compila executa
compila: main.o pilha.o
	gcc main.o pilha.o -o prog
main.o: main.c
	gcc -c main.c
pilha.o: pilha.c
	gcc -c pilha.c
executa: 
	./prog
clean:
	del main.o pilha.o prog.exe
