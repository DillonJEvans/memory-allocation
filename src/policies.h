#ifndef POLICIES_H_
#define POLICIES_H_

#include "memory_pool.h" // MemoryBlock

// Returns the first free block in the pool that fits the size.
// Returns NULL if none of the free blocks are large enough.
char *FirstFit(char *pool, int size);

// Returns the free block in the pool that fits the size the best.
// Returns NULL if none of the free blocks are large enough.
char *BestFit(char *pool, int size);

// Returns the free block in the pool that fits the size the worst.
// Returns NULL if none of the free blocks are large enough.
char *WorstFit(char *pool, int size);

// Returns the next free block in the pool.
// Returns NULL if there are no more free blocks in the pool.
// Sets *size to the size of the returned block.
char *NextFreeBlock(char *pool, int *size);

#endif // POLICIES_H_
