// run with
//   gcc mem.c -lpthread
//   setarch `uname -m` -R a.out 

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "common.h"

int main(int argc, char *argv[])
{
  int *p;           // memory for pointer is on "stack"
  p = malloc(sizeof(int));  // malloc'd memory is on "heap"
  assert(p != NULL);

  int myid = (int) getpid();
  printf("(pid:%d) addr of p:    %p\n", myid, &p);
  printf("(pid:%d) addr stored in p: %p\n", myid, p);
  printf("(pid:%d) addr of main  %p\n", myid, &main);
  sleep(5);

  return 0;
}

