#include <stdio.h>

void	ft_star(int a, int b)
{
	int	idx;

	idx = a > b ? b : b - a;
	while (idx)
	{
		printf(" ");
		idx--;
	}

	idx = a > b ? a - b : a;
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

	idx = 1;
	while (idx < n)
	{
		ft_star(idx++, n);
		printf("\n");
	}

	idx = 0;
	while (idx < n)
	{
		ft_star(n, idx++);
		printf("\n");
	}
	return (0);
}