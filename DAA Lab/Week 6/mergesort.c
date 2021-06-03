#include <stdio.h>
#include <stdlib.h>

void merge(int *arr, int start, int end, int mid, int *opcount)
{
	int anum = mid - start + 1;
	int bnum = end - mid;
	int a[anum], b[bnum];
	for (int i = 0; i < anum; i++)
	{
		a[i] = arr[i + start];
	}
	for (int i = 0; i < bnum; i++)
	{
		b[i] = arr[i + mid + 1];
	}
	int i = 0, j = 0, k = start;
	while (i < anum && j < bnum)
	{
		(*opcount)++;
		if (a[i] < b[j])
		{
			arr[k] = a[i];
			i++;
		}
		else
		{
			arr[k] = b[j];
			j++;
		}
		k++;
	}
	while (i < anum)
	{
		arr[k] = a[i];
		i++;
		k++;
	}
	while (j < bnum)
	{
		arr[k] = b[j];
		j++;
		k++;
	}
}
void mergeSort(int *arr, int start, int end, int *opcount)
{
	if (start < end)
	{
		int mid = start + (end - start) / 2;
		mergeSort(arr, start, mid, opcount);
		mergeSort(arr, mid + 1, end, opcount);
		merge(arr, start, end, mid, opcount);
	}
}

int main()
{
	printf("Enter the number of elements in the array : ");
	int num;
	scanf("%d", &num);
	printf("Enter the array : ");
	int *arr = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Your array is : ");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	int opcount = 0;
	mergeSort(arr, 0, num - 1, &opcount);
	printf("Your sorted array is : ");
	for (int i = 0; i < num; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\nThe number of operations are : %d\n", opcount);
	return 0;
}