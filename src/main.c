// necessary libraries -------->
#include "lib/include/command_arguments_engine.h"

// program execution -------->
int main(int argc, char **argv){
  // program variables
  struct Parameters params;
  arguments_engine(argc, argv, &params);
  return 0;
}
