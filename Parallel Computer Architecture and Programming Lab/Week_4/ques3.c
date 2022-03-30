#include <stdio.h>
#include <mpi/mpi.h>
#include <stdlib.h>

void ErrorHandler(int err_code){
    if(err_code != MPI_SUCCESS){
        char error_string[BUFSIZ];
        int length_err_string, err_class;
        MPI_Error_class(err_code, &err_class);
        MPI_Error_string(err_code, error_string, &length_err_string);
        fprintf(stderr, "Error: %d %s\n", err_class, error_string);
    }
}

int main(int argc, char* argv[]){
    int rank, size, err_code, ele, result;
    int mat[3][3];
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    err_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    err_code = MPI_Comm_size(MPI_COMM_WORLD, &size);
    if(rank == 0)
        ErrorHandler(err_code);

    if(rank == 0){
        printf("Enter the elements in 3x3 matrix:\n");
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                scanf("%d",&mat[i][j]);
            }
        }
        printf("Enter element to be searched: ");
        scanf("%d",&ele);
    }
    int sMat[3];
    err_code = MPI_Bcast(&ele, 1, MPI_INT, 0, MPI_COMM_WORLD);
    err_code = MPI_Scatter(mat, 3, MPI_INT, sMat, 3, MPI_INT, 0, MPI_COMM_WORLD);
    int res = 0;
    for(int i=0;i<3;i++){
        if(sMat[i] == ele)
            res++;
    }
    err_code = MPI_Reduce(&res, &result, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    if(rank == 0){
        ErrorHandler(err_code);
        printf("Total number of occurences is: %d\n", result);
    }

    MPI_Finalize();
    exit(0);
}