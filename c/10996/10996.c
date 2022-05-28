#include <stdio.h>

void	ft_star(int idx, int n)
{
	if (idx % 2 == 0)
		printf(" ");
	
	if (n % 2 == 0)
		n = n - 1;
	else if (n % 2 == 1 && idx % 2 == 0)
		n = n - 2;
	
	while (n)
	{
		if (n % 2 == 1)
			printf("*");
		else
			printf(" ");
		n--;
	}
}

int main(void)
{
	int n, idx;

	scanf("%d", &n);
	if (n == 1)
		printf("*");
	else
	{
		idx = 1;
		while (idx <= 2 * n)
		{
			ft_star(idx++, n);
			printf("\n");
		}
	}
	return (0);
}