#include <stdio.h>

int	main(void)
{
	int	n, m, count, i, j;

	scanf("%d%d", &n, &m);

	count = 1;
	
	if (n <= m)
		count++;
	if (n != 1)
	{
		i = n % 2 == 1 ? n / 2 + 1 : n / 2;
		if (i <= m)
			count++;
		if (n / 2 <= m)
			count++;
		if (n > 2)
		{
			j = n % 3 != 0 ? n / 3 + 1 : n / 3;
			if (j <= m)
				count++;
			if (i + j <= m)
				count++;
			if (n / 2 + j <= m)
				count++;
			if (n + j <= m)
				count++;
		}
	}
	printf("%d", count);
	return (0);
}