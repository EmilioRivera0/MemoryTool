#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  int var = 22;
  char ph;
  printf("PID %d\nValue %d\nAddress %p\nSize %ld\n", getpid(), var, &var, sizeof(var));
  scanf("%c", &ph);
  while (1) {
    scanf("%d", &var);
    printf("var modified\n");
  }
  return 0;
}
