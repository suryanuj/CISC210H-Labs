all: makex makexc initials

makex: main.o
	gcc main.o -o makex -lsense
main.o: main.c
	gcc -c main.c 
clean:
	rm -f makex *.o

makexc: main2.o
	gcc main2.o -o makexc -lsense
main2.o: main2.c
	gcc -c main2.c
clean1:
	rm -f makexc *.o

initials: main3.o
	gcc main3.o -o initials -lsense
main3.o: main3.c
	gcc -c main3.c
clean2:
	rm -f initials *.o
