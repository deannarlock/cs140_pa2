Last name of Student 1: Narlock
First name of Student 1: Dean
Email of Student 1: deannarlock@ucsb.edu
Last name of Student 2:
First name of Student 2:
Email of Student 2:


----------------------------------------------------------------------------
Report for Question 1 
How is the code parallelized?

 - The code is parallelized by dividing the tosses across the threads in the statement #pragma omp parallel for
 - Since there is no workload difference as i iterates, the default scheduling is used.
 - Since all threads write to x,y and distance_squared, we make these variables private to ensure
   there is no data race. This is the private(x,y,distance_squared) statement
 - Because each thread will accumulate their own sum value, we need to combine the final result to
   get the grand total amongst all threads. This is done with reduction(+ : sum)
 - To set the number of threads to the input parameter we use num_threads(threadcnt)

----------------------------------------------------------------------------
Report for Question 2 
How is the code parallelized?
 - The code is parallelized by 1 of 3 possible schedulings. This can be decided at runtime by the input
   parameter. This is the three initial if statements
 - We set the number of threads to the input parameter with num_threads(threadcnt)
 - Since the cash line size is no bigger than the size of a double, we don't need to worry about making
   vector_y private
 - The parallel code divides the rows of matrix A amongst the threads and multiplies by vector x. The result    is stored in vector y in the index according to the row. 

----------------------------------------------------------------------------
Parallel time/speedup/efficiency using 2 and 4 cores under different scheduling methods

n=4k t=1k BLOCK_MAPPING:
 - Sequential time (1 core): 27.304 sec
 - Parallel time (2 cores): 20.353 sec
 - Parallel time (4 cores): 11.831 sec

n=4k t=1k BLOCK_CYCLIC (r=1):
 - Sequential time (1 core): 27.286 sec
 - Parallel time (2 cores): 14.245 sec
 - Parallel time (4 cores): 7.405 sec

n=4k t=1k BLOCK_CYCLIC (r=16):
 - Sequential time (1 core): 27.281 sec
 - Parallel time (2 cores): 13.718 sec
 - Parallel time (4 cores): 6.928 sec

n=4k t=1k DYNAMIC (r=16):
 - Sequential time (1 core): 27.310 sec
 - Parallel time (2 cores): 13.816 sec
 - Parallel time (4 cores): 6.940 sec


If there are significant performance differences among different thread scheduling  methods,
provide a short reason.

 - There is a significant amount of more time used for BLOCK_MAPPING. This is most likely because the
   speed in which each core executes is different.
 - Since this scheduling forces each core to take a large block of the iterations regardles of the
   speed of that core, the entire program will only run as fast as the slowest core.
 - Dynamic is the fastest because it gives each thread small chunks of the data and each thread only
   executes another chunk when it has comleted the current chunk. This allows the faster thread to execute
   more iterations of the for loop.


