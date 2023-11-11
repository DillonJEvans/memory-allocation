#include "memory_pool.h"

int main(/* int argc, const char *argv[] */)
{
  MemoryPool *pool = CreateMemoryPool(80);
  FreeMemoryPool(pool);
  return 0;
}
