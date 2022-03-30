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
    int rank, size, err_code, N;
    float result = 0.0, res = 0.0, sres = 0.0;
    MPI_Init(&argc, &argv);
    MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
    err_code = MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    err_code = MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 0){
        ErrorHandler(err_code);
        printf("Enter the number of terms: ");
        scanf("%d",&N);
    }
    err_code = MPI_Bcast(&N, 1, MPI_INT, 0, MPI_COMM_WORLD);
    for (int i = rank; i < N; i += size){
        res = (i + 0.5)/N;
        res = (1 + res*res)*N;
        res = 4/res;
        sres += res;
        res = 0.0;
    }

    err_code = MPI_Reduce(&sres, &result, 1, MPI_FLOAT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0){
        ErrorHandler(err_code);
        printf("The value of Pi is: %f\n", result);
    }

    MPI_Finalize();
    exit(0);
}