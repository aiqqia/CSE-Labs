#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data; 
    int priority;
}NODE;

void heapifyTop(NODE arr[], int n)
{
	if (n <= 1)
	{
		return;
	}
	if (arr[n].priority > arr[n / 2].priority)
	{
		NODE temp = arr[n];
		arr[n] = arr[n / 2];
		arr[n / 2] = temp;
	}
	heapifyTop(arr, n / 2);
}

void heapify(NODE arr[], int n)
{
	for (int i = n / 2; i >= 1; i--)
	{
		NODE v = arr[i];
		int k = i;
		int flag = 0;
		while (!flag && 2 * k <= n)
		{
			int j = 2 * k;
			if (j < n)
			{
				if (arr[j].priority < arr[j + 1].priority)
				{
					j++;
				}
			}
			if (v.priority < arr[j].priority)
			{
				arr[k] = arr[j];
				k = j;
			}
			else
			{
				flag = 1;
			}
		}
		arr[k] = v;
	}
	return;
}

int deleteMax(NODE arr[], int n)
{
	NODE temp = arr[1];
	arr[1] = arr[n];
	arr[n] = temp;
	n = n - 1;
	heapify(arr, n);
	return n;
}

int insert(NODE arr[], int n, NODE val)
{
	n = n + 1;
	arr[n] = val;
	heapifyTop(arr, n);
	return n;
}

int deleteAny (NODE arr[], int n, int val)
{
	int pos = -1;
	for (int i = 1; i <= n; i++)
	{
		if (arr[i].data == val)
		{
			pos = i;
			break;
		}
	}
	if (pos == -1)
	{
		printf("Element not found\n");
		return n;
	}
	for (int i = pos; i < n; i++)
	{
		arr[i] = arr[i + 1];
	}
	return n - 1;
}

int main()
{
	NODE arr[100];
	int ch;
	NODE ele;
	int n = 0, temp;
    do{
		printf("\n1) Insert  2) Display Queue  3) Delete element by priority  4) Delete any element  5) Exit     Enter choice : ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			printf("Enter element : ");
			scanf("%d", &ele.data);
			printf("Enter the element's priority : ");
			scanf("%d", &ele.priority);
			n = insert(arr, n, ele);
			break;
		case 2:
			printf("The queue is : ");
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", arr[i].data);
			}
			printf("\n");
			break;
		case 3:
			if (n != 0)
			{
				n = deleteMax(arr, n);
				printf("The element dequeued by priority is : %d with priority : %d\n", arr[n + 1].data, arr[n + 1].priority);
			}
			else
			{
				printf("Queue is empty\n");
			}

			break;
		case 4:
			printf("Enter the element to be deleted : ");
			scanf("%d", &temp);
			n = deleteAny (arr, n, temp);
			printf("The element is deleted\n");
			break;
		case 5:
            exit(1);
			break;
		default:
            break;
		}
	}while (ch < 5);
	return 0;
}