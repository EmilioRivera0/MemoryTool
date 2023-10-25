#ifndef STRUCTS_H
#define STRUCTS_H

// necessary libraries -------->
#include <stdbool.h>
#include <stddef.h>
#include <unistd.h>

// structs declaration -------->
struct Memory_Sector{
  char* name;
  size_t size;
  void* start;
  void* end;
  struct Memory_Sector* next;
};

struct Program_Data{
  // PID argument
  bool a_pid;
  pid_t pid;
  struct Memory_Sector* memory_sectors;
};



#endif // !STRUCTS_H
