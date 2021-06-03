#include <stdio.h>
#include <stdlib.h>

int opcount = 0;

void merge(int *arr, int start, int end, int mid)
{
	int an = mid - start + 1;
	int bn = end - mid;
	int a[an], b[bn];
	for (int i = 0; i < an; i++){
		a[i] = arr[i + start];
	}
	for (int i = 0; i < bn; i++){
		b[i] = arr[i + mid + 1];
	}
	int i = 0, j = 0, k = start;
	while (i < an && j < bn){
		opcount++;
		if (a[i] < b[j]){
			arr[k] = a[i];
			i++;
		}
		else{
			arr[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < an){
        opcount++;
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < bn){
        opcount++;
		arr[k] = b[j];
		j++;
		k++;
	}
}
void mergesort(int *arr, int start, int end){
	if (start < end){
		int mid = start + (end - start) / 2;
		mergesort(arr, start, mid);
		mergesort(arr, mid + 1, end);
		merge(arr, start, end, mid);
	}
}

int main(){
	printf("Enter number of elements : ");
	int n;
	scanf("%d", &n);
	printf("Enter the array : ");
	int *arr = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
    }
	printf("\n");
	mergesort(arr, 0, n - 1);
	printf("The Sorted Array is : ");
	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\nThe Opcount is : %d\n",opcount);
	return 0;
}