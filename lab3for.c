#include <stdio.h>
#include <math.h>
int main()
{
double h;
printf("h = ");
scanf("%lf", &h);
printf("%-17sf(x)\n", "x");
int step_h = (int)(2 / h);
double f;
for (int i = 0; i <= step_h; i++)
{
double x = i*h;
if (0.0 < x && x <= 1.5)
f = exp(sin(2*x));
else
f = (x*x - 2*x*x*x) * cos(x*x);
printf("x = %lf\t f(x) = %lf\n", x, f);
}
return 0;
}


#include <math.h>
#include <stdio.h>
int
main()
{
    double h;
    printf("h = ");
    scanf("%lf", &h);
    printf("%-17sf(x)\n", "x");
    int step_h = (int)(2 / h);
    double f;
    for(int i = 0; i <= count_h; i++)
    {
        double x = i * h;
        if(0.0 <= x && x <= 1.5)
            f = exp(sin(2 * x));
        else
            f = (x * x - 2 * x * x * x) * cos(x * x);
        printf("x = %lf\t f(x) = %lf\n", x, f);
    }
    return 0;
}
