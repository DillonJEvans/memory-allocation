#include "policies.h"
#include "memory_pool.h"

int main(/* int argc, const char *argv[] */)
{
  char pool[POOL_SIZE + 1];
  FreeMemoryPool(pool);
  PrintMemoryPool(pool);
  char *block = FirstFit(pool, 10);
  AllocateMemoryBlock(block, 10, 'A');
  block = FirstFit(pool, 10);
  AllocateMemoryBlock(block, 10, 'B');
  PrintMemoryPool(pool);
  FreeProcess(pool, 'A');
  PrintMemoryPool(pool);
  return 0;
}
