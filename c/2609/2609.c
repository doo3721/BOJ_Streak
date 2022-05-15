#include <stdio.h>

int	main(void)
{
	int	n;
	int	m;
	int	gcd;
	int lcm;

	scanf("%d", &n);
	scanf("%d", &m);

	if (n < m)
	{
		if (m % n == 0)
			gcd = n;
		else
			gcd = n / 2;
	}
	else
	{
		if (n % m == 0)
			gcd = m;
		else
			gcd = m / 2;
	}

	while ((n % gcd || m % gcd) && gcd > 1)
		gcd--;
	
	lcm = n * m / gcd;

	printf("%d\n%d", gcd, lcm);
	return (0);
}

/*
유클리드 호제법에 의한 풀이
int main(void)
{
	int n;
	int	m;
	int gcd;
	int lcm;

	scanf("%d%d", &n, &m);

	lcm = n * m;
	while ((gcd = n % m))
	{
		n = m;
		m = gcd;
	}

	gcd = m;
	lcm /= gcd;
	printf("%d\n%d", gcd, lcm); 
	return (0);
}
*/