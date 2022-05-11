#include <stdio.h>

int	main(void)
{
	int	idx;
	int	sum;
	int	num;

	idx = 0;
	sum = 0;
	while (idx < 5)
	{
		scanf("%d", &num);
		sum = sum + (num * num);
		idx++;
	}
	printf("%d", sum % 10);
	return (0);
}