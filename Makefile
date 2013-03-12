CFLAGS=-Wall -g -ggdb -Wextra -O2

CC=gcc

.PHONY:all
all: test

CSOURCE=utils.c \
	vector.c \
	test.c \
	bubblesort.c \
	quicksort.c#\
#	mergesort.c \
#	heapsort.c

test: $(CSOURCE)
	$(CC) $(CFLAGS) -o test $(CSOURCE)

.PHONY:clean
clean:
	rm -f test

