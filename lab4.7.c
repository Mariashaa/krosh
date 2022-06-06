#include <stdio.h>
#include <math.h>
double integral (double x, double y)
{
    if (y <= 1)
    return exp(-2 * sin(x));
    else 
    return (x * x) - 1 / tan(x);
}
 int main()
{
    double z;
    double sum1 = 0;
    double x;
    double q = 0.5; q - ширина одного столбца
    double f = 3;
    double t;

    printf("Enter z: ");
    scanf("%lf", &z);

 while (fabs(sum1 - f) / 3 >= z)
{
    f = sum1;
    sum1 = 0; q /= 2;

    t = 3 / q;

 for (int i = 0; i < t; i++)
{
    x = i * q - 1 + q / 3;
    sum1 += integral (x, i * q - 1);
}
    sum1 *= q;
    printf("%lf\n", sum1);

}
    printf("%lf", sum1);
    return 0;
}
