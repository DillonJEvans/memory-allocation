#ifndef MEMORY_BLOCK_H_
#define MEMORY_BLOCK_H_

#include <stdlib.h> // malloc, free
#include <string.h> // strdup

// A block of memory. Meant to be used as a node in a linked list of blocks.
typedef struct memory_block
{
  int size;                  // The size in bytes of the block.
  char *process;             // The name of the process this block is allocated to.
                             //   Will be NULL if this block is free.
  struct memory_block *prev; // The previous block in the linked list.
  struct memory_block *next; // The next block in the linked list.
} MemoryBlock;

// Creates a memory block of `size` bytes allocated to `process`.
// If `process` is NULL, the block is considered free.
MemoryBlock *CreateMemoryBlock(int size, const char *process);

// Frees the memory block.
void FreeMemoryBlock(MemoryBlock *block);

#endif // MEMORY_BLOCK_H_
