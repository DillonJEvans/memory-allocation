#ifndef POLICIES_H_
#define POLICIES_H_

#include "memory_block.h" // MemoryBlock

// Returns the first free block in the pool that fits the size.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *FirstFit(MemoryBlock *head, int size);

// Returns the free block in the pool that fits the size the best.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *BestFit(MemoryBlock *head, int size);

// Returns the free block in the pool that fits the size the worst.
// Returns NULL if none of the free blocks are large enough.
MemoryBlock *WorstFit(MemoryBlock *head, int size);

#endif // POLICIES_H_
