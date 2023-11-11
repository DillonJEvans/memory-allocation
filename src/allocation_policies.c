#include "allocation_policies.h"

MemoryBlock *FirstFit(const MemoryPool *pool, int size)
{
  for (MemoryBlock *current = pool->head; current; current = current->next)
  {
    if (current->process) continue;
    if (current->size >= size)
    {
      return current;
    }
  }
  return NULL;
}

MemoryBlock *BestFit(const MemoryPool *pool, int size)
{
  MemoryBlock *best = NULL;
  for (MemoryBlock *current = pool->head; current; current = current->next)
  {
    if (current->process) continue;
    if (current->size < size) continue;
    if (!best || (current->size < best->size))
    {
      best = current;
    }
  }
  return best;
}

MemoryBlock *WorstFit(const MemoryPool *pool, int size)
{
  MemoryBlock *worst = NULL;
  for (MemoryBlock *current = pool->head; current; current = current->next)
  {
    if (current->process) continue;
    if (current->size < size) continue;
    if (!worst || (current->size > worst->size))
    {
      worst = current;
    }
  }
  return worst;
}
