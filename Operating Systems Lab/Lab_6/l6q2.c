#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void* thread_code(void* args){
	int *arr = (int*)args;
	int n = arr[0];
	int *res = (int*)malloc(sizeof(int));
	*res = 0;
	for(int i=1;i<=n;i++){
		*res+=arr[i];
	}
	return (void*)res;
}

int main(int argc, char* argv[]){
	if(argc<2){
		printf("Not enough arguments!\n");
		exit(EXIT_FAILURE);
	}
	int n = argc - 1;
	int* arr = (int*)calloc(n+1, sizeof(int)), *res;
	arr[0] = n;
	for(int i=0;i<n;i++){
		arr[i+1] = atoi(argv[i+1]);
	}
	pthread_t thread;
	pthread_create(&thread, 0, &thread_code, (void*)arr);
	pthread_join(thread, (void**)&res);
	printf("The Sum is: %d\n", *res);
	return 0;
}