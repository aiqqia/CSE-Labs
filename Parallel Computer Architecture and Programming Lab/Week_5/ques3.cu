#include<cuda.h>
#include<stdlib.h>
#include<stdio.h>

__global__
void oddEven(int *arr,int n){
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	if(idx%2 == 1 && idx + 1 < n){
		if(arr[idx] > arr[idx+1]){
			int temp = arr[idx];
			arr[idx] = arr[idx+1];
			arr[idx+1] = temp;
		}
	}
}

__global__
void evenOdd(int* arr,int n){
	int idx = threadIdx.x + blockIdx.x*blockDim.x;

	if(idx%2 == 0 && idx + 1 < n){
		if(arr[idx] > arr[idx+1]){
			int temp = arr[idx];
			arr[idx] = arr[idx+1];
			arr[idx+1] = temp;
		}
	}
}

void oddEvenTranspositionSort(int *arr,int n){
	int size= n * sizeof(int);
	int *d_arr;
	cudaMalloc((void**)&d_arr,size);
	cudaMemcpy(d_arr,arr,size,cudaMemcpyHostToDevice);
	for(int i = 0;i<=n/2;i++){
		oddEven<<<1,n>>>(d_arr,n);
		evenOdd<<<1,n>>>(d_arr,n);
	}
	cudaMemcpy(arr,d_arr,size,cudaMemcpyDeviceToHost);
	cudaFree(d_arr);
}

int main(){
	int *h_arr;
	int n;
    printf("Enter size(N): ");
    scanf("%d", &n);
	int size = n * sizeof(int);
	h_arr = (int*)malloc(size);
    printf("Enter %d elements in unsorted array: ", n);
	for(int i = 0 ;i < n;i++){
		scanf("%d",&h_arr[i]);
	}
	printf("Unsorted Arr:");
	for(int i = 0 ;i < n;i++){
		printf("%d ",h_arr[i]);
	}
	printf("\n\n");
	oddEvenTranspositionSort(h_arr,n);
	printf("Sorted Arr: ");
	for(int i = 0 ;i < n;i++){
		printf("%d ",h_arr[i]);
	}
	printf("\n");
	return 0;
}
