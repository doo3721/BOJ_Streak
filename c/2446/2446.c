#include <stdio.h>

void	ft_star(int a, int b)
{
	int	idx;

	idx = a >= b ? a - b : a;
	while (idx)
	{
		printf(" ");
		idx--;
	}

	idx = a >= b ? 2 * b - 1 : 2 * (b - a) - 1;
	while (idx)
	{
		printf("*");
		idx--;
	}
}

int main(void)
{
	int n, idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n - 1)
	{
		ft_star(idx++, n);
		printf("\n");
	}

	idx = 1;
	while (idx <= n)
	{
		ft_star(n, idx++);
		printf("\n");
	}
	return (0);
}