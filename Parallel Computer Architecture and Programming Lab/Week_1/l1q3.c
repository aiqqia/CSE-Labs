#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char** argv) {
	int x = 7,y = 5;
	MPI_Init(&argc,&argv);
	int size;
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int rank;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	if(rank==0)
		printf("We perform Addition for Rank 0, %d + %d = %d\n",x,y,x+y);
	else if(rank==1)
		printf("We perform Subtraction for Rank 1, %d - %d = %d\n",x,y,x-y);
	else if(rank==2)
		printf("We perform Multiplication for Rank 2, %d * %d = %d\n",x,y,x*y);
	else
		printf("We perform Division for Rank 3, %d / %d = %f\n",x,y,(float)x/y);
	MPI_Finalize();
}