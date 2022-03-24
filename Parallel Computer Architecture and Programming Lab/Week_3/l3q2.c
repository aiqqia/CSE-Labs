#include <mpi/mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argv, char *argc[]){
	int rank, size, *numbers, *array, result, m;

	MPI_Init(&argv, &argc);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	
	if (rank == 0){
		printf("Enter M: ");
		scanf("%d", &m);
		numbers = (int *)calloc(size * m, sizeof(int));
		printf("Enter %d number(s): ", size * m);
		for (int i = 0; i < size * m; i++)
			scanf("%d", &numbers[i]);
	}

	MPI_Bcast(&m, 1, MPI_INT, 0, MPI_COMM_WORLD);

	array = (int *)calloc(m, sizeof(int));

	MPI_Scatter(numbers, m, MPI_INT, array, m, MPI_INT, 0, MPI_COMM_WORLD);
	
	int sendResult = 0;
	for (int i = 0; i < m; i++)
		sendResult += array[i];

	sendResult /= m;
	
	MPI_Reduce(&sendResult, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
	
	if (rank == 0){
		printf("The average is : %d\n", result / size);
		free(numbers);
	}
	free(array);
	MPI_Finalize();
	return 0;
}