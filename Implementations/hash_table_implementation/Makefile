CC = gcc
CFLAGS = -Wall -ansi -pedantic

list: testsymtab.o symtablelist.o
	$(CC) $(CFLAGS) -o testsymtab testsymtab.o symtablelist.o

hash: testsymtab.o symtablehash.o
	$(CC) $(CFLAGS) -o testsymtab testsymtab.o symtablehash.o


testsymtab.o: testsymtab.c symtable.h
	$(CC) $(CFLAGS) -c testsymtab.c

symtablelist.o: symtable.h symtablelist.c
	$(CC) $(CFLAGS) -c symtablelist.c

symtablehash.o: symtable.h symtablehash.c
	$(CC) $(CFLAGS) -c symtablehash.c

clean:
	rm *.o testsymtab
