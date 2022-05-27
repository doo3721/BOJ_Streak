#include <stdio.h>

void	ft_star(int n)
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
		ft_star(n);
		printf("\n");
		idx++;
	}
	return (0);
}