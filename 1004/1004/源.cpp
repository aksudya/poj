#include <stdio.h>


int main()
{
	double total = 0.00;
	for (int i = 0; i < 12; ++i)
	{
		double t = 0.00;
		scanf("%lf", &t);
		total += t;
	}
	double result = (total / 12)*100;
	if(result-(int)result>=0.5)
	{
		result += 1;
	}
	printf("$%.2f", result / 100);
	return 0;
}
