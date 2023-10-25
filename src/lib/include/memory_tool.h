#ifndef MEMORY_TOOL_H
#define MEMORY_TOOL_H

// necessary libraries -------->
#include <stdio.h>

#include "structs.h"
#include "macros.h"

// functions declaration -------->
short int memory_menu(struct Program_Data*);
struct iovec* initialize_remote_iovec(struct Program_Data*, const short int);
void memory_IO(struct Program_Data*);

#endif // !MEMORY_TOOL_H
