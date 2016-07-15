CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -g

all: double_linked_list tmain

double_linked_list: double_linked_list.o
	$(CC) $(CFLAGS) main.c double_linked_list.o -o double_linked_list

tmain: test.o double_linked_list.o
	$(CC) $(CFLAGS) tmain.c test.o double_linked_list.o -o tmain

double_linked_list.o: double_linked_list.c
	$(CC) $(CFLAGS) -c double_linked_list.c

test.o: test.c double_linked_list.c
	$(CC) $(CFLAGS) -c tmain.c

clean:
	rm *.o tmain double_linked_list