CFLAGS = -Wall -g 

all: 
	gcc $(CFLAGS) -c -fPIC mylib.c
	gcc -shared -o libmylib.so mylib.o -lc

clean: rm libmylib*


