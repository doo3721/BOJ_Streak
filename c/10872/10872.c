#include <stdio.h>

int	ft_fact(int n)
{
	if (n == 0)
		return (1);
	return (n * ft_fact(n - 1));
}

int main(void)
{
	int n;

	scanf("%d", &n);

	printf("%d", ft_fact(n));

	return (0);
}