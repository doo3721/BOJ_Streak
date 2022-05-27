#include <stdio.h>

void	ft_star(int idx, int n)
{
	n = n - idx;

	while (idx)
	{
		printf(" ");
		idx--;
	}
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

	idx = 0;
	while (idx < n)
	{
		ft_star(idx++, n);
		printf("\n");
	}
	return (0);
}