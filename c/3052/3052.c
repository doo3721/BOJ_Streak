#include <stdio.h>

int	main(void)
{
	int	arr[10] = {0, };
	int mod[42] = {0, };
	int	idx;
	int count;

	idx = 0;
	while (idx < 10)
	{
		scanf("%d", &arr[idx]);
		arr[idx] = arr[idx] % 42;
		mod[arr[idx]]++;
		idx++;
	}
	count = 0;
	idx = 0;
	while (idx < 42)
	{
		if (mod[idx] > 0)
			count++;
		idx++;
	}
	printf("%d", count);
	return (0);
}