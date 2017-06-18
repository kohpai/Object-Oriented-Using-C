CC=gcc
CFLAG=-Wall -Werror -Iinc/ -c -o
LFLAG=-o -g
SOURCES=$(find src -name '*.c')
OBJECTS=$(addprefix obj/,$(SOURCES:%.c=%.o))

all: bin/main

bin/main: $(OBJECTS)
	$(CC) $@ $^ $(LFLAG)

obj/%.o: src/%.c
	$(CC) $(CFLAG) $@ $^

clean:
	@-rm obj/*
	@-rm bin/*
