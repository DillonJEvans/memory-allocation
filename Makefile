CC = gcc
CFLAGS = -Wall -Wextra # -Werror

.PHONY: clean

clean:
	rm -rf memory
	rm -rf bin/*

memory: bin/memory.o bin/policies.o bin/memory_block.o
	$(CC) -o $@ $^ $(CFLAGS)

bin/memory.o: src/memory.c
	$(CC) -c -o $@ $< $(CFLAGS)

bin/policies.o: src/policies.c src/policies.h
	$(CC) -c -o $@ $< $(CFLAGS)

bin/memory_block.o: src/memory_block.c src/memory_block.h
	$(CC) -c -o $@ $< $(CFLAGS)
