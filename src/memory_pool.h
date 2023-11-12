#ifndef MEMORY_POOL_H_
#define MEMORY_POOL_H_

#include <stdio.h>
#include <string.h>

#define POOL_SIZE (80)
#define FREE_BYTE ('.')

// Initializes the memory pool to be one free block.
void InitializeMemoryPool(char *pool);

// Allocates the first `size` bytes of `block` to `process`.
void AllocateMemoryBlock(char *block, int size, char process);

// Frees all blocks allocated to `process`.
void FreeProcess(char *pool, char process);

// Compacts the memory pool.
// AKA moves all allocated blocks to be contiguous,
// leaving a single free block at the end of the pool.
void CompactMemoryPool(char *pool);

// Prints the memory pool.
void PrintMemoryPool(const char *pool);

#endif // MEMORY_POOL_H_
