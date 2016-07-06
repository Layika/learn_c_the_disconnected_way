CC=gcc

all: main

library.o: library.c
	$(CC) $(CFLAGS) -fPIC -c library.c -o library.o

liblibrary.so: library.o
	$(CC) -shared -Wl,-soname,liblibrary.so -o liblibrary.so library.o

main.o: main.c
	$(CC) $(CFLAGS) main.c -c -o main.o

main: main.o liblibrary.so
	$(CC) $(CFLAGS) $(LDFLAGS) -L. -llibrary main.o -o main
