
#include <stdio.h>
#include <math.h>

int main() {
    float h, f;
    float x = 0;
    printf("Enter h: ");
    scanf("%f", &h);

    printf("x           f(x)\n");
    printf("--------------------\n");

    for (int i = 0; x <= 1.500001; i++)
    {
        if (x >= -1.5 && x <= 0) {
            f = (pow(x, 2) - 2 * pow(x, 3)) * cos(pow(x, 2));
            printf("%f    %f\n", x, f);
        }
        else {
            f = exp(sin(2*x));
            printf("%f    %f\n", x, f);
        }
        x += h;
    }

    return 0;
}
