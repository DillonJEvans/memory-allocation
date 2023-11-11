#ifndef MEMORY_POOL_H_
#define MEMORY_POOL_H_

#include <stdio.h>  // 
#include <stdlib.h> // malloc, free
#include <string.h> // strdup

#include "memory_block.h" // MemoryBlock

// A linked list of MemoryBlocks.
typedef struct memory_pool
{
  MemoryBlock *head;
  int blocks;
  int size;
  int free_blocks;
  int free_size;
  int allocated_blocks;
  int allocated_size;
} MemoryPool;

// Creates a memory pool of `size` bytes.
// The pool starts with just a single free memory block.
MemoryPool *CreateMemoryPool(int size);

// Frees the memory pool.
void FreeMemoryPool(MemoryPool *pool);

// Prints the memory pool one byte at a time.
// If a byte is allocated, the name of it's process will be printed.
// If a byte is free, `freeProcess` will be printed.
void PrintMemoryPoolByByte(const MemoryPool *pool, const char *freeProcess);

// void PrintMemoryPoolByBlock(const MemoryPool *pool);

#endif // MEMORY_POOL_H_
