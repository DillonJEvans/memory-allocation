#ifndef MEMORY_BLOCK_H_
#define MEMORY_BLOCK_H_

#include <stdio.h>  // fputc, stdout
#include <stdlib.h> // malloc, free

#define FREE_BLOCK ('\0')

// A block of memory. Meant to be used as a node in a linked list of blocks.
typedef struct memory_block
{
  int size;                  // The size in bytes of the block.
  char process;              // The name of the process this block is allocated to.
                             //   Will be FREE_BLOCK if this block is free.
  struct memory_block *prev; // The previous block in the linked list.
  struct memory_block *next; // The next block in the linked list.
} MemoryBlock;

// Creates a memory pool of `size` bytes.
// The pool starts with just a single free memory block.
// Returns the head of the memory pool.
MemoryBlock *CreateMemoryPool(int size);

// Frees the memory pool.
void FreeMemoryPool(MemoryBlock *head);

// Prints the memory pool.
void PrintMemoryPool(const MemoryBlock *head);

void AllocateMemoryBlock(MemoryBlock *block, int size, char process);

// Frees all memory blocks allocated to `process`.
// Returns the new head of the memory pool.
MemoryBlock *FreeProcess(MemoryBlock *head, char process);

// Coalesces the memory block with its neighbors,
// combining adjacent memory blocks if they are allocated to the same process.
// Returns the coalesced block.
MemoryBlock *CoalesceMemoryBlock(MemoryBlock *block);

// MemoryBlock *AllocateMemoryBlock(MemoryBlock *block, int size, char process);
// MemoryBlock *CompactMemoryPool(MemoryBlock *head);

#endif // MEMORY_BLOCK_H_
