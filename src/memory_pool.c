#include "memory_pool.h"

void InitializeMemoryPool(char *pool)
{
  memset(pool, FREE_BYTE, POOL_SIZE);
  pool[POOL_SIZE] = '\0';
}

void AllocateMemoryBlock(char *block, int size, char process)
{
  memset(block, process, size);
}

void FreeProcess(char *pool, char process)
{
  for (int i = 0; i < POOL_SIZE; i++)
  {
    if (pool[i] == process)
    {
      pool[i] = FREE_BYTE;
    }
  }
}

void CompactMemoryPool(char *pool)
{
  // Move all the allocated bytes to the front of the pool.
  int freeByte = 0;
  for (int i = 0; i < POOL_SIZE; i++)
  {
    if (pool[i] != FREE_BYTE)
    {
      pool[freeByte] = pool[i];
      freeByte++;
    }
  }
  // Free all of the remaining bytes.
  while (freeByte < POOL_SIZE)
  {
    pool[freeByte] = FREE_BYTE;
    freeByte++;
  }
}

void PrintMemoryPool(const char *pool)
{
  puts(pool);
}
