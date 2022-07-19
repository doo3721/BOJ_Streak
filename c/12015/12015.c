#include <stdio.h>

static int	arr[1000000];
static int	lis[1000000];

static int	ft_bi_search(int t, int n)
{
	int l, r, m;

	l = 0;
	r = n;
	while (l < r)
	{
		m = (l + r) / 2;
		if (lis[m] < t)
			l = m + 1;
		else
			r = m;
	}
	return (r);
}

int	main(void)
{
	int	n, idx, i, j;

	scanf("%d", &n);
	
	i = 0;
	while (i < n)
		scanf("%d", &arr[i++]);
	
	lis[0] = arr[0];
	i = 1;
	j = 0;
	while (i < n)
	{
		if (lis[j] < arr[i])
			lis[++j] = arr[i];
		else
		{
			idx = ft_bi_search(arr[i], j);
			lis[idx] = arr[i];
		}
		i++;
	}
	printf("%d", j + 1);
	return (0);
}