#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void transp(int m, int n, int array[], int newarray[]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            newarray[j * n + i] = array[i * n + j];
    }
}
void fill(int m, int n, int array[]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i * n + j] = rand() % 101 - 50;
}
void out(int m, int n, int arr[]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i * n + j]);
        printf("\n");
    }
    printf("\n");
}
int main() {
    srand(time(NULL));
    int n, m, z;
    int *newarray = (int *)malloc(n*m*sizeof(int));
    if (!newarray)
{
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
}
    printf("Enter count of rows: ");
    scanf("%d", &m);
    printf("Enter count of columns: ");
    scanf("%d", &n);
     int *array = (int *)malloc(n*m*sizeof(int));
    if (!array)
{
    printf("Memory allocation error!\n");
    exit(EXIT_FAILURE);
}
    fill(m, n, array);
    out(m, n, array);
    printf("Enter a number: ");
    scanf("%d", &z);
    int sum1 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                sum1 += array[i * n + j];
            if (j - 1 == i && j - 1 >= 0)
                sum1 += array[i * n + j];
            if (j + 1 == i && j + 1 < n)
                sum1 += array[i * n + j];
        }
    
    }
    if (sum1 > z)
    {
        transp(m, n, array, newarray);
        out(n, m, newarray);
    }
    else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (j - 1 == i && j - 1 >= 0)
                    continue;
                if (j + 1 == i && j + 1 < n)
                    continue;
                array[i * n + j] = 0;
           }
        }
          out(m, n, array);
        
    }
     free(newarray);
     free(array);
    return 0;
}
