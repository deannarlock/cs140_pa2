#CC      = icc
CC      = gcc
CFLAGS  =   -O -fopenmp 
LDFLAGS  =  -lm
NUMTHREADS = 8
#CFLAGS  =  -O -DDEBUG1 -g

OBJECTS=pi_mc_test_omp.o pi_mc_omp.o minunit.o
OBJECTS1= itmv_mult_omp.o itmv_mult_test_omp.o  minunit.o 

TARGET= pi_mc_test_omp itmv_mult_test_omp

all:  $(TARGET)

pi_mc_test_omp: $(OBJECTS) minunit.h 
	$(CC) -o $@ $(OBJECTS) $(LDFLAGS) $(CFLAGS)

itmv_mult_test_omp: $(OBJECTS1) itmv_mult_omp.h minunit.h 
	$(CC) -o $@ $(OBJECTS1) $(LDFLAGS) $(CFLAGS)

status:
	squeue -u `whoami`

run-pi_mc_test_omp:
	export OMP_NUM_THREADS=$(NUMTHREADS)
	./pi_mc_test_omp $(NUMTHREADS)

run-itmv_mult_test_omp:
	export OMP_NUM_THREADS=$(NUMTHREADS)
	./itmv_mult_test_omp $(NUMTHREADS)

.c.o: 
	$(CC)  $(CFLAGS) -c $<

clean:
	rm  *.o $(TARGET) test

cleanlog:
	rm  job*.out


test: 
	$(CC) -o test test.c $(LDFLAGS) $(CFLAGS)

run-test:
	export OMP_NUM_THREADS=$(NUMTHREADS)
	./test $(NUMTHREADS)
