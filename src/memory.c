#include "memory_pool.h"

int main(/* int argc, const char *argv[] */)
{
  MemoryPool *pool = CreateMemoryPool(80);
  PrintMemoryPoolByByte(pool, ".");
  pool->head->next = CreateMemoryBlock(10, "A");
  PrintMemoryPoolByByte(pool, ".");
  FreeMemoryPool(pool);
  return 0;
}
