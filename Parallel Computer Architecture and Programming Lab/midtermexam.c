#include <stdio.h>
#include <stdlib.h>
#include <mpi/mpi.h>

int main(int argc, char* argv[]){
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    
    int arr[size], x;
    if(rank == 0){
        printf("Enter shuffled numbers[0-3]: ");
        for(int i=0;i<size;i++){
            scanf("%d",&arr[i]);
        }
    }
    MPI_Scatter(arr, 1, MPI_INT, &x, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d has received value: %d\n", rank, x);
    int rand = (50*(rank+1)+size);
    printf("Process %d has generated a new random value: %d\n", rank, rand);

    /// Following code works in case of Collective Communication but we were asked to do rest in Point to Point

    // int ran[4], farr[4];
    // MPI_Gather(&rand, 1, MPI_INT, ran, 1, MPI_INT, 0, MPI_COMM_WORLD);
    // if(rank == 0){
    //     printf("Random numbers generated are: ");
    //     for(int i=0;i<size;i++){
    //         printf("%d ", ran[i]);
    //     }
    //     printf("\n");
    //     for(int i=0;i<size;i++){
    //         farr[i] = ran[i] + arr[arr[i]];
    //     }
    //     printf("Final Output Array is: ");
    //     for(int i=0;i<size;i++){
    //         printf("%d ", farr[i]);
    //     }
    //     printf("\n");
    // }

    /// Using Point to Point Communication

    int ran[4], r;

    if(rank != 0){
        MPI_Send(&rand, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
    }
    else{
        ran[0] = rand;
        for(int i=1;i<size;i++){
            MPI_Recv(&r, 1 , MPI_INT, i, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            ran[i] = r;
        }
        printf("Random numbers are: ");
        for(int i=0;i<size;i++){
            printf("%d ", ran[i]);
        }
        printf("\n");
    }


    MPI_Finalize();
    return 0;
}