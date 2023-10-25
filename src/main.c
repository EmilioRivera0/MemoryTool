// necessary libraries -------->
#include "lib/include/command_arguments_engine.h"
#include "lib/include/maps_file_interface.h"
#include "lib/include/memory_tool.h"

// program execution -------->
int main(int argc, char **argv){
  // program variables
  struct Program_Data pd;
  arguments_engine(argc, argv, &pd);
  get_memory_addresses(&pd);
  memory_IO(&pd);
  return 0;
}
