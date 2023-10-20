// necessary libraries -------->
#include "lib/include/command_arguments_engine.h"
#include "lib/include/maps_file_interface.h"

// program execution -------->
int main(int argc, char **argv){
  // program variables
  struct Parameters params;
  arguments_engine(argc, argv, &params);
  get_memory_addresses(&params);
  return 0;
}
