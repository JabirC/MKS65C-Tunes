all: LinkedList.o tests.o
		gcc tests.o LinkedList.o

LinkedList.o: LinkedList.c LinkedList.h
		gcc -c LinkedList.c

tests.o: tests.c LinkedList.h
		gcc -c tests.c

run:
		./a.out
