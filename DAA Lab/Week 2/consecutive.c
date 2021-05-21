#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b, int *x)
{
  for (int i = (a > b ? b : a); i > 0; i--)
  {
    (*x)++;
    if (a % i == 0 && b % i == 0)
    {
      return i;
    }
  }
}

int main()
{
  int m, n;
  scanf("%d %d", &m, &n);
  int x = 0;
  int result = gcd(m, n, &x);
  printf("\nGCD is %d and the Opcount is  %d\n", result, x);
}