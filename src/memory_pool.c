#include "memory_pool.h"

MemoryPool *CreateMemoryPool(int size)
{
  MemoryPool *pool = malloc(sizeof(*pool));
  // Create the initial free memory block.
  pool->head = CreateMemoryBlock(size, NULL);
  // Set the information about the memory pool.
  pool->blocks = 1;
  pool->size = size;
  pool->free_blocks = 1;
  pool->free_size = size;
  pool->allocated_blocks = 0;
  pool->allocated_size = 0;
  return pool;
}

void FreeMemoryPool(MemoryPool *pool)
{
  if (pool == NULL) return;
  // Free every block in the pool.
  MemoryBlock *current = pool->head;
  MemoryBlock *next;
  while (current)
  {
    next = current->next;
    FreeMemoryBlock(current);
    current = next;
  }
  free(pool);
}

void PrintMemoryPoolByByte(const MemoryPool *pool, const char *freeProcess)
{
  for (MemoryBlock *current = pool->head; current; current = current->next)
  {
    // Determine the name of the process to print.
    const char *process;
    if (current->process)
    {
      process = current->process;
    }
    else
    {
      process = freeProcess;
    }
    for (int byte = 0; byte < current->size; byte++)
    {
      fputs(process, stdout);
    }
  }
  fputc('\n', stdout);
}
