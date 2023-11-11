#include "memory_block.h"

MemoryBlock *CreateMemoryBlock(int size, const char *process)
{
  MemoryBlock *block = malloc(sizeof(*block));
  block->size = size;
  if (process)
  {
    block->process = strdup(process);
  }
  else
  {
    block->process = NULL;
  }
  block->prev = NULL;
  block->next = NULL;
  return block;
}

void FreeMemoryBlock(MemoryBlock *block)
{
  if (block == NULL) return;
  free(block->process);
  free(block);
}
