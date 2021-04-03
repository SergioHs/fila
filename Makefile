# the compiler: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS  = -g -Wall -O3

default: main

fila.o: fila.c fila_interface.h fila_privado.h
	$(CC) $(CFLAGS) -c fila.c -o fila.o

main: main.c fila.o
	$(CC) $(CFLAGS) main.c fila.o -o main

clean:
	rm -f main *.o core a.out *.*~ Makefile~

all: main