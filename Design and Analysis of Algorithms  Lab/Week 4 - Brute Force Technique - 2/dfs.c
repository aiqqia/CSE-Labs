#include <stdio.h>
#include <stdlib.h>

int isEmpty(int top)
{
	if (top == -1)
	{
		return 1;
	}
	return 0;
}

int isFull(int top, int size)
{
	if (top == size - 1)
	{
		return 1;
	}
	return 0;
}

void push(int **Stack, int *top, int *size, int key)
{
	if (isFull(*top, *size))
	{
		*Stack = (int *)realloc(*Stack, sizeof(int) * (*size) * 2);
		*size *= 2;
	}
	(*top)++;
	(*Stack)[*top] = key;
}

int pop(int **Stack, int *top)
{
	int temp = (*Stack)[*top];
	(*top)--;
	return temp;
}

void display(int *Stack, int top)
{
	if (isEmpty(top))
	{
	}
	else
	{
		printf("stack : ");
		int i;
		for (i = 0; i <= top; i++)
		{
			printf("%d ", *(Stack + i));
		}
		printf("\n");
	}
}

void insertEdgeM(int **matrix, int first, int second)
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

void DFS(int **matrix, int num, int **Stack, int *top, int *size)
{
	int *visited = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		visited[i] = 0;
	}
	char result[100];
	int resindex = 0;
	char popped[100];
	int popindex = 0;
	push(Stack, top, size, 0);
	printf("pushed : %d\n", 0);
	char p = (char)('0' + 0);
	result[resindex++] = p;
	display(*Stack, *top);
	visited[0] = 1;
	int cur = *Stack[*top];
	int flag, ele;
	while (1)
	{
		if(!(isEmpty(*top))){
			flag = 0;
			for (int i = 0; i < num; i++)
			{
				if (visited[i] == 0 && matrix[cur][i] == 1)
				{
					visited[i] = 1;
					printf("pushed : %d\n", i);
					p = (char)('0' + i);
					result[resindex++] = p;
					push(Stack, top, size, i);
					display(*Stack, *top);
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				ele = pop(Stack, top);
				p = (char)('0' + ele);
				popped[popindex++] = p;
				printf("popped : %d\n", ele);
				display(*Stack, *top);
			}
			cur = (*Stack)[*top];
		}
		else{
			flag = 1;
			for (int i = 0; i < num && flag; i++){
				if(visited[i]==0){
					visited[i] = 1;
					printf("pushed : %d\n", i);
					p = (char)('0' + i);
					result[resindex++] = p;
					push(Stack, top, size, i);
					display(*Stack, *top);
					flag = 0;
					cur = (*Stack)[*top];
					break;
				}
			}
			if(flag == 1){
				break;
			}
		}
		
	}
	while (!(isEmpty(*top)))
	{
		int rem = pop(Stack, top);
		p = (char)('0' + rem);
		popped[popindex++] = p;
		printf("popped : %d\n", rem);
		display(*Stack, *top);
	}
	printf("The DFS is : ");
	for (int i = 0; i < resindex; i++)
	{
		printf("%c ", result[i]);
	}
	printf("\nThe pop order is : ");
	for (int i = 0; i < popindex; i++)
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
            insertEdgeM(matrix, m, n);
    }while(m!=-1);
	dispM(matrix, num);
	int top = -1, size = 2;
	int *Stack = (int *)calloc(size, sizeof(int));
	DFS(matrix, num, &Stack, &top, &size);
	return 0;
}