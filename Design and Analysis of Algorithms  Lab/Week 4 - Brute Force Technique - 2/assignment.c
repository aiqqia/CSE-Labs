#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
void nextPermute(int *cur, int num);
int findCost(int **matrix, int num, int *arr);
int solve(int **matrix, int num);
void reverse(int *cur, int start, int end);
int findCeil(int *cur, int first, int l, int h);
int main()
{
	int num;
	printf("Enter the number of jobs : ");
	scanf("%d", &num);
	printf("Enter the adjacency : ");
	int **matrix = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
		matrix[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	int count = solve(matrix, num);
	printf("The number of operations is : %d\n", count);
	return 0;
}

int findCost(int **matrix, int num, int *arr)
{
	int result = 0;
	for (int i = 0; i < num; i++)
	{
		result += matrix[i][arr[i]];
	}
	return result;
}

int fact(int num)
{
	int result = 1;
	for (int i = 1; i <= num; i++)
	{
		result *= i;
	}
	return result;
}

int solve(int **matrix, int num)
{
	int *cur = (int *)calloc(num, sizeof(int));
	int *best = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		cur[i] = i;
	}
	int loop = fact(num);
	int min = __INT_MAX__;
	int temp, cnt = 0;
	printf("%d\n", loop);
	while (loop--)
	{
		cnt++;
		temp = findCost(matrix, num, cur);
		printf("The cost is : %d\n", temp);
		if (temp < min)
		{
			min = temp;
			for (int i = 0; i < num; i++)
			{
				best[i] = cur[i]; //10 3 8 9 7 5 4 8 6 9 2 9 8 7 10 5
			}
		}
		nextPermute(cur, num);
	}
	printf("Minimum cost is : %d\nAnd the jobs assigned to person 0 to %d : ", min, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", best[i] + 1);
	}
	printf("\n");
    return cnt;
}

void nextPermute(int *cur, int num)
{
	int i;
	for (i = num - 2; i >= 0; --i)
		if (cur[i] < cur[i + 1])
			break;
	int ceilIndex = findCeil(cur, cur[i], i + 1, num - 1);
	swap(cur, i, ceilIndex);
	reverse(cur, i + 1, num - 1);
}
void reverse(int *cur, int start, int end)
{
	while (start < end)
	{
		swap(cur, start, end);
		start++;
		end--;
	}
}
int findCeil(int *cur, int first, int l, int h)
{
	int ceilIndex = l;
	for (int i = l + 1; i <= h; i++)
		if (cur[i] > first && cur[i] < cur[ceilIndex])
			ceilIndex = i;

	return ceilIndex;
}