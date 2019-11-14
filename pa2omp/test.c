#include <omp.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[]) {
  int threadcnt = atoi(argv[1]);
  //omp_set_num_threads(num_threads);

  int x = 0;;
  
  /*#pragma omp parallel private(x) num_threads(threadcnt)
  {
    //printf("Thread: %i\n", omp_get_thread_num() );

    x += omp_get_thread_num() + 1;
    printf("Thread: %i\n", x);
  }

  */


  int y = ceil(16.0/threadcnt);
  printf("%i\n", y);
  
#pragma omp parallel for num_threads(threadcnt)
  for (int i = 0; i < 16; i++) {
    printf("Thread: %i, i=%i\n", omp_get_thread_num(), i);
  }
  
  return 0;
}
