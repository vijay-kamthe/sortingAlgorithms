CFLAGS=-Wall

all: test

test: test.o
	gcc -o test utils.c vector.c bubblesort.c quicksort.c mergesort.c test.c

clean:
	rm -f test.o bubblesort.o quicksort.o vector.o mergesort.o utils.o
