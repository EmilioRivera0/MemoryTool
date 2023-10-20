#ifndef STRUCTS_H
#define STRUCTS_H

// necessary libraries -------->
#include <stdbool.h>
#include <unistd.h>

// structs declaration -------->
struct Parameters{
  // PID argument
  bool a_pid;
  pid_t pid;
};

#endif // !STRUCTS_H
