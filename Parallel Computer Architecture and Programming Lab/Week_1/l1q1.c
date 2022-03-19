#include "mpi.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
	int rank;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	double ans = pow(5,rank);
	printf("My rank is %d and pow(5,rank) is: %lf\n", rank, ans);
	MPI_Finalize();
	return 0;
}