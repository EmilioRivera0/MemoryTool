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
struct Memory_Sector* initialize_memory_sector_struct(char*);
void push_mem_sec(struct Memory_Sector*, struct Program_Data*);
void get_memory_addresses(struct Program_Data*);

#endif // !MAPS_FILE_INTERFACE_H
