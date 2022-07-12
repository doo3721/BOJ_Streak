#include <stdio.h>

static int	arr[100000] = {0, };
static int	dp[100000] = {0, };

int main(void)
{
	int	n, idx, max;

	scanf("%d", &n);

	scanf("%d", &arr[0]);
	dp[0] = arr[0];
	max = dp[0];
	idx = 1;
	while (idx < n)
	{
		scanf("%d", &arr[idx]);
		if (arr[idx] > dp[idx - 1] + arr[idx])
			dp[idx] = arr[idx];
		else
			dp[idx] = dp[idx - 1] + arr[idx];
		if (max < dp[idx])
			max = dp[idx];
		idx++;
	}

	printf("%d", max);
	return (0);
}