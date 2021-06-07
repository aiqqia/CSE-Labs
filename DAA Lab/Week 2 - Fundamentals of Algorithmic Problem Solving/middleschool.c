#include <stdio.h>
#include <stdlib.h>

void sievesalgo(int m, int arr[])
{
  for (int i = 2; i < m + 1; i++)
  {
    arr[i] = i;
  }
  int j;
  for (int i = 2; i < m + 1; i++)
  {
    if (arr[i] != 0)
    {
      j = i * i;
      while (j <= m)
      {
        arr[j] = 0;
        j = j + i;
      }
    }
  }
}

int primefactors(int n, int arr[], int *op)
{
  int narr[n + 1];
  sievesalgo(n, narr);
  int i = 2;
  int cnt = 0;
  while (i <= n)
  {
    (*op)++;
    if (narr[i] != 0)
    {
      if (n % narr[i] == 0)
      {
        arr[cnt] = narr[i];
        n = n / narr[i];
        cnt++;
      }
      else
      {
        i++;
      }
    }
    else
    {
      i++;
    }
  }
  return cnt;
}

int gcd(int m, int n, int *opcount)
{
  if (m == 0 || n == 0)
  {
    *opcount = 1;
    return m == 0 ? n : m;
  }
  int marr[m], narr[n], op1 = 0, op2 = 0;
  int a = primefactors(m, marr, &op1);
  int b = primefactors(n, narr, &op2);
  *opcount = op1 + op2;
  printf("\n");
  int i = 0, j = 0;
  int res = 1;
  while (i < a && j < b)
  {
    if (marr[i] == narr[j])
    {
      res *= marr[i];
      i++;
      j++;
    }
    else if (marr[i] < narr[j])
    {
      i++;
    }
    else
    {
      j++;
    }
  }
  return res;
}

int main()
{
  int x, y;
  scanf("%d %d", &x, &y);
  int op = 0;
  int res = gcd(x, y, &op);
  printf("GCD is %d and the opcount is : %d\n", res, op);
}