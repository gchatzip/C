




CC  = gcc
CFLAGS = -Wall -ansi -pedantic -o


all: data3 data6 data9
	
data3: a3.out
	./a3.out

a3.out: createdata3.c
	$(CC) $(CFLAGS) a3.out createdata3.c

data6: a6.out
	./a6.out

a6.out: createdata6.c
	$(CC) $(CFLAGS) a6.out createdata6.c

data9: a9.out
	./a9.out

a9.out: createdata9.c
	$(CC) $(CFLAGS) a9.out createdata9.c

clean:
	rm -rf a3.out a6.out a9.out data3 data6 data9