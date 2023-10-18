#ifndef MEM_READ_H
#define MEM_READ_H
// necessary libraries -------->
#define __USE_GNU 
#include <sys/uio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

// functions declaration -------->
void read(void);
extern ssize_t process_vm_readv (pid_t __pid, const struct iovec *__lvec,
				 unsigned long int __liovcnt,
				 const struct iovec *__rvec,
				 unsigned long int __riovcnt,
				 unsigned long int __flags)
  __THROW;

#endif // !MEM_READ_H
