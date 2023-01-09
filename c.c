#include <math.h>
#include <stdio.h>
#include <time.h>

double x(int m, int n, double p) {
    double result = 0.0;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            result += pow((pow(i, 2.0) / 5) - sin(pow(i, (1.0/3.0))) - 5 + log(j + 1) - sqrt(5 / pow((j + 1), 2.0)), p);
        }
    }
    return pow(result, (1 / p));
}

int main() {
    double result = 0.0;
    clock_t begin = clock();
    for (int i = 0; i < 1000; i++) {
        result = x(50, 50, 3.0);
    }
    clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f\nC time: %f", result, time_spent/1000.0);
    return 0;
}
