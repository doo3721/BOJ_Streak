#include <stdio.h>

int	ft_power(int n)
{
	int num;

	num = 1;
	while (n)
	{
		num *= 2;
		n--;
	}
	return (num);
}

void	ft_solve(int from, int to, int k)
{
	if (k == 1)
	{
		printf("%d %d\n", from, to);
		return ;
	}
	
	ft_solve(from, 6 - from - to, k - 1);
	printf("%d %d\n", from, to);
	ft_solve(6 - from - to, to, k - 1);
}

int main(void)
{
	int k;

	scanf("%d", &k);
	printf("%d\n", ft_power(k) - 1);
	ft_solve(1, 3, k);
	return (0);
}