all: clock
clock: main.o
	gcc main.o -o clock -lsense 
main.o: main.c
	gcc -c main.c 
clean:
	rm -f clock*.o
