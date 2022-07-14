#include <stdio.h>

static int	arr[1000][3] = {{0, 0, 0}, };
static int	dp[1000][3] = {{0, 0, 0}, };

static int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}

int	main(void)
{
	int	n, min, idx, s_idx;

	scanf("%d", &n);

	idx = 0;
	scanf("%d%d%d", &arr[idx][0], &arr[idx][1], &arr[idx][2]);
	
	s_idx = 0;
	while (s_idx < 3)
	{
		dp[idx][s_idx] = arr[idx][s_idx];
		s_idx++;
	}

	idx++;
	while (idx < n)
	{
		scanf("%d%d%d", &arr[idx][0], &arr[idx][1], &arr[idx][2]);
		dp[idx][0] = ft_min(dp[idx - 1][1] + arr[idx][0], dp[idx - 1][2] + arr[idx][0]);
		dp[idx][1] = ft_min(dp[idx - 1][0] + arr[idx][1], dp[idx - 1][2] + arr[idx][1]);
		dp[idx][2] = ft_min(dp[idx - 1][0] + arr[idx][2], dp[idx - 1][1] + arr[idx][2]);
		idx++;
	}

	s_idx = 0;
	min = 2147483647;
	while (s_idx < 3)
	{
		if (min > dp[n - 1][s_idx])
			min = dp[n - 1][s_idx];
		s_idx++;
	}
	printf("%d", min);
	return (0);
}