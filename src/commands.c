#include "commands.h"

bool GetAndExecuteCommand(char *pool, FILE *stream)
{
  bool stillRunning = true;
  // Read in the next command.
  char command;
  fscanf(stream, "%c", &command);
  // Execute the command.
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
  // Throw away the rest of the line.
  while (fgetc(stream) != '\n');
  return stillRunning;
}

void ExecuteAllocate(char *pool, FILE *stream)
{
  // Read in the arguments of allocation.
  char process;
  int size;
  char policy;
  fscanf(stream, " %c %d %c", &process, &size, &policy);
  // Find the block to allocate to.
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
  // Ensure a block was found.
  if (!block)
  {
    fprintf(stderr,
            "Unable to find a free block of size %d for process '%c'.\n",
            size, process);
    return;
  }
  // Allocate that block to the process.
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
  // stream isn't used as there are no arguments for show.
  UNUSED(stream);
  PrintMemoryPool(pool);
}

bool ExecuteRead(char *pool, FILE *stream)
{
  bool stillRunning = true;
  // Open the file.
  char filename[MAX_FILENAME_LEN + 1];
  fscanf(stream, " %s", filename);
  FILE *file = fopen(filename, "r");
  // Execute each line in the file.
  while (stillRunning && !feof(file))
  {
    stillRunning = GetAndExecuteCommand(pool, file);
  }
  fclose(file);
  return stillRunning;
}

void ExecuteCompact(char *pool, FILE *stream)
{
  // stream isn't used as there are no arguments for compact.
  UNUSED(stream);
  CompactMemoryPool(pool);
}
