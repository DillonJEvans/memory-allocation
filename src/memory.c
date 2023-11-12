#include <stdio.h>

#include "commands.h"
#include "memory_pool.h"

int main()
{
  char pool[POOL_SIZE + 1];
  InitializeMemoryPool(pool);
  while (GetAndExecuteCommand(pool, stdin));
  return 0;
}
