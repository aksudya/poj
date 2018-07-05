#include <stdio.h>

int caculate(int n)
{
	int t = 1;
	while (n!=1)
	{
		if(n%2==0)
		{
			n /= 2;
		}
		else
		{
			n = 3 * n + 1;
		}
		t++;
	}
	return t;
}

int main()
{
	int a, b;
	int max, min;
	while (scanf("%d %d",&a,&b) != EOF)
	{
		if(a>b)
		{
			max = a;
			min = b;
		}
		else
		{
			max = b; min = a;
		}
		int max_turn=0;
		for (int i = min; i <= max; ++i)
		{
			int re = caculate(i);
			if(re >max_turn)
			{
				max_turn = re;
			}
		}
		printf("%d %d %d\n", a, b, max_turn);
	}
	return 0;
}

