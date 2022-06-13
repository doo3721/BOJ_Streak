#include <stdio.h>

int main(void)
{
	long long	a, b, c, n;

	scanf("%lld%lld%lld", &a, &b, &c);

	if (b < c)
	{
		n = a / (c - b);
		while (a + b * n >= c * n)
			n++;
		printf("%lld", n);
	}
	else
		printf("-1");
	return (0);
}