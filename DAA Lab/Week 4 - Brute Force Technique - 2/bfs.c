#include <stdio.h>
#include <stdlib.h>

int isEmpty(int front, int rear)
{
	if (front == rear)
	{
		return 1;
	}
	return 0;
}

int isFull(int front, int rear, int maxsize)
{
	if ((rear + 1) % maxsize == front)
	{
		return 1;
	}
	return 0;
}

void display(int *Queue, int front, int rear, int maxsize)
{
	if (isEmpty(front, rear))
	{
	}
	else
	{
		printf("queue : ");
		for (int i = (front + 1) % maxsize; i != (rear + 1) % maxsize; i = (i + 1) % maxsize)
		{
			printf("%d ", Queue[i]);
		}
		printf("\n");
	}
}

void push(int **Queue, int *front, int *rear, int *maxsize, int key)
{
	if (isFull(*front, *rear, *maxsize))
	{
		int *newQueue = (int *)calloc((*maxsize) * 2, sizeof(int));
		int i, j;
		for (i = 1, j = (*front + 1) % (*maxsize); j != (*rear + 1) % (*maxsize); j = (j + 1) % (*maxsize), i++)
		{
			newQueue[i] = (*Queue)[j];
		}
		int *temp = *Queue;
		*Queue = newQueue;
		*maxsize = *maxsize * 2;
		*front = 0;
		*rear = --i;
		free(temp);
	}
	*rear = (*rear + 1) % (*maxsize);
	(*Queue)[*rear] = key;
}

int pop(int **Queue, int *front, int *rear, int *maxsize)
{
	int temp = (*Queue)[(*front + 1) % (*maxsize)];
	*front = (*front + 1) % (*maxsize);
	return temp;
}
void insertEdge(int **matrix, int first, int second)
{
	matrix[first][second] = 1;
	matrix[second][first] = 1;
}

void dispM(int **matrix, int n)
{
	for (int i = -1; i < n; i++)
	{
		if (i != -1)
			printf("%d -> ", i);
		for (int j = 0; j < n; j++)
		{
			if (i == -1)
			{
				if (j == 0)
				{
					printf("\t");
				}
				printf("%d\t", j);
				continue;
			}
			if (j == 0)
			{
				printf("\t");
			}
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}

void BFS(int **matrix, int num, int **Queue, int *front, int *rear, int *maxsize)
{
	int *visited = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		visited[i] = 0;
	}
	char result[100];
	int resultIndex = 0;
	char popped[100];
	int poppedIndex = 0;
	push(Queue, front, rear, maxsize, 0);
	printf("pushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resultIndex++] = p;
	display(*Queue, *front, *rear, *maxsize);
	visited[0] = 1;
	int cur = *Queue[*front];
	int flag, ele;
	while (1)
	{
		if (!(isEmpty(*front, *rear)))
		{
			for (int i = 0; i < num; i++)
			{
				if (visited[i] == 0 && matrix[cur][i] == 1)
				{
					visited[i] = 1;
					char p = (char)('0' + i);
					result[resultIndex++] = p;
					push(Queue, front, rear, maxsize, i);
					printf("Pushed : %d\n", i);
					display(*Queue, *front, *rear, *maxsize);
				}
			}
			ele = pop(Queue, front, rear, maxsize);
			p = (char)('0' + ele);
			popped[poppedIndex++] = p;
			printf("Popped : %d\n", ele);
			display(*Queue, *front, *rear, *maxsize);
			cur = (*Queue)[(*front + 1) % (*maxsize)];
		}
		else
		{
			flag = 1;
			for (int i = 0; i < num && flag; i++)
			{
				if (visited[i] == 0)
				{
					visited[i] = 1;
					printf("Pushed : %d\n", i);
					p = (char)('0' + i);
					result[resultIndex++] = p;
					push(Queue, front, rear, maxsize, i);
					display(*Queue, *front, *rear, *maxsize);
					cur = (*Queue)[(*front + 1) % (*maxsize)];
					flag = 0;
					break;
				}
			}
			if (flag == 1)
			{
				break;
			}
		}
	}
	while (!(isEmpty(*front, *rear)))
	{
		ele = pop(Queue, front, rear, maxsize);
		p = (char)('0' + ele);
		popped[poppedIndex++] = p;
		printf("Popped : %d\n", ele);
		display(*Queue, *front, *rear, *maxsize);
	}
	printf("The BFS is : ");
	for (int i = 0; i < resultIndex; i++)
	{
		printf("%c ", result[i]);
	}
	printf("\nThe pop order is : ");
	for (int i = 0; i < poppedIndex; i++)
	{
		printf("%c ", popped[i]);
	}
	printf("\n");
}

int main()
{
	int num = 9;
	int **matrix = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
		matrix[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++)
		{
			matrix[i][j] = 0;
		}
	}
    int m,n;
    do{
        printf("\nEnter edges to be joined : ");
        scanf("%d %d",&m,&n);
        if(m!=-1 && n!=-1)
            insertEdge(matrix, m, n);
    }while(m!=-1);
	dispM(matrix, num);
	int front = 0, rear = 0, maxsize = 2;
	int *Queue = (int *)calloc(maxsize, sizeof(int));
	BFS(matrix, num, &Queue, &front, &rear, &maxsize);
	return 0;
}