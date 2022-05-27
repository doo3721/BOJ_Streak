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
	int n;

	scanf("%d", &n);

	while (n)
	{
		ft_star(n);
		printf("\n");
		n--;
	}
	return (0);
}