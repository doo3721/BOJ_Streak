#include <stdio.h>
#include <stdlib.h>

typedef struct	s_line
{
	int	a;
	int	b;
}	line;

static line	arr[100];
static int	dp[100];

static int	ft_cmp(const void *a, const void *b)
{
	line *tmp_a = (line *)a;
	line *tmp_b = (line *)b;

	return ((*tmp_a).b - (*tmp_b).b);
}

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
	{
		scanf("%d", &arr[idx].a);
		scanf("%d", &arr[idx++].b);
	}
	qsort(arr, n, sizeof(line), ft_cmp);

	idx = 0;
	max = 0;
	while (idx < n)
	{
		dp[idx] = 1;
		s_idx = 0;
		while (s_idx < idx)
		{
			if (arr[s_idx].a < arr[idx].a)
				dp[idx] = ft_max(dp[idx], dp[s_idx] + 1);
			s_idx++;
		}
		max = ft_max(max, dp[idx]);
		idx++;
	}
	printf("%d", n - max);
	return (0);
}