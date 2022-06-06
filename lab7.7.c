#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void transp(int m, int n, int array[][n], int newarray[][m]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            newarray[j][i] = array[i][j];
    }
}
void fill(int m, int n, int array[][n]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = rand() % 101 - 50;
}
void out(int m, int n, int arr[][n]) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main() {
    srand(time(NULL));
    int n, m, z, newarray[n][m];
    printf("Enter count of rows: ");
    scanf("%d", &m);
    printf("Enter count of columns: ");
    scanf("%d", &n);
    int array[m][n];
    fill(m, n, array);
    out(m, n, array);
    printf("Enter a number: ");
    scanf("%d", &z);
    int sum1 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                sum1 += array[i][j];
            if (j - 1 == i && j - 1 >= 0)
                sum1 += array[i][j];
            if (j + 1 == i && j + 1 < n)
                sum1 += array[i][j];
        }
    }
    printf("sum: %d\n", sum1);
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
                array[i][j] = 0;
            }
        }
        out(m, n, array);
    }

    return 0;
}
