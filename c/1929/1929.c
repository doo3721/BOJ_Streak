#include <stdio.h>

int	ft_is_prime(int num)
{
	int idx;

	if (num < 2)
		return (0);
	idx = 2;
	while (idx * idx <= num)
	{
		if (!(num % idx))
			return (0);
		idx++;
	}
	return (1);
}

int main(void)
{
	int m, n, idx;

	scanf("%d%d", &m, &n);

	idx = m;
	while (idx <= n)
	{
		if (ft_is_prime(idx))
			printf("%d\n", idx);
		idx++;
	}
	return (0);
}