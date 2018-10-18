all: LinkedList.o driver.o Library.o
		gcc driver.o LinkedList.o Library.o

LinkedList.o: LinkedList.c LinkedList.h
		gcc -c LinkedList.c

Library.o: Library.c Library.h LinkedList.h
		gcc -c Library.c

driver.o: driver.c Library.h
		gcc -c driver.c

run:
		./a.out

clean:
		rm *.o
