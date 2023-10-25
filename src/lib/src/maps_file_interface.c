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
  // get second token which stores the memory sector mode
  char* token = strtok(line_buffer," ");
  token = strtok(NULL, " ");
  // remove '\n' character from previous token
  *(token-1) = ' ';
  // remove '\n' character from current token
  *(token+4) = ' ';
  // check if the 'w' flag is set, meaning it is a writable memory sector
  if (*(token+1) == 'w')
    return true;
  return false;
}

struct Memory_Sector* initialize_memory_sector_struct(char* line_buffer){
  long int start = 0, end = 0;
  size_t name_len = 0;
  // get starting memory sector address
  char* token = strtok(line_buffer, "-");
  char* name = NULL;
  struct Memory_Sector* mem_sec = malloc(sizeof(struct Memory_Sector));

  // initialize starting memory address
  sscanf(token, "%p", &mem_sec->start);
  sscanf(token, "%lx", &start);
  // get ending memory sector address
  token = strtok(NULL, " ");
  // initialize ending memory address
  sscanf(token, "%p", &mem_sec->end);
  sscanf(token, "%lx", &end);
  // initialize memory sector size
  mem_sec->size = end - start;
  // jump until last token to initialize memory sector name
  strtok(NULL, " ");
  strtok(NULL, " ");
  strtok(NULL, " ");
  strtok(NULL, " ");
  token = strtok(NULL, " ");
  // initialize memory sector name
  name_len = strlen(token);
  if (name_len > 1){
    name_len--;
    // remove '\n' character at the end of the token
    *(token+name_len) = '\0';
    mem_sec->name = malloc(name_len);
    memcpy(mem_sec->name, token, name_len);
  }
  // no name
  else{
    name_len = strlen("<No Name>");
    mem_sec->name = malloc(name_len);
    mem_sec->name = "<No Name>\0";
  }
  mem_sec->next = NULL; 

  return mem_sec;
}

void push_mem_sec(struct Memory_Sector* ms, struct Program_Data* pd){
  struct Memory_Sector* front = NULL;
  struct Memory_Sector* back = NULL;

  if (pd->memory_sectors == NULL)
    pd->memory_sectors = ms;
  else{
    front = pd->memory_sectors;
    while (front != NULL) {
      back = front;
      front = front->next;
    }
    back->next = ms;
  }
}

void get_memory_addresses(struct Program_Data* pd){
  // maps file content format
  //<address start>-<address end>  <mode>  <offset>   <major id:minor id>   <inode id>   <file path>  
  //559b8c418000-559b8c41a000      r--p    00000000          08:30               1708     /usr/bin/cat
  char line_maps[MAPS_LINE_BUFFER];
  char* token = NULL;
  FILE* file_maps = NULL;
  
  // initialize memory sectors to NULL
  pd->memory_sectors = NULL;

  // open maps file
  file_maps = open_maps_file(pd->pid);

  // iterate through maps file searching for writable memory sections
  while (fgets(line_maps, MAPS_LINE_BUFFER, file_maps) != NULL) {
    if (is_writable(line_maps)) {
      push_mem_sec(initialize_memory_sector_struct(line_maps), pd);
    }
    // clear line buffer content
    memset(line_maps, '\0', MAPS_LINE_BUFFER);
  }
  fclose(file_maps);
}
