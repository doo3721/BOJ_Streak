#include <stdio.h>

void	ft_star(int idx, int n)
{
	n = n - idx;
	while (n)
	{
		printf(" ");
		n--;
	}

	idx = 2 * idx - 1;
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
	while (idx <= n)
	{
		ft_star(idx++, n);
		printf("\n");
	}
	return (0);
}