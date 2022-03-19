#include <mpi/mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
	int rank, size, num;
	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	if(rank == 0){
		for(int i = 1; i<size; i++){
			MPI_Send(&i, 1, MPI_INT, i, i, MPI_COMM_WORLD);
		}
	}
	else{
		MPI_Recv(&num, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE );
		printf("In process %d, number sent is %d\n", rank, num);
	}
	MPI_Finalize();
	return 0;
}