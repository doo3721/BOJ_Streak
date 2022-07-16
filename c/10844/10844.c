#include <stdio.h>

static int	dp[101][10];

int	main(void)
{
	int	n, idx, s_idx, sum;

	scanf("%d", &n);
	
	idx = 1;
	while (idx <= 9)
		dp[1][idx++] = 1;
	
	idx = 2;
	while (idx <= n)
	{
		s_idx = 0;
		while (s_idx <= 9)
		{
			if (s_idx == 0)
				dp[idx][s_idx] = dp[idx - 1][1];
			else if (s_idx == 9)
				dp[idx][s_idx] = dp[idx - 1][8];
			else
				dp[idx][s_idx] = dp[idx - 1][s_idx - 1] + dp[idx - 1][s_idx + 1];
			s_idx++;
		}
		s_idx = 0;
		while (s_idx <= 9)
			dp[idx][s_idx++] %= 1000000000;
		idx++;
	}

	idx = 0;
	sum = 0;
	while (idx <= 9)
		sum = (sum + dp[n][idx++]) % 1000000000;

	printf("%d", sum);
	return (0);
}