#include <stdio.h>

int	ft_prime_f(int n)
{
	int idx;

	idx = 2;
	while (idx * idx <= n)
	{
		if (!(n % idx))
			return (idx);
		idx++;
	}
	return (n);
}

int main(void)
{
	int n, f;

	scanf("%d", &n);

	if (n != 1)
	{
		while (n != 1)
		{
			f = ft_prime_f(n);
			printf("%d\n", f);
			n /= f;
		}
	}
	return (0);
}