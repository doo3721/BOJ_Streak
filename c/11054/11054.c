#include <stdio.h>

static int	arr[1000];
static int	s_dp[1000];
static int	r_dp[1000];

static int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int	n, idx, s_idx, max;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);
	
	idx = 0;
	while (idx < n)
	{
		s_dp[idx] = 1;
		s_idx = 0;
		while (s_idx < idx)
		{
			if (arr[s_idx] < arr[idx])
				s_dp[idx] = ft_max(s_dp[idx], s_dp[s_idx] + 1);
			s_idx++;
		}
		idx++;
	}

	idx = n - 1;
	while (idx >= 0)
	{
		r_dp[idx] = 1;
		s_idx = n - 1;
		while (s_idx > idx)
		{
			if (arr[s_idx] < arr[idx])
				r_dp[idx] = ft_max(r_dp[idx], r_dp[s_idx] + 1);
			s_idx--;
		}
		idx--;
	}

	max = 0;
	idx = 0;
	while (idx < n)
	{
		max = ft_max(max, s_dp[idx] + r_dp[idx] - 1);
		idx++;
	}
	printf("%d", max);
	return (0);
}