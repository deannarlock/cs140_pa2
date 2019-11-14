#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]) {
  int threadcnt = atoi(argv[1]);
  //omp_set_num_threads(num_threads);

  int x[threadcnt] = { 0 };

  for (int i = 0; i < threadcnt; i++) {
    printf("i = %i, x[%i] = %i\n", i, i, x[i]);
  }
  
  /*#pragma omp parallel private(x) num_threads(threadcnt)
  {
    //printf("Thread: %i\n", omp_get_thread_num() );

    x += omp_get_thread_num() + 1;
    printf("Thread: %i\n", x);
  }

  */



  
#pragma omp parallel for
  for (int i = 0; i < 20; i++) {
    x[omp_get_thread_num()]++;
    printf("Thread: %i, i=%i\n", omp_get_thread_num(), x);
  }
  printf("%i\n", x);
  
  return 0;
}
