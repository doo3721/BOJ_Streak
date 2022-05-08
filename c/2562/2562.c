#include <stdio.h>

int	main(void)
{
	int	arr[9];
	int	idx;
	int max_idx;
	int	max;

	idx = 0;
	max_idx = 0;
	max = 0;
	while (idx < 9)
	{
		scanf("%d", &arr[idx]);
		if (max < arr[idx])
		{
			max = arr[idx];
			max_idx = idx + 1;
		}
		idx++;
	}

	printf ("%d\n%d", max, max_idx);
	return (0);
}