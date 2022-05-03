// 2. Write a program in CUDA to perform parallel Sparse Matrix - Vector Multiplication 
// using compressed sparse row (CSR) storage format. Represent the input sparse matrix in CSR format
//  in the host code.
#include <cuda.h>
#include <stdio.h>
#include <stdlib.h>

__global__ void SpMV_CSR(int num_rows, int* data, int* col_index, int* row_ptr, int* x, int* y) {
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if (row < num_rows) {
        int dot = 0;
        int start = row_ptr[row];
        int stop = row_ptr[row + 1];
        for (int k = start; k < stop; k++) {
            dot += data[k] * x[col_index[k]];
        }
        y[row] = dot;
    }
}

int main() {
    int n, m;
    printf("Enter dimensions of matrix: ");
    scanf("%d%d", &n, &m);
    int* h_matrix = (int*)malloc(n * m * sizeof(int));
    int non_zero_count = 0;
    printf("Enter elements of matrix:\n");
    for (int i = 0; i < n * m; i++) {
        scanf("%d", h_matrix + i);
        non_zero_count += (h_matrix[i] != 0);
    }
    int* h_x = (int*)malloc(m * sizeof(int));
    printf("Enter %d elements of vector x: ", m);
    for (int i = 0; i < m; i++) {
        scanf("%d", h_x + i);
    }
    int* h_data = (int*)malloc(non_zero_count * sizeof(int));
    int* h_col_index = (int*)malloc(non_zero_count * sizeof(int));
    int* h_row_ptr = (int*)calloc(n + 1, sizeof(int));
    int* h_y = (int*)calloc(n, sizeof(int));
    int id = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int k = i * m + j;
            if (h_matrix[k]) {
                h_data[id] = h_matrix[k];
                h_col_index[id] = j;
                id += 1;
            }
        }
        h_row_ptr[i + 1] = id;
    }

    int *d_data, *d_col_index, *d_row_ptr, *d_x, *d_y;
    cudaMalloc((void**)&d_data, non_zero_count * sizeof(int));
    cudaMalloc((void**)&d_col_index, non_zero_count * sizeof(int));
    cudaMalloc((void**)&d_row_ptr, (n + 1) * sizeof(int));
    cudaMalloc((void**)&d_x, m * sizeof(int));
    cudaMalloc((void**)&d_y, n * sizeof(int));

    cudaMemcpy(d_data, h_data, non_zero_count * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_col_index, h_col_index, non_zero_count * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_row_ptr, h_row_ptr, (n + 1) * sizeof(int), cudaMemcpyHostToDevice);
    cudaMemcpy(d_x, h_x, m * sizeof(int), cudaMemcpyHostToDevice);

    SpMV_CSR<<<1, n>>>(n, d_data, d_col_index, d_row_ptr, d_x, d_y);
    cudaMemcpy(h_y, d_y, n * sizeof(int), cudaMemcpyDeviceToHost);

    printf("Y:");
    for (int i = 0; i < n; i++) {
        printf(" %d", h_y[i]);
    }
    printf("\n");
}