CC = gcc
LIBS = -lbl

all: pootis

pootis : pootis.o
	$(CC) -o $@ $@.o

%.o: %.c
	@echo 'Building $@ from $<'
	$(CC) -o $@ -c -I. $<

clean:
	rm -f *.o pootis
