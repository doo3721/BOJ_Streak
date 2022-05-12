#include <stdio.h>

int	main(void)
{
	int num;
	int idx;
	int	max;

	idx = 0;
	max = 0;
	while (idx < 2)
	{
		scanf("%d", &num);
		num = (num % 10 * 100) + (num % 100 / 10 * 10) + (num / 100);
		if (max < num)
			max = num;
		idx++;
	}
	printf("%d", max);
	return (0);
}