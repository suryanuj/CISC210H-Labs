INCLUDES=../../include
LIBS=../../lib

all: dicetest 

dicetest: main.o
	gcc main.o -o dicetest -L $(LIBS) -lsense -lm
main.o: main.c
	gcc -c main.c -I $(INCLUDES) 
clean:
	rm -f dicetest*.o
