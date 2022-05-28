#include <stdio.h>

void	ft_star(int idx, int n)
{
	if (idx % 2 == 0)
		printf(" ");
	
	n = 2 * n - 1;
	while (n)
	{
		if (n % 2 == 1)
			printf("*");
		else
			printf(" ");
		n--;
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
	return (0);
}