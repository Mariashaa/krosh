#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <math.h>

// функция

double func(double x)

{

double y=0.0;

if (x >= -1.5 && x <= 0)

{

y = (pow(x, 2) - 2 * pow(x, 3)) * cos(pow(x, 2));

} 

else if (x <= 1.5)

{

y = exp(sin(2*x));

}

return y;

}

// интегрирование методом средних прямоугольников

double integr(double a, double b, int n) 

{

double result = 0, h = (b - a) / n;

for (int i = 0; i < n; i++) {

result += func(a + h * (i + 0.5));

}

result *= h;

return result;

}

int main()

{

double res1, res2;

// граница интегрирования

double a = -1;

double b = 1;

double err;

// ввод ошибки

printf("Input err: ");

scanf("%lf", &err);

// число разбиений

int n = 10; 

res2 = integr(a, b, n);

do

{

n *= 2; // увеличиваем в два рара число разбиений

res1 = res2;

res2 = integr(a, b, n);

} while (fabs(res1 - res2) > err); // если модуль разности двух значений меньше или равен err, то прекращаем расчет

// выводим результат

printf("Res = %lf\n\n", res2);

}
