#include "policies.h"
#include "memory_block.h"

int main(/* int argc, const char *argv[] */)
{
  MemoryBlock *head = CreateMemoryPool(80);
  PrintMemoryPool(head);
  MemoryBlock *block = FirstFit(head, 10);
  AllocateMemoryBlock(block, 10, 'A');
  PrintMemoryPool(head);
  block = FirstFit(head, 10);
  AllocateMemoryBlock(block, 10, 'B');
  PrintMemoryPool(head);
  head = FreeProcess(head, 'A');
  PrintMemoryPool(head);
  FreeMemoryPool(head);
  return 0;
}
