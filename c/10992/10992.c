#include <stdio.h>

void	ft_star(int idx, int n)
{
	n = n - idx;
	while (n)
	{
		printf(" ");
		n--;
	}

	printf("*");
	idx = 2 * idx - 2;
	while (idx)
	{
		if (idx == 1)
			printf("*");
		else
			printf(" ");
		idx--;
	}
}

void	ft_last(int n)
{
	while (n)
	{
		printf("*");
		n--;
	}
}

int main(void)
{
	int n, idx;

	scanf("%d", &n);

	idx = 1;
	while (idx <= n)
	{
		if (idx != n)
			ft_star(idx++, n);
		else
			ft_last(2 * idx++ - 1);
		printf("\n");
	}
	return (0);
}