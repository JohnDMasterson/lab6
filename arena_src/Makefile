CC = gcc
CFLAGS =

all: arena assassin fork ninja

arena: arena4.o
	$(CC) -o ../arena/$@ $@4.o

assassin: assassin.o
	$(CC) -o ../arena/$@ $@.o

fork: fork.o
	$(CC) -o ../arena/$@ $@.o

ninja: ninja.o
	$(CC) -o ../arena/$@ $@.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o ../arena/arena ../arena/assassin ../arena/fork ../arena/ninja

tidy:
	rm -f *.o
