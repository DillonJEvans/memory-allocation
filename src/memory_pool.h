#ifndef MEMORY_POOL_H_
#define MEMORY_POOL_H_

#include <stdio.h>
#include <string.h>

#define POOL_SIZE (80)
#define FREE_BYTE ('.')

void FreeMemoryPool(char *pool);

void AllocateMemoryBlock(char *block, int size, char process);

void FreeProcess(char *pool, char process);

void PrintMemoryPool(const char *pool);

#endif // MEMORY_POOL_H_
