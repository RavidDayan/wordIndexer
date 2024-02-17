CC = gcc
CFLAGS = -Wall -ansi -pedantic
LIBS = -lm

all: index

mainmat: index.c 
	$(CC) $(CFLAGS) index.c -o index $(LIBS)