#ifndef ALLOCATION_POLICIES_H_
#define ALLOCATION_POLICIES_H_

#include "memory_block.h" // MemoryBlock
#include "memory_pool.h"  // MemoryPool

// Returns the first free block in the pool that fits the size.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *FirstFit(const MemoryPool *pool, int size);

// Returns the free block in the pool that fits the size the best.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *BestFit(const MemoryPool *pool, int size);

// Returns the free block in the pool that fits the size the worst.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *WorstFit(const MemoryPool *pool, int size);

#endif // ALLOCATION_POLICIES_H_
