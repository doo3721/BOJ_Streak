#include <stdio.h>

int	ft_factorial(int num)
{
	int ftrl;

	ftrl = 1;
	while (num > 0)
	{
		ftrl *= num;
		num--;
	}
	return (ftrl);
}

int	main(void)
{
	int n;
	int	k;
	int result;

	scanf("%d", &n);
	scanf("%d", &k);

	result = ft_factorial(n) / (ft_factorial(k) * ft_factorial(n - k));

	printf("%d", result);
	return (0);
}