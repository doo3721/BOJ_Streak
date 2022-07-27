#include <stdio.h>

static int	ps[100];
static int	cost[100];
static int	dp[10001];

int main(void)
{
	int	n, m, idx, s_idx, sum;

	scanf("%d%d", &n, &m);

	idx = 0;
	while (idx < n)
		scanf("%d", &ps[idx++]);
	idx = 0;
	sum = 0;
	while (idx < n)
	{
		scanf("%d", &cost[idx]);
		sum += cost[idx++];
	}
	
	idx = 0;
	while (idx < n)
	{
		s_idx = sum;
		while (s_idx >= cost[idx])
		{
			if (dp[s_idx] < dp[s_idx - cost[idx]] + ps[idx])
				dp[s_idx] = dp[s_idx - cost[idx]] + ps[idx];
			s_idx--;
		}
		idx++;
	}

	idx = 0;
	while (idx <= sum)
	{
		if (dp[idx] >= m)
		{
			printf("%d", idx);
			break ;
		}
		idx++;
	}
	return (0);
}