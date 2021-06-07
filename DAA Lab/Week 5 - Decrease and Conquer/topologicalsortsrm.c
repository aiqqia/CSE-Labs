#include <stdio.h>
#include <stdlib.h>

void insertEdge(int **mat, int first, int second)
{
	mat[first][second] = 1;
}

// void display(int **mat, int n)
// {
// 	for (int i = -1; i < n; i++)
// 	{
// 		if (i != -1)
// 			printf("%d -> ", i);
// 		for (int j = 0; j < n; j++)
// 		{
// 			if (i == -1)
// 			{
// 				if (j == 0)
// 				{
// 					printf("\t");
// 				}
// 				printf("%d\t", j);
// 				continue;
// 			}
// 			if (j == 0)
// 			{
// 				printf("\t");
// 			}
// 			printf("%d\t", mat[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

int check(int **mat, int num, int node)
{
	int result = 1;
	for (int i = 0; i < num; i++)
	{
		if (mat[i][node] == 1)
		{
			result = 0;
		}
	}
	return result;
}

void deleteEdge(int **mat, int num, int node)
{
	for (int i = 0; i < num; i++)
	{
		mat[node][i] = 0;
	}
}

void topologicalsort(int **mat, int num)
{
	int *removed = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		removed[i] = 0;
	}
	int popped[num];
	int popIndex = 0;
	for (int i = 0; i < num; i++)
	{
		if (removed[i] == 0 && check(mat, num, i))
		{
			removed[i] = 1;
			popped[popIndex++] = i;
			deleteEdge(mat, num, i);
			i = -1;
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (removed[i] == 0)
		{
			printf("The Graph is a Cyclic Graph.\n");
			return;
		}
	}
	printf("The Graph is a Directed Acyclic Graph (DAG), Topoplogical Sort order is : ");
	for (int i = 0; i < popIndex; i++)
	{
		printf("%d ", popped[i]);
	}
	printf("\n");
}

int main()
{
	int num = 6;
	int **mat = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
		mat[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++)
		{
			mat[i][j] = 0;
		}
	}
    int m,n;
    do{
        printf("Enter edges to be joined : ");
        scanf("%d %d",&m,&n);
        if(m!=-1 && n!=-1)
            insertEdge(mat, m, n);
    }while(m!=-1);
	// insertEdge(mat, 0, 2);
	// insertEdge(mat, 0, 3);
	// insertEdge(mat, 1, 3);
	// insertEdge(mat, 1, 4);
	// insertEdge(mat, 2, 3);
	// insertEdge(mat, 2, 5);
	// insertEdge(mat, 3, 5);
	// insertEdge(mat, 4, 5);
	//display(mat, num);
	topologicalsort(mat, num);
	return 0;
}