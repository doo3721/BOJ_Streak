#include <stdio.h>

int ft_prime(int n)
{
	int idx;

	idx = 2;
	while (idx * idx <= n)
	{
		if (!(n % idx))
			return (0);
		idx++;
	}
	return (1);
}

int	ft_solve(int n)
{
	int idx, cnt;

	idx = n + 1;
	cnt = 0;
	while (idx <= 2 * n)
		cnt += ft_prime(idx++);
	return (cnt);
}

int main(void)
{
	int n, cnt;

	while (1)
	{
		scanf("%d", &n);
		if (!n)
			break;
		cnt = ft_solve(n);
		printf("%d\n", cnt);
	}
	return (0);
}