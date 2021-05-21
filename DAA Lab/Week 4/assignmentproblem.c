#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}
int findCost(int **mat, int num, int *arr, int *cnt)
{
	int result = 0;
	for (int i = 0; i < num; i++)
	{
        (*cnt)++;
		result += mat[i][arr[i]];
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

int getCeil(int *current, int first, int l, int h)
{
	int ceilindex = l;
	for (int i = l + 1; i <= h; i++)
		if (current[i] > first && current[i] < current[ceilindex])
			ceilindex = i;

	return ceilindex;
}

void reverse(int *current, int start, int end)
{
	while (start < end)
	{
		swap(current, start, end);
		start++;
		end--;
	}
}

void lexicoNext(int *current, int num)
{
	int i;
	for (i = num - 2; i >= 0; --i)
		if (current[i] < current[i + 1])
			break;
	int ceilindex = getCeil(current, current[i], i + 1, num - 1);
	swap(current, i, ceilindex);
	reverse(current, i + 1, num - 1);
}

int solve(int **mat, int num)
{
	int *current = (int *)calloc(num, sizeof(int));
	int *best = (int *)calloc(num, sizeof(int));
	for (int i = 0; i < num; i++)
	{
		current[i] = i;
	}
	int iterate = fact(num);
	int min = __INT_MAX__;
	int temp, cnt = 0;
	while (iterate--)
	{
		temp = findCost(mat, num, current,&cnt);
		if (temp < min)
		{
			min = temp;
			for (int i = 0; i < num; i++)
			{
				best[i] = current[i];
			}
		}
		lexicoNext(current, num);
	}
	printf("Minimum cost is : %d\nThe jobs assigned from person 1 to %d : ", min, num);
	for (int i = 0; i < num; i++)
	{
		printf("%d ", best[i] + 1);
	}
	printf("\n");
    return cnt;
}

int main()
{
	int num;
	printf("Enter the number of jobs and people : ");
	scanf("%d", &num);
	printf("Enter the adjacency matrix : \n");
	int **mat = (int **)calloc(num, sizeof(int *));
	for (int i = 0; i < num; i++)
	{
		mat[i] = (int *)calloc(num, sizeof(int));
		for (int j = 0; j < num; j++)
		{
			scanf("%d", &mat[i][j]);
		}
	}
	int count = solve(mat, num);
	printf("The number of operations is : %d\n", count);
	return 0;
}

