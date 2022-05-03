#include <stdio.h>
#include <math.h>
int main()
{
double f, h, x;
unsigned int n, c = 0;
printf("h = ");
scanf("%lf", &h);
n = 2 / h;
while (c <= n)
{
if (0.0 < x && x <= 1.)
f = exp(sin(2*x));
else
f = (x*x - 2*x*x*x) * cos(x*x);
printf("x = %lf\t f(x) = %lf\n", x, f);
x = x + h;
c++;
}
return 0;
}
