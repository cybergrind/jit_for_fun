#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>

#include <time.h>
#include <sys/time.h>


int my_pow(int source){
  return source*source;
}

void timeit(int (*f)(int)){
  struct timespec start, end;
  double d;
  clock_gettime(CLOCK_MONOTONIC, &start);
  for (long i=0; i<1000000000; i++){
    f(9);
  }
  clock_gettime(CLOCK_MONOTONIC, &end);
  d = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1000000000.0;
  printf("Total time: %f\n", d);
}

int main(){
  printf("asdfasdf\n");
  
  unsigned int size = 1024;
  void* buff = mmap(NULL, size, (PROT_READ|PROT_WRITE|PROT_EXEC),
                   (MAP_PRIVATE|MAP_ANONYMOUS), -1, 0);
  
  printf("MMAP %p\n", buff);
  // char code[] = {0x55, 0x48, 0x89, 0xe5, // push rbp, mov %rsp, %rbp
  //                0x89, 0x7d, 0xfc, 0x8b, 0x7d, 0xfc,
  //                0x0f, 0xaf, 0x7d, 0xfc,
  //                0x89, 0xf8,
  //                0x5d, 0xc3, 0xf8}; // pop rbp, retq
  
  //char code[] = {0x89, 0x7c, 0x24, 0x28, 0x0f, 0xaf, 0x7c, 0x24, 0x28, 0x89, 0xf8, 0xc3};

  // mov 
  char code[] = {0x89, 0xf8, 0x0f, 0xaf, 0xc0, 0xc3};
  
  memcpy(buff, code, sizeof(code));

  int (*func)(int) = buff;
  printf("FUNC: %i\n", (unsigned) func(9));
  printf("Mypow: %i\n", my_pow(9));
  char* c = (char*)(my_pow);

  for (int i=0; i>-1; i++){
    void* currp = (*my_pow)+i*8;
    printf("Char: %x\n", (short int)currp);
    i=-2;
  }

  timeit(func);
  timeit(my_pow);
  
  return 0;
}
