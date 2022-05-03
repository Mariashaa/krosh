#include <stdio.h>
int main()
{
	double a, b, x;
	//ввод исходных данных
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("x = ");
	scanf("%lf", &x);
	if (a*b < x)	//если произведение меньше х
	{
		//¬ыведите произведение параметров a, b
		printf("(a * b)/x = %lf\n",(a*b)/x);
	}//и разность иначе
	else if (a*b > x)
	{
		printf("a - b = %lf\n", a-b);
	}
	else
	{//¬ случае равенства выведите соответствующее сообщение
		printf("a*b equal x\n");
	}
	getchar();
	getchar();
	return 0;
}
