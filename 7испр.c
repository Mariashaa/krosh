#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void transp(int m, int n, int **array, int **newarray) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            newarray[j][i] = array[i][j];
    }
}
void fill(int m, int n, int **array) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            array[i][j] = rand() % 101 - 50;
}
void out(int m, int n, int **arr) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%4d", arr[i][j]);
        printf("\n");
    }
    printf("\n");
}
int main() {
    srand(time(NULL));
    int n, m, z;
    printf("Enter count of rows: ");
    scanf("%d", &m);
    printf("Enter count of columns: ");
    scanf("%d", &n);
    int **newarray = (int**) malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        newarray[i] = (int*) malloc(m * sizeof(int));
    }

    int **array = (int**) malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        array[i] = (int*) malloc(n * sizeof(int));
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

    for (int i = 0; i < n; i++) {
        free(newarray[i]);
    }
    free(newarray);

    for (int i = 0; i < m; i++) {
        free(array[i]);
    }
    free(array);
    return 0;
}
