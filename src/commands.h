#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include <stdbool.h>

#include "policies.h"
#include "memory_pool.h"

#define MAX_FILENAME_LEN (256)

#define UNUSED(variable) ((void) (variable))

// Gets and executes the next command from the stream.
// Returns true if the program should continue running, false otherwise.
bool GetAndExecuteCommand(char *pool, FILE *stream);

// Allocates a block to a process.
// The process, block size, and allocation policy are read from the stream.
void ExecuteAllocate(char *pool, FILE *stream);

// Frees all blocks allocated to a process.
// The process to free is read from the stream.
void ExecuteFree(char *pool, FILE *stream);

// Prints the memory pool.
void ExecuteShow(char *pool, FILE *stream);

// Reads and executes commands from a file.
// The name of the file to open is read from the stream.
// Returns true if the program should continue running, false otherwise.
bool ExecuteRead(char *pool, FILE *stream);

// Compacts the memory pool.
void ExecuteCompact(char *pool, FILE *stream);

#endif // COMMANDS_H_
