// 1003.cpp: 定义控制台应用程序的入口点。
//

#include <stdio.h>


int main()
{
	double input;
	scanf("%lf", &input);
	while (input!=0.00)
	{
		double total = 0.00;
		int n = 0;
		while (total<=input)
		{
			n++;
			total += 1 / (double)(1 + n);
		}
		printf("%d card(s)\n", n);
		scanf("%lf", &input);
	}	
    return 0;
}

