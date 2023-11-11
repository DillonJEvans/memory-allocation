#include "policies.h"

MemoryBlock *FirstFit(MemoryBlock *head, int size)
{
  for (MemoryBlock *current = head; current; current = current->next)
  {
    if (current->process != FREE_BLOCK) continue;
    if (current->size >= size)
    {
      return current;
    }
  }
  return NULL;
}

MemoryBlock *BestFit(MemoryBlock *head, int size)
{
  MemoryBlock *best = NULL;
  for (MemoryBlock *current = head; current; current = current->next)
  {
    if (current->process != FREE_BLOCK) continue;
    if (current->size < size) continue;
    if (!best || (current->size < best->size))
    {
      best = current;
    }
  }
  return best;
}

MemoryBlock *WorstFit(MemoryBlock *head, int size)
{
  MemoryBlock *worst = NULL;
  for (MemoryBlock *current = head; current; current = current->next)
  {
    if (current->process != FREE_BLOCK) continue;
    if (current->size < size) continue;
    if (!worst || (current->size > worst->size))
    {
      worst = current;
    }
  }
  return worst;
}
