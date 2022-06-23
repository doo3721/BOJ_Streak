#include <stdio.h>

int	ft_prime(int n)
{
	int	idx;

	if (n < 2)
		return (0);
	idx = 2;
	while (idx * idx <= n)
	{
		if (!(n % idx))
			return (0);
		idx++;
	}
	return (1);
}

int main(void)
{
	int m, n, min_p, sum_p;

	scanf("%d%d", &m, &n);

	min_p = 0;
	sum_p = 0;
	while (m <= n)
	{
		if (ft_prime(m))
		{
			if (!min_p)
				min_p = m;
			sum_p += m;
		}
		m++;
	}
	if (min_p)
		printf("%d\n%d", sum_p, min_p);
	else
		printf("-1");
	return (0);
}