all: dicetest 

dicetest: main.o
	gcc main.o -o dicetest  -lsense -lm
main.o: main.c
	gcc -c main.c 
clean:
	rm -f dicetest*.o

