#include <stdio.h>

#include "commands.h"
#include "memory_pool.h"

#define PROMPT ("command = ")

int main()
{
  bool stillRunning = true;
  char pool[POOL_SIZE + 1];
  InitializeMemoryPool(pool);
  while (stillRunning)
  {
    fputs(PROMPT, stdout);
    stillRunning = GetAndExecuteCommand(pool, stdin);
  }
  return 0;
}
