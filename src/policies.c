#include "policies.h"

char *FirstFit(char *pool, int size)
{
  char *block = pool;
  int blockSize = 0;
  while (block && blockSize < size)
  {
    block = NextFreeBlock(block + blockSize, &blockSize);
  }
  return block;
}

char *BestFit(char *pool, int size)
{
  char *best = NULL;
  int bestSize = POOL_SIZE + 1;
  char *block = pool;
  int blockSize = 0;
  while (block)
  {
    block = NextFreeBlock(block + blockSize, &blockSize);
    if (blockSize >= size && blockSize < bestSize)
    {
      best = block;
    }
  }
  return best;
}

char *WorstFit(char *pool, int size)
{
  char *worst = NULL;
  int worstSize = 0;
  char *block = pool;
  int blockSize = 0;
  while (block)
  {
    block = NextFreeBlock(block + blockSize, &blockSize);
    if (blockSize >= size && blockSize > worstSize)
    {
      worst = block;
    }
  }
  return worst;
}

char *NextFreeBlock(char *pool, int *size)
{
  // Find the base of the next free block.
  int base;
  for (base = 0; pool[base] && pool[base] != FREE_BYTE; base++);
  // If a free block could not be found, return NULL.
  if (!pool[base]) return NULL;
  // Determine the size of the free block.
  int blockSize;
  for (blockSize = 0;
       pool[base + blockSize] && pool[base + blockSize] == FREE_BYTE;
       blockSize++);
  // Set *size to the size and return the base of the free block.
  *size = blockSize;
  return pool + base;
}
