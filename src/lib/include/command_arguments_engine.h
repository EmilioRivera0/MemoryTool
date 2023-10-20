#ifndef COMMAND_ARGUMENTS_ENGINE_H
#define COMMAND_ARGUMENTS_ENGINE_H

// necessary libraries -------->
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "macros.h"
#include "structs.h"

// functions declaration -------->
void arguments_engine(const int, char**, struct Parameters*);

#endif // !COMMAND_ARGUMENTS_ENGINE_H
