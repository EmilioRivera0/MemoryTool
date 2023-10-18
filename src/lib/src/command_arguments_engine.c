// necessary libraries -------->
#include "../include/command_arguments_engine.h"

// local functions -------->
// function to check if a c-string is an integer
bool is_integer(char* str){
  int it = 1;
  const int len = strlen(str);
  while (it<=len) {
    if (!isdigit(*str))
      return false;
    str++;
    it++;
  }
  return true;
}

// functions definition -------->
void arguments_engine(const int argc, char**argv, struct Parameters*params){
  // skip program command
  argv++;
  // no arguments specified
  if (argc == 1){
    printf("\nIndicate PID.\n\n");
    PROGRAM_ERROR
  }
  // only one argument specified
  else if (argc == 2) {
    printf("\nargc == 2\n");
    // check if it is an integer and save it as the target pid params struct 
    if (is_integer(*argv)){
      params->a_pid = true;
      params->pid = atoi(*argv);
    }
    else{
      printf("\nIncorrect PID format.\n\n");
      PROGRAM_ERROR
    }
  }
  // multiple arguments specified
  else{
    printf("\nargc > 2\n");
    // iterate through parameters
    for (short int it = 1; it<argc; it++) {
      // will only accept arguments that start with a '-' preceded by a character
      if (**argv == '-' && strlen(*argv) == 2){
        // skip '-' character
        (*argv)++;
        switch (**argv) {
          // PID argument
          case 'p':
            params->a_pid = true;
            // move to next argument to get the PID
            argv++;
            if (is_integer(*argv))
              params->pid = atoi(*argv);
            else{
              printf("\nArgument \"%s\" is not a PID\n\n", *argv);
              PROGRAM_ERROR
            }
            it++;
          break;

          //invalid argument
          default:
            printf("\nIncorrect format in \"%s\" argument\n\n", --(*argv));
            PROGRAM_ERROR
            break;
        }
      }
      // incorrect argument format
      else{
        printf("\nIncorrect format in \"%s\" argument\n\n", *argv);
        PROGRAM_ERROR
      }
      // move to next argument
      argv++;
    }
  }
}
