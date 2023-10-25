// necessary libraries -------->
#include "../include/memory_tool.h"

// functions definition -------->
short int memory_menu(struct Program_Data* pd){
  short int op = 0, count = 1;
  struct Memory_Sector* temp = pd->memory_sectors;
  // show all the writable memory sectors and ask the user to choose one to work with
  while (temp != NULL) {
    printf("%d. %s \n\tSize:%ld Bytes \n", count, temp->name, temp->size);
    count++;
    temp = temp->next;
  }
  printf("0. Exit\n");
  printf("\nOption> ");
  scanf(" %hd", &op);
  return op;
}

struct iovec* initialize_remote_iovec(struct Program_Data* pd, const short int op){
  short int it = 1;
  struct iovec* remote_iovec = NULL;
  struct Memory_Sector* mem_sec = pd->memory_sectors;
  
  // move mem_sec to the Memory_Sector struct that the user specified
  while (it < op){
    mem_sec = mem_sec->next;
    it++;
  }

  return remote_iovec;
}

void memory_IO(struct Program_Data* pd){
  short int op = 0;
  struct iovec* remote_mem_sec = NULL;
  
  while (true) {
    op = memory_menu(pd);
    // check if exit option was chosen
    if (op == 0)
      break;
    // initialize remote iovec from the chosen memory sector of target process
    remote_mem_sec = initialize_remote_iovec(pd, op);
  }
}
