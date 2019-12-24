CC = gcc
AR = ar -rcs
FLAGS = -Wall

all: isort txtfind

isort: main.o isort.o
	$(CC) $(FLAGS) main.o isort.o -o isort
txtfind: mains.o txtfind.o 
	$(CC) $(FLAGS) mains.o txtfind.o -o txtfind
main.o: main.c isort.o
	$(CC) $(FLAGS) -c main.c 
isort.o: isort.c
	$(CC) $(FLAGS) -c isort.c
mains.o: mains.c txtfind.o
	$(CC) $(FLAGS) -c mains.c
txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so out isort txtfind