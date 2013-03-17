CFLAGS=-Wall -g -ggdb -Wextra -O2

CC=gcc

.PHONY:all
all: run

CSOURCE=utils.c \
	bubblesort.c \
	quicksort.c \
	mergesort.c \
	heapsort.c \
	main.c

run: $(CSOURCE)
	$(CC) $(CFLAGS) -o run $(CSOURCE)

.PHONY:clean
clean:
	rm -f run

