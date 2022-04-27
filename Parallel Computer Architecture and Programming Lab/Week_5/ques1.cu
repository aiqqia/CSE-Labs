#include <cuda.h>
#include <stdlib.h>
#include <stdio.h>

// 1. Write and execute a program in CUDA to add two vectors of length N to meet the following requirements using 3 different kernels 

// a) block size as N 

// b) N threads within a block

// c) Keep the number of threads per block as 256 (constant) and vary the number of blocks to handle N elements.

__global__
void vecAddKernel_1a(float *a,float *b,float *c){
	int idx = threadIdx.x + blockIdx.x*blockDim.x;
	c[idx] = a[idx]+b[idx];
}

__global__
void vecAddKernel_1b(float *a,float *b,float *c){
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	c[idx] = a[idx] + b[idx];
}

__global__
void vecAddKernel_1c(float *a,float *b,float *c,int n){
	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if(idx < n){
		c[idx] = a[idx] + b[idx];
	}
}

void vecAdd(float *a,float *b,float *c,int n){
	int size = n * sizeof(float);
	float *d_a,*d_b,*d_c;
	cudaMalloc((void**) &d_a,size);
	cudaMalloc((void**) &d_b,size);
	cudaMalloc((void**) &d_c,size);

	cudaMemcpy(d_a,a,size,cudaMemcpyHostToDevice);
	cudaMemcpy(d_b,b,size,cudaMemcpyHostToDevice);
	printf("a:");
	for(int i = 0;i<n;i++){
		printf("%f,",a[i]);
	}
	printf("\n");
	printf("b:");
	for(int i = 0;i<n;i++){
		printf("%f,",b[i]);
	}
	printf("\n\n\n");
	vecAddKernel_1a<<<n,1>>> (d_a,d_b,d_c);
	cudaMemcpy(c,d_c,size,cudaMemcpyDeviceToHost);
	printf("a + b(from kernel 1a):");
	for(int i = 0;i<n;i++){
		printf("%f,",c[i]);
	}
	printf("\n\n");

	vecAddKernel_1b<<<1,n>>> (d_a,d_b,d_c);
	cudaMemcpy(c,d_c,size,cudaMemcpyDeviceToHost);
	printf("a + b(from kernel 1b):");
	for(int i = 0;i<n;i++){
		printf("%f,",c[i]);
	}
	printf("\n\n");	

	vecAddKernel_1c<<<((n+255)/256),256>>> (d_a,d_b,d_c,n);
	cudaMemcpy(c,d_c,size,cudaMemcpyDeviceToHost);
	printf("a + b(from kernel 1c):");
	for(int i = 0;i<n;i++){
		printf("%f,",c[i]);
	}
	printf("\n\n");	
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
}

int main(){
	float *ha,*hb,*hc;
	int n = 5;
	int size = n*sizeof(float);
	ha = (float*)malloc(size);
	hb = (float*)malloc(size);
	hc = (float*)malloc(size);

	for(int i = 0;i<n;i++){
		ha[i] = (i+1)*2;
		hb[i] = (i+1);
	}
	vecAdd(ha,hb,hc,n);
	return 0;
}