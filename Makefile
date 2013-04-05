CFLAGS=-Wall -g -ggdb -Wextra -O2

POSTFLAGS=-lrt

CC=gcc

.PHONY:all
all: run

CSOURCE=utils.c \
	bubblesort.c \
	quicksort.c \
	mergesort.c \
	heapsort.c \
	hashmap.c \
	main.c

run: $(CSOURCE)
	$(CC) $(CFLAGS) -o run $(CSOURCE) $(POSTFLAGS)

.PHONY:clean
clean:
	rm -f run

