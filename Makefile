CC = gcc
CFLAGS = -Wall -Wextra # -Werror

.PHONY: clean

clean:
	rm -rf memory
	rm -rf bin/*

memory: bin/memory.o bin/policies.o bin/memory_pool.o
	$(CC) -o $@ $^ $(CFLAGS)

bin/memory.o: src/memory.c
	$(CC) -c -o $@ $< $(CFLAGS)

bin/policies.o: src/policies.c src/policies.h
	$(CC) -c -o $@ $< $(CFLAGS)

bin/memory_pool.o: src/memory_pool.c src/memory_pool.h
	$(CC) -c -o $@ $< $(CFLAGS)
