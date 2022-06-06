#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void massiv(int i, int j, int a[])
{
  int cnt = 0;
    for (int l = i; l < (j - i) / 2 + i; l++)
    {
      int temp = a[l];
      a[l] = a[j - cnt - 1];
      a[j - cnt - 1] = temp;
      cnt++;
    }
}
void fill(int n, int a[])
{
    int i;
    for (i = 0; i < n; i++)
        a[i] = rand() % 101 - 50;
}
int main()
{
    int z;
    int t = -1;
    srand(time(NULL));
    int n;
    printf("n -> ");
    scanf("%d", &n);
    int A[n];
    fill(n, A);
    for (int i = 0; i < n; i++)
        printf("%4d ", A[i]);
    printf("\nВведите число ");
    scanf("%d", &z);
    for (int i = 0; i < n; i++)
    {
        if (A[i] == z)
            t = i;
    }
    if (t < 0)
        massiv(0, n, A);
    else
    {
        massiv(0, t, A);
        massiv(t + 1, n, A);
    }
    int i;
    for (i = 0; i < n; i++)
        printf("%4d ", A[i]);
    printf("\n");
    return 0;
}
