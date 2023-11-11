#include "policies.h"
#include "memory_block.h"

int main(/* int argc, const char *argv[] */)
{
  MemoryBlock *head = CreateMemoryPool(80);
  PrintMemoryPool(head);
  FreeMemoryPool(head);
  return 0;
}
