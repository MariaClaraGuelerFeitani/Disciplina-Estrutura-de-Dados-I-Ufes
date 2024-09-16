all: compila executa
compila: main.o filas.o 
	gcc main.o filas.o -o prog
main.o: main.c
	gcc -c main.c
filas.o: filas.c
	gcc -c filas.c
executa: 
	./prog
clean:
	del main.o filas.o prog.exe