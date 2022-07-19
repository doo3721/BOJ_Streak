#include <stdio.h>

static int	arr[1001];
static int	lis[1001];
/*
static int	dp[1001];

static int	ft_max(int a, int b)
{
	return (a >= b ? a : b);
}

int	main(void)
{
	int	n, idx, s_idx, max;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);
	
	idx = 0;
	max = 0;
	while (idx < n)
	{
		dp[idx] = 1;
		s_idx = 0;
		while (s_idx < idx)
		{
			if (arr[s_idx] < arr[idx])
				dp[idx] = ft_max(dp[idx], dp[s_idx] + 1);
			s_idx++;
		}
		max = ft_max(max, dp[idx]);
		idx++;
	}
	printf("%d", max);
	return (0);
}
*/

static int binary_search(int t, int n)
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

int main(void)
{
	int	n, idx, i, j;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);
	
	lis[0] = arr[0];
	j = 0;
	for (i = 1; i < n; i++)
	{
		if (lis[j] < arr[i])
			lis[++j] = arr[i];
		else
		{
			idx = binary_search(arr[i], j);
			lis[idx] = arr[i];
		}
	}
	printf("%d", j + 1);
	return (0);
}