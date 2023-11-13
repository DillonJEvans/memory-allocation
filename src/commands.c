#include "commands.h"

bool GetAndExecuteCommand(char *pool, FILE *stream)
{
  bool stillRunning = true;
  char command;
  fscanf(stream, "%c", &command);
  switch (command)
  {
    case 'A':
      ExecuteAllocate(pool, stream);
      break;
    case 'F':
      ExecuteFree(pool, stream);
      break;
    case 'S':
      ExecuteShow(pool, stream);
      break;
    case 'R':
      stillRunning = ExecuteRead(pool, stream);
      break;
    case 'C':
      ExecuteCompact(pool, stream);
      break;
    case 'E':
      return false;
    default:
      fprintf(stderr, "Invalid command '%c'.\n", command);
      break;
  }
  while (fgetc(stream) != '\n');
  return stillRunning;
}

void ExecuteAllocate(char *pool, FILE *stream)
{
  char process;
  int size;
  char policy;
  fscanf(stream, " %c %d %c", &process, &size, &policy);
  char *block = NULL;
  switch (policy)
  {
    case 'F':
      block = FirstFit(pool, size);
      break;
    case 'B':
      block = BestFit(pool, size);
      break;
    case 'W':
      block = WorstFit(pool, size);
      break;
    default:
      fprintf(stderr, "Invalid allocation policy '%c'.\n", policy);
      return;
  }
  if (!block)
  {
    fprintf(stderr, "Unable to find a free block of size %d.\n", size);
    return;
  }
  AllocateMemoryBlock(block, size, process);
}

void ExecuteFree(char *pool, FILE *stream)
{
  char process;
  fscanf(stream, " %c", &process);
  FreeProcess(pool, process);
}

void ExecuteShow(char *pool, FILE *stream)
{
  UNUSED(stream);
  PrintMemoryPool(pool);
}

bool ExecuteRead(char *pool, FILE *stream)
{
  bool stillRunning = true;
  char filename[MAX_FILENAME_LEN + 1];
  fscanf(stream, " %s", filename);
  FILE *file = fopen(filename, "r");
  while (stillRunning && !feof(file))
  {
    stillRunning = GetAndExecuteCommand(pool, file);
  }
  fclose(file);
  return stillRunning;
}

void ExecuteCompact(char *pool, FILE *stream)
{
  UNUSED(stream);
  CompactMemoryPool(pool);
}
