#include <stdio.h>
int main()
{
	int t = 0;
	double PI = 3.141592654;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
		double x = 0;
		double y = 0;
		scanf("%lf %lf", &x, &y);
		double s = (x*x + y * y)*PI / 2;
		int n = 0;
		while (s>n*50)
		{
			n++;
		}
		printf("Property %d: This property will begin eroding in year %d.\n", i+1, n);
	}
	printf("END OF OUTPUT.\n");
	return 0;
}
