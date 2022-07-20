#include <stdio.h>

static int	arr[1000];
static int 	dp[1000];

static int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int n, idx, s_idx, max;

	scanf("%d", &n);
	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);
	
	max = 0;
	idx = n - 1;
	while (idx >= 0)
	{
		dp[idx] = 1;
		s_idx = n - 1;
		while (s_idx > idx)
		{
			if (arr[s_idx] < arr[idx])
				dp[idx] = ft_max(dp[idx], dp[s_idx] + 1);
			s_idx--;
		}
		max = ft_max(max, dp[idx]);
		idx--;
	}
	printf("%d", max);
	return (0);
}