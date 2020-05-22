all: initials

initials: main.o
	gcc main.o -o initials -lsense
main.o: main.c
	gcc -c main.c 
clean:
	rm -f initials *.o
