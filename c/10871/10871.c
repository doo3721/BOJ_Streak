#include <stdio.h>

int	main(void)
{
	int	arr[10000] = {0, };
	int n;
	int	cmp;
	int	num;
	int	idx;

	scanf("%d", &n);
	scanf("%d", &num);
	idx = 0;
	while (idx < n)
	{
		scanf("%d", &cmp);
		if (num > cmp)
			arr[idx] = cmp;
		idx++;
	}
	idx = 0;
	while (idx < n)
	{
		if (arr[idx] > 0)
			printf("%d ", arr[idx]);
		idx++;
	}
	return (0);
}