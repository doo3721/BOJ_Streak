#include <stdio.h>

int	main(void)
{
	int	n, count;

	scanf("%d", &n);

	count = 0;
	while (n)
	{
		if (n % 2)
			count++;
		n /= 2;
	}
	printf("%d", count);
	return (0);
}
