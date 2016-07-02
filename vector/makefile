CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g

all: array tests

array: array.o
	$(CC) $(CFLAGS) main.c array.o -o array

tests: test.o
	$(CC) $(CFLAGS) test_main.c test.o -o tests

array.o: array.c
	$(CC) $(CFLAGS) -c array.c

test.o: test.c
	$(CC) $(CFLAGS) -c test.c

