#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static int	n, k, arr[1000];

int	ft_cmp(const void *a, const void *b)
{
	int i_a, i_b;

	i_a = *(int *)a;
	i_b = *(int *)b;

	return (i_a - i_b);
}

int	main(void)
{
	char	num[20];
	int		i, count, temp;

	while (read(0, num, 20) > 0)
	{
		if (!n)
		{
			n = atoi(num);
			continue;
		}

		i = 0;
		while (num[i] != '\n')
			arr[k] |= (1 << (num[i++] - '0'));
		k++;
		
		if (k == n)
		{
			qsort(arr, n, sizeof(int), ft_cmp);
			temp = arr[0];
			count = 1;
			i = 1;
			while (i < n)
			{
				if (temp != arr[i])
				{
					temp = arr[i];
					count++;
				}
				i++;
			}
			printf("%d\n", count);
			memset(arr, 0, sizeof(int) * n);
			n = 0;
			k = 0;
		}
	}
	return (0);

	// 런타임오류
}
