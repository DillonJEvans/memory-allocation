CC = gcc
CFLAGS = -Wall -Wextra -Werror

.PHONY: clean

default: memory

clean:
	rm -rf memory
	rm -rf bin/*

memory: bin/memory.o bin/commands.o bin/policies.o bin/memory_pool.o | bin
	$(CC) -o $@ $^ $(CFLAGS)

bin/memory.o: src/memory.c | bin
	$(CC) -c -o $@ $< $(CFLAGS)

bin/%.o: src/%.c src/%.h | bin
	$(CC) -c -o $@ $< $(CFLAGS)

bin:
	mkdir -p $@
