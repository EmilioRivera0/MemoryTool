#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  /*
  int var = 22;
  char ph;
  printf("PID %d\nValue %d\nAddress %p\nSize %ld\n", getpid(), var, &var, sizeof(var));
  scanf("%c", &ph);
  while (1) {
    scanf("%d", &var);
    printf("var modified\n");
  }
  */
  char temp[] = "7f224b7b2000-7f224b7b3000 rw-p 0008f000 08:02 18114552                   /usr/lib/libluajit-5.1.so.2.1.1696795921";
  printf("%lu",strlen(temp));
  return 0;
}
