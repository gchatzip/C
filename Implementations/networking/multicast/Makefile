
sender: sender.o
	gcc sender.o -o sender

listener: listener.o
	gcc listener.o -o listener

sender.o: sender.c
	gcc -c sender.c -o sender.o


listener.o: listener.c
	gcc -c listener.c -o listener.o


clean:
	rm -rf *.o sender listener
