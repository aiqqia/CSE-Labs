#include <mpi/mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    if (rank == 0){
        int array[size-1];
        printf("Enter %d elements : ", size-1);
        for(int i = 0; i<size-1; i++){
            scanf("%d", &array[i]);
        }
        int buffer_size = MPI_BSEND_OVERHEAD + sizeof(int)*size-1;
        char *buffer = (char*)malloc(buffer_size);
        MPI_Buffer_attach(buffer, buffer_size);
        for(int i = 0; i<size-1; i++){
            MPI_Bsend(&array[i], 1, MPI_INT, i+1, i+1, MPI_COMM_WORLD);
        }
        MPI_Buffer_detach(&buffer, &buffer_size);
    }
    else{
        int num;
        MPI_Recv(&num, 1, MPI_INT, 0, rank, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        if (rank & 1){
            printf("In process : %d, number of array : %d, cube value : %d\n", rank, num, num * num * num);
        }
        else{
        printf("In process : %d, number of array : %d, square value : %d\n", rank, num, num * num);
        }
    }
    MPI_Finalize();
    return 0;
}