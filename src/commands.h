#ifndef COMMANDS_H_
#define COMMANDS_H_

#include <stdio.h>
#include <stdbool.h>

#include "policies.h"
#include "memory_pool.h"

#define MAX_FILENAME_LEN (256)

#define UNUSED(variable) ((void) (variable))

bool GetAndExecuteCommand(char *pool, FILE *stream);

void ExecuteAllocate(char *pool, FILE *stream);

void ExecuteFree(char *pool, FILE *stream);

void ExecuteShow(char *pool, FILE *stream);

bool ExecuteRead(char *pool, FILE *stream);

void ExecuteCompact(char *pool, FILE *stream);

#endif // COMMANDS_H_
