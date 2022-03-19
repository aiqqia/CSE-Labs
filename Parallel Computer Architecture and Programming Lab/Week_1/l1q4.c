#include "mpi.h"
#include <stdio.h>

char* toggle(char str[], int rank){
    if(str[rank] >= 'a' && str[rank] <= 'z'){
        str[rank] -= 32;
    }
    else if(str[rank] >= 'A' && str[rank] <= 'Z'){
        str[rank] += 32;
    }
    return str;
}

int main(int argc, char *argv[])
{
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    char str[] = "HeLLO";
    char printStr[] = "HeLLO";
    printf("Input is : %s, Rank : %d, Output : %s\n", printStr, rank, toggle(str, rank));

    MPI_Finalize();
    return 0;
}