#include <stdio.h>

int	main(void)
{
	int	count;
	int	idx;
	int	num;
	int	max;
	int	min;

	scanf("%d", &count);
	scanf("%d", &num);

	idx = 1;
	min = num;
	max = num;
	while (idx < count)
	{
		scanf("%d", &num);
		if (min > num)
			min = num;
		else if (max < num)
			max = num;
		idx++;
	}
	printf("%d %d", min, max);
	return (0);
}