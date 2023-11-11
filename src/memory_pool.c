#include "memory_pool.h"

void FreeMemoryPool(char *pool)
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

void PrintMemoryPool(const char *pool)
{
  puts(pool);
}
