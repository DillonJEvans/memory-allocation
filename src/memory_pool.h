#ifndef MEMORY_POOL_H_
#define MEMORY_POOL_H_

#include <stdio.h>  // 
#include <stdlib.h> // malloc, free
#include <string.h> // strdup

#include "memory_block.h" // MemoryBlock

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

void PrintMemoryPoolByByte(const MemoryPool *pool, const char *freeString);

// void PrintMemoryPoolByBlock(const MemoryPool *pool);

#endif // MEMORY_POOL_H_
