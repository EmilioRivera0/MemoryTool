// necessary libraries -------->
#include "../include/memory_tool.h"

// functions definition -------->
short int memory_menu(struct Program_Data* pd){
  short int op = 0, count = 1;
  struct Memory_Sector* temp = pd->memory_sectors;
  // show all the writable memory sectors and ask the user to choose one to work with
  printf("\n");
  while (temp != NULL) {
    printf("%d. %s \n\t%p - %p\n\tSize: %ld Bytes \n", count, temp->name, temp->start, temp->end, temp->size);
    count++;
    temp = temp->next;
  }
  printf("0. Exit\n");
  printf("\nOption> ");
  scanf(" %hd", &op);
  return op;
}


bool is_whole_number(char* str){
  while (*str != '\0') {
    if (!isdigit(*str))
      return false;
    str++;
  }
  return true;
}

bool is_decimal_number(char* str){
  while (*str != '\0') {
    if (!isdigit(*str) && *str!='.')
      return false;
    str++;
  }
  return true;
}

short int str_len(char* str){
  short int len = 0;
  while (*str != '\0') {
    len++;
    str++;
  }
  return len;
}

struct iovec* initialize_remote_iovec(struct Program_Data* pd, const short int op){
  short int it = 1;
  struct iovec* remote_iovec = (struct iovec*)malloc(sizeof(struct iovec));
  struct Memory_Sector* mem_sec = pd->memory_sectors;
  
  // move mem_sec to the Memory_Sector struct that the user specified
  while (it < op){
    mem_sec = mem_sec->next;
    it++;
  }
  // initialize remote iovec with chosen memory sector
  remote_iovec->iov_base = mem_sec->start;
  remote_iovec->iov_len = mem_sec->size;

  return remote_iovec;
}

void memory_IO(struct Program_Data* pd){
  short int op = 0;
  ssize_t transfered_bytes = 0;
  char usr_input[MAX_USER_INPUT_LEN];
  // declare struct for remote iovec and declare and allocate memory space for local iovec struct
  struct iovec* remote_mem_sec = NULL;
  struct iovec* local_mem_sec = malloc(sizeof(struct iovec));
  
  while (true) {
    op = memory_menu(pd);
    // check if exit option was chosen
    if (op == 0)
      break;
    // initialize remote iovec from the chosen memory sector of target process
    remote_mem_sec = initialize_remote_iovec(pd, op);
    // initialize local iovec struct based on the remote iovec data
    // allocate space for the buffer that will store the memory readed from the remote process
    local_mem_sec->iov_base = malloc(remote_mem_sec->iov_len);
    local_mem_sec->iov_len = remote_mem_sec->iov_len;
    // read the remote process memory sector and store it in the allocated buffer
    transfered_bytes = process_vm_readv(pd->pid, local_mem_sec, 1, remote_mem_sec, 1, 0);
    // check if bytes were transfered
    if (transfered_bytes <= 0) {
      printf("Program failed to read process %d memory: %s\n\n", pd->pid, strerror(errno));
      PROGRAM_ERROR
    }
    printf("\nRemote Process Memory Copied Successfully Into Program's Buffer\n\n");
    // clean usr_input array content
    memset(usr_input, '\0', MAX_USER_INPUT_LEN);
    // ask for user to input the value to search for in the buffer
    printf("Indicate the value to search for (Rational Numbers/Character/String):\n\n\nValue > ");
    scanf(" %s", usr_input);
    printf("%s", usr_input);

    // free allocated memory from heap
    free(remote_mem_sec);
    free(local_mem_sec->iov_base);
  }
}
