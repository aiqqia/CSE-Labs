#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

// 2. Write and execute a CUDA program to read an array of N integer values. Sort the array in parallel using parallel selection sort and store the result in another array.

__global__
void selectionSortKernel(int* unsorted,int *sorted,int n){
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	int key = unsorted[idx];
	int pos = 0;
	for(int i = 0;i < n;i++){
		if(unsorted[i] < key || (unsorted[i] == key && i < idx)){
			pos++;
		}
	}
	sorted[pos] = key;
}

void selectionSort(int *unsorted,int *sorted,int n){
	int size = n * sizeof(int);
	int *d_unsorted;
	int *d_sorted;

	cudaMalloc((void**)&d_unsorted,size);
	cudaMalloc((void**)&d_sorted,size);
	cudaMemcpy(d_unsorted,unsorted,size,cudaMemcpyHostToDevice);
	selectionSortKernel<<<1,n>>>(d_unsorted,d_sorted,n);
	cudaMemcpy(sorted,d_sorted,size,cudaMemcpyDeviceToHost);
	cudaFree(d_unsorted);
	cudaFree(d_sorted);
}
int main(){
	int *h_unsorted,*h_sorted;
	printf("Enter size(N): ");
    int n;
    scanf("%d",&n);
	int size = n * sizeof(int);
	h_unsorted = (int*)malloc(size);
	h_sorted = (int*)malloc(size);
    printf("\nEnter %d elements in unsorted array: ", n);
	for(int i = 0; i < n; i++){
		scanf("%d", &h_unsorted[i]);
	}
	selectionSort(h_unsorted,h_sorted,n);
	printf("unsorted arr:");
	for(int i = 0;i < n;i++){
		printf("%d,",h_unsorted[i]);
	}
	printf("\n\n");
	printf("sorted arr:");
	for(int i = 0;i < n;i++){
		printf("%d,",h_sorted[i]);
	}
	printf("\n\n");	
	return 0;
}