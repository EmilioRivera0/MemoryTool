#ifndef COMMAND_ARGUMENTS_ENGINE_H
#define COMMAND_ARGUMENTS_ENGINE_H

// necessary libraries -------->
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "macros.h"

// functions declaration -------->
struct Parameters{
  // PID argument
  bool a_pid;
  pid_t pid;
};

// functions declaration -------->
void arguments_engine(const int, char**, struct Parameters*);

#endif // !COMMAND_ARGUMENTS_ENGINE_H
