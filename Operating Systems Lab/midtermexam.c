#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

void* threadcodeavg(void** args){
	int** arr = (int**)args;
	int l = 3;
	int m = (l+1)/2;
	int *avg = (int*)malloc(sizeof(int));
	int sum;
	sum=0;
	for(int i=0;i<l;i++){
		sum += arr[m-1][i];
	}
	*avg = sum/l;
	return (void*)avg;
}

void* threadcodelar(void** args){
	int** arr = (int**)args;
	int *l = (int*)malloc(sizeof(int));
	*l = 3;
	int m = (*l+1)/2;
	m-=1;
	int *lar = (int*)malloc(sizeof(int));
	*lar = 0;
	for(int i=0;i<*l;i++){
		if(*lar < arr[i][m])
			*lar = arr[i][m];
	}
	return (void*)lar;
}

int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	if(n%2 == 0){
		printf("\nEven not allowed!");
		exit(-1);
	}
	int **arr = (int**)calloc(n,sizeof(int*));
	for(int i=0;i<n;i++){
		arr[i] = (int*)calloc(n,sizeof(int));
	}
	printf("\nEnter elements: \n");
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nHello!");
	int *resAvg, *resLar;
	pthread_t thread1, thread2;
	pthread_create(&thread1,0,&threadcodeavg,(void**)arr);
	pthread_create(&thread2,0,&threadcodelar,(void**)arr);
	pthread_join(thread1,(void**)&resAvg);
	pthread_join(thread2,(void**)&resLar);
	printf("\nResult is:\nAverage: %d\nLargest: %d",*resAvg,*resLar);
	return 0;
}