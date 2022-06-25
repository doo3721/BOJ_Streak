#include <stdio.h>

int	ft_fibo(int n)
{
	if (n < 2)
		return (n);
	return (ft_fibo(n - 2) + ft_fibo(n - 1));
}

int main(void)
{
	int n;

	scanf("%d", &n);
	printf("%d", ft_fibo(n));
	return (0);
}