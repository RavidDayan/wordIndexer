CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIBS = -lm

all: index

index: index.c tree.c node.c
	$(CC) $(CFLAGS) index.c tree.c node.c -o index $(LIBS)