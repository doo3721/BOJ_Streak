#include <stdio.h>

void	ft_star(int idx, int n)
{
	int i;

	i = idx > n ? idx - n : idx;
	while (i)
	{
		printf("*");
		i--;
	}
	
	i = idx > n ? 2 * n : 2 * (n - idx);
	while (i)
	{
		printf(" ");
		i--;
	}

	i = idx > n ? idx - n : idx;
	while (i)
	{
		printf("*");
		i--;
	}
}

int	main(void)
{
	int n, idx;

	scanf("%d", &n);

	idx = 1;
	while (idx <= n)
	{
		ft_star(idx++, n);
		printf("\n");
	}

	idx = 1;
	while (idx < n)
	{
		ft_star(n, idx++);
		printf("\n");
	}
	return (0);
}