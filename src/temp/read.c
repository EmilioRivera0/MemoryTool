// necessary libraries -------->
#include "../include/read.h"

// functions definition -------->
void read(){
  int* var_ptr;
  int bytes_transfered;
  pid_t pid;
  char ph;
  struct iovec local;
  struct iovec remote;

  local.iov_base = malloc(4);
  local.iov_len = 4;
  remote.iov_len = 4;

  scanf("%d", &pid);
  printf("Target PID %d\n", pid);
  scanf("%p", &var_ptr);
  printf("Address %p\n", var_ptr);

  remote.iov_base = var_ptr;
  while (1) {
    bytes_transfered = process_vm_readv(pid, &local, 1, &remote, 1, 0);
    printf("Bytes Readed %d\n", bytes_transfered);
    if (bytes_transfered > 0)
      printf("Value of remote var %d\n", *(int*)local.iov_base);
    scanf("%c", &ph);
  }


}
