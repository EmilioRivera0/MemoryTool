#ifndef MEMORY_TOOL_H
#define MEMORY_TOOL_H

// necessary libraries -------->
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <sys/uio.h>
#include <sys/types.h>

#include "structs.h"
#include "macros.h"

// macro definition -------->
#define MAX_USER_INPUT_LEN 100

// functions declaration -------->
short int memory_menu(struct Program_Data*);
struct iovec* initialize_remote_iovec(struct Program_Data*, const short int);
void memory_IO(struct Program_Data*);
bool is_whole_number(char*);
bool is_decimal_number(char*);
short int str_len(char*);

/* 
 * function declaration copied from <bits/uio-ext.h>
 * I needed to include it because the language server was constantly generating undeclared function errors
 * this was done just for developing purposes, the compilation and execution were not afected by this small 
 * error of the language server 
*/
extern ssize_t process_vm_readv (pid_t, const struct iovec *,
				 unsigned long int,
				 const struct iovec *,
				 unsigned long int,
				 unsigned long int)
  __THROW;

#endif // !MEMORY_TOOL_H
