CC = gcc
CFLAGS =
LIBS = -lbl

all: pootis arenafiles

pootis:
	$(MAKE) -C ./src

arenafiles: 
	$(MAKE) -C ./arena_src

clean:
	cd ./src && $(MAKE) clean && cd ../arena_src && $(MAKE) clean

tidy:
	cd ./src && $(MAKE) tidy && cd ../arena_src && $(MAKE) tidy
