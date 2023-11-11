#include "memory_block.h"

MemoryBlock *CreateMemoryPool(int size)
{
  MemoryBlock *head = malloc(sizeof(*head));
  head->size = size;
  head->process = FREE_BLOCK;
  head->prev = NULL;
  head->next = NULL;
  return head;
}

void FreeMemoryPool(MemoryBlock *head)
{
  if (head == NULL) return;
  // Free every block in the pool.
  MemoryBlock *current = head;
  MemoryBlock *next;
  while (current)
  {
    next = current->next;
    free(current);
    current = next;
  }
}

void PrintMemoryPool(const MemoryBlock *head)
{
  for (const MemoryBlock *current = head; current; current = current->next)
  {
    // Determine the name of the process to print.
    char process;
    if (current->process == FREE_BLOCK) process = '.';
    else process = current->process;
    for (int byte = 0; byte < current->size; byte++)
    {
      fputc(process, stdout);
    }
  }
  fputc('\n', stdout);
}

void AllocateMemoryBlock(MemoryBlock *block, int size, char process)
{
  // If the block is the perfect size, switch it from being free to
  // being allocated and then coalesce.
  if (block->size == size)
  {
    block->process = process;
    CoalesceMemoryBlock(block);
    return;
  }
  // If the block isn't the perfect size but the previous block is allocated to `process`,
  // then shift `size` bytes over to the previous block, no coalescing needed.
  if (block->prev && block->prev->process == process)
  {
    block->prev->size += size;
    block->size -= size;
    return;
  }
  // If the block isn't the perfect size and the previous block is not allocated to `process`,
  // split the block into two separate blocks. No coalescing needed.
  MemoryBlock *freeBlock = malloc(sizeof(*freeBlock));
  freeBlock->size = block->size - size;
  freeBlock->process = FREE_BLOCK;
  freeBlock->prev = block;
  freeBlock->next = block->next;
  block->next = freeBlock;
  if (freeBlock->next)
  {
    freeBlock->next->prev = freeBlock;
  }
  block->size = size;
  block->process = process;
}

MemoryBlock *FreeProcess(MemoryBlock *head, char process)
{
  for (MemoryBlock *current = head; current; current = current->next)
  {
    if (current->process == process)
    {
      // Free the block and then coalesce it.
      current->process = FREE_BLOCK;
      current = CoalesceMemoryBlock(current);
    }
  }
  return head;
}

MemoryBlock *CoalesceMemoryBlock(MemoryBlock *block)
{
  // If the previous block and current block are for the same process,
  // have the current block coalesce into the previous block.
  MemoryBlock *prev = block->prev;
  if (prev && prev->process == block->process)
  {
    prev->size += block->size;
    prev->next = block->next;
    block->next->prev = prev;
    free(block);
    block = prev;
  }
  // If the current block and next block are for the same process,
  // have the next block coalesce into the current block.
  MemoryBlock *next = block->next;
  if (next && next->process == block->process)
  {
    block->size += next->size;
    block->next = next->next;
    next->next->prev = block;
    free(next);
  }
  return block;
}
