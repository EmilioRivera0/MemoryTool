#ifndef MAPS_FILE_INTERFACE_H
#define MAPS_FILE_INTERFACE_H

// necessary libraries -------->
#include <stdio.h>
#include <string.h>
#include <errno.h>

#include "macros.h"
#include "structs.h"

// macros definition -------->
#define FILE_PATH_BUFFER_SIZE 17
#define MAPS_LINE_BUFFER 151

// functions declaration -------->
FILE* open_maps_file(pid_t);
bool is_writable(char*);
void get_memory_addresses(struct Parameters*);

#endif // !MAPS_FILE_INTERFACE_H
