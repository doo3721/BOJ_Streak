#include <stdio.h>

static int	arr[1001];
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
