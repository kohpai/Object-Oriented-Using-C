CC=gcc
CFLAG=-Wall -Werror -Iinc/ -c -o
LFLAG=-g
SOURCES=$(wildcard src/*.c)
OBJECTS=$(addprefix obj/,$(notdir $(SOURCES:.c=.o)))

all: bin/main

bin/main: $(OBJECTS)
	$(CC) $^ -o $@ $(LFLAG)
	./$@

obj/%.o: src/%.c
	$(CC) $(CFLAG) $@ $^

clean:
	@-rm obj/*
	@-rm bin/*
