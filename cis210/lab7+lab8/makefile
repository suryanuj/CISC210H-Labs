all: client server
client: main.o
	gcc main.o -o client
main.o: main.c
	gcc -c main.c 
clean:
	rm -f client*.o

server: main2.o
	gcc main2.o -o server
main2.o: main2.c
	gcc -c main2.c
clean1:
	rm -f server *.o

