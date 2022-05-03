#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>

// 1. Write a CUDA program to perform convolution operation on one dimensional input array N of size width 
//    using a mask array M of size mask_width to produce the resultant one dimensional array P of size width 
//    using without and with constant Memory for Mask array.  
//    Add another kernel function to the first program to perform 1D convolution using shared memory. 
//    Find and display the time taken by both the kernels. 

#define MAX_MASK_WIDTH 5
__constant__ int M[MAX_MASK_WIDTH];

__global__
void oneDConvoluteKernel(int* d_A, int* d_M, int* d_P, int width, int mwidth){
    int id = blockIdx.x*blockDim.x + threadIdx.x;
    int c = 0;
    int sp = id - (mwidth/2);
    for(int j=0;j<mwidth;j++){
        if(sp+j >= 0 && sp+j < width)
            c += d_A[sp+j] * d_M[j];
    }
    d_P[id] = c;
}

__global__
void oneDConvoluteConstMemKernel(int* d_A, int* d_P, int width){
    int id = blockIdx.x*blockDim.x + threadIdx.x;
    int c = 0;
    int sp = id - (MAX_MASK_WIDTH/2);
    for(int j=0;j<MAX_MASK_WIDTH;j++){
        if(sp+j >= 0 && sp+j < width)
            c += d_A[sp+j] * M[j];
    }
    d_P[id] = c;
}

__global__
void oneDConvoluteSharedMemKernel(int *N, int *P, int mask_width, int width){
    int i = blockIdx.x*blockDim.x + threadIdx.x;
    extern __shared__ int N_shared[];
    // copy to shared memory
    N_shared[i] = N[i];
    __syncthreads();
    int Pvalue = 0;
    int N_start_point = i - (mask_width/2);
    for (int j = 0; j < mask_width; j++){
        if (N_start_point + j >= 0 && N_start_point + j < width)
            Pvalue += N_shared[N_start_point + j] * M[j];
    }
    P[i] = Pvalue;
}

__host__
void oneDConvolute(int* h_A, int* h_M, int* h_P, int width, int mwidth){
    cudaEvent_t start, stop;
    cudaEventCreate(&start);
    cudaEventCreate(&stop);
    int *d_A, *d_M, *d_P;
    int size = width*sizeof(int);
    int msize = mwidth*sizeof(int);
    cudaMalloc((void**)&d_A, size);
    cudaMalloc((void**)&d_M, msize);
    cudaMalloc((void**)&d_P, size);
    cudaMemcpy(d_A, h_A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_M, h_M, msize, cudaMemcpyHostToDevice);
    cudaMemcpyToSymbol(M, h_M, MAX_MASK_WIDTH * sizeof(int));
    cudaEventRecord(start, 0);
    oneDConvoluteKernel<<<1,width>>>(d_A, d_M, d_P, width, mwidth);
    cudaEventRecord(stop, 0);
    cudaEventSynchronize(stop);
    float elapsedTime;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    cudaMemcpy(h_P, d_P, size, cudaMemcpyDeviceToHost);
    printf("The Convulated Array is : ");
    for(int i=0;i<width;i++){
        printf("%d ",h_P[i]);
    }
    printf("\nTotal Time Taken: %f\n", elapsedTime);
    cudaEventRecord(start,0);
    oneDConvoluteConstMemKernel<<<1,width>>>(d_A,d_P,width);
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    elapsedTime = 0;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    cudaMemcpy(h_P, d_P, size, cudaMemcpyDeviceToHost);
    printf("The Convulated Array(Constant Memory) is : ");
    for(int i=0;i<width;i++){
        printf("%d ",h_P[i]);
    }
    printf("\nTotal Time Taken(Constant Memory): %f\n", elapsedTime);
    cudaEventRecord(start,0);
    oneDConvoluteSharedMemKernel<<<1, width, width>>>(d_A,d_P,MAX_MASK_WIDTH,width);
    cudaEventRecord(stop,0);
    cudaEventSynchronize(stop);
    elapsedTime = 0;
    cudaEventElapsedTime(&elapsedTime, start, stop);
    cudaMemcpy(h_P, d_P, size, cudaMemcpyDeviceToHost);
    printf("The Convulated Array(Shared Memory) is : ");
    for(int i=0;i<width;i++){
        printf("%d ",h_P[i]);
    }
    printf("\nTotal Time Taken(Shared Memory): %f\n", elapsedTime);
    cudaFree(d_A);
    cudaFree(d_M);
    cudaFree(d_P);
}

int main(){
    int *A, *M, *P;
    int width, mwidth;
    printf("Enter array width: ");
    scanf("%d", &width);
    int size = sizeof(int)*width;
    A = (int*)malloc(size);
    P = (int*)malloc(size);
    printf("Enter array elements: ");
    for(int i=0;i<width;i++){
        scanf("%d",&A[i]);
    }
    printf("Enter mask width(odd): ");
    scanf("%d",&mwidth);
    M = (int*)malloc(mwidth*sizeof(int));
    printf("Enter mask elements: ");
    for(int i=0;i<mwidth;i++){
        scanf("%d",&M[i]);
    }
    oneDConvolute(A,M,P,width,mwidth);
    return 0;
}