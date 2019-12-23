CC=gcc
all: progmain progmains

progmain: isort.o  main.o 
	$(CC) -Wall main.o isort.o -o progmain 

progmains: mains.o txtfind.o 
	$(CC) -Wall mains.o txtfind.o -o progmains 

isort.o: isort.c
	$(CC) -Wall -c isort.c -o isort.o
		
main.o: main.c libmyBank.a
	$(CC) -Wall -c -o main.o main.c

mains.o: mains.c libmyBank.a
	$(CC) -Wall -c -o mains.o mains.c

txtfind.o: txtfind.c
	$(CC) -Wall -c txtfind.c -o txtfind.o

clean:
	rm *.o *.a progmain 

.PHONY: clean all






