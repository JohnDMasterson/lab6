CC = gcc
CFLAGS =
LIBS = -lbl

all: pootis

test: CFLAGS += -DARENATEST -g
test: pootis

pootis: pootis.o
	$(CC) -o ../arena/$@ $@.o

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o ../arena/pootis

tidy:
	rm -f *.o
