#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

__global__
void selectionSortKernel(float* unsorted,float *sorted,int n){
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	float key = unsorted[idx];
	int pos = 0;
	for(int i = 0;i < n;i++){
		if(unsorted[i] < key || (unsorted[i] == key && i < idx)){
			pos++;
		}
	}
	sorted[pos] = key;
}

void selectionSort(float *unsorted,float *sorted,int n){
	int size = n * sizeof(float);
	float *d_unsorted;
	float *d_sorted;

	cudaMalloc((void**)&d_unsorted,size);
	cudaMalloc((void**)&d_sorted,size);
	cudaMemcpy(d_unsorted,unsorted,size,cudaMemcpyHostToDevice);
	selectionSortKernel<<<1,n>>>(d_unsorted,d_sorted,n);
	cudaMemcpy(sorted,d_sorted,size,cudaMemcpyDeviceToHost);
	cudaFree(d_unsorted);
	cudaFree(d_sorted);
}
int main(){
	float *h_unsorted,*h_sorted;
	int n = 5;

	int size = n * sizeof(float);
	h_unsorted = (float*)malloc(size);
	h_sorted = (float*)malloc(size);

	for(int i = 0; i < 5; i++){
		h_unsorted[i] = rand()%50;
	}
	selectionSort(h_unsorted,h_sorted,n);
	printf("unsorted arr:");
	for(int i = 0;i < n;i++){
		printf("%f,",h_unsorted[i]);
	}
	printf("\n\n");
	printf("sorted arr:");
	for(int i = 0;i < n;i++){
		printf("%f,",h_sorted[i]);
	}
	printf("\n\n");	
	return 0;
}