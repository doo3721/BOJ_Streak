#include <stdio.h>

void	ft_star(int i, int n)
{
	if (i <= n)
		n = n - i;
	else
		i = i - n;
	while (n)
	{
		printf(" ");
		n--;
	}

	i = 2 * i - 1;
	while (i)
	{
		printf("*");
		i--;
	}
}

int main(void)
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