// necessary libraries -------->
#include "../include/maps_file_interface.h"

// functions definition -------->
FILE* open_maps_file(pid_t pid){
  int ret_val = 0;
  char filepath[FILE_PATH_BUFFER_SIZE];
  FILE* maps_file = NULL;
  
  // clean buffer memory
  memset(filepath, '\0', FILE_PATH_BUFFER_SIZE);
  // set filepath
  sprintf(filepath, "/proc/%d/maps", pid);
  // open maps file in read mode
  maps_file = fopen(filepath, "r");
  // check for errors
  if (maps_file == NULL){
    printf("\nProcess %d does not exist\n%s\n\n", pid, strerror(errno));
    PROGRAM_ERROR
  }
  return maps_file;
}

bool is_writable(char* line_buffer){
  return true;
}

void get_memory_addresses(struct Parameters* params){
  // maps file content format
  //<address start>-<address end>  <mode>  <offset>   <major id:minor id>   <inode id>   <file path>  
  //559b8c418000-559b8c41a000      r--p    00000000          08:30               1708     /usr/bin/cat
  char line_maps[MAPS_LINE_BUFFER];
  FILE* file_maps = NULL;
  
  // open maps file
  file_maps = open_maps_file(params->pid);

  // iterate through maps file searching for writable memory sections
  while (!feof(file_maps)) {
    // clear line buffer content
    memset(line_maps, '\0', MAPS_LINE_BUFFER);
    fgets(line_maps, MAPS_LINE_BUFFER, file_maps);
    printf("%s", line_maps);
  }
  // temporal structure to store all lines containing writable sections of code information
  // change Parameters struct to ProgramData struct
  // then make user pick at least one section and store the addresses of the selected sections into the metadata struct
}
