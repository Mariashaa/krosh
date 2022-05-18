#include <math.h>
#include <stdio.h>

int
main()
{

    double h, f;
    int i = 0;

    printf("Enter h: ");
    scanf("%lf", &h);

    int count = (int)(3 / h);

    printf("x           f(x)\n--------------------\n");

    while(i <= count)
    {
        double x = -1.5 + i * h;
        if(x >= -1.5 && x <= 0)
        {
            f = (pow(x, 2) - 2 * pow(x, 3)) * cos(pow(x, 2));
        }
        else if(x <= 1.5)
        {
            f = exp(sin(2 * x));
        }
        printf("%f    %f\n", x, f);

        i++;
    }

    return 0;
}
