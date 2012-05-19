CC=g++
CFLAGS=-Wall -c

emitter.o: x86_emitter.cpp *.h
	$(CC) -o $@ $(CFLAGS) x86_emitter.cpp

clean:
	rm -f *.o
