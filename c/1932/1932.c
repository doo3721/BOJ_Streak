#include <stdio.h>

static int	arr[500][500] ={{0, }, };
static int	dp[500][500] ={{0, }, };

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	return (b);
}

int	main(void)
{
	int	n, idx, s_idx, max;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
	{
		s_idx = 0;
		while (s_idx <= idx)
			scanf("%d", &arr[idx][s_idx++]);
		idx++;
	}

	dp[0][0] = arr[0][0];

	idx = 1;
	while (idx < n)
	{
		s_idx = 0;
		while (s_idx <= idx)
		{
			if (s_idx == 0)
				dp[idx][0] = dp[idx - 1][0] + arr[idx][0];
			else if (s_idx == idx)
				dp[idx][s_idx] = dp[idx - 1][s_idx - 1] + arr[idx][s_idx];
			else
				dp[idx][s_idx] = ft_max(dp[idx - 1][s_idx - 1] + arr[idx][s_idx], \
										dp[idx - 1][s_idx] + arr[idx][s_idx]);
			s_idx++;
		}
		idx++;
	}

	idx = 0;
	max = 0;
	while (idx < n)
	{
		if (max < dp[n - 1][idx])
			max = dp[n - 1][idx];
		idx++;
	}
	printf("%d", max);
	return (0);
}