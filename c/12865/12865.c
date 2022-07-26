#include <stdio.h>
#include <stdlib.h>
/*
typedef struct s_thing
{
	int	w;
	int	v;
}	thing;

static thing	arr[100];
static int		dp[100][100001];

static int	ft_cmp(const void *a, const void *b)
{
	thing t1;
	thing t2;

	t1 = *(thing *)a;
	t2 = *(thing *)b;

	return (t1.w- t2.w);
}

static int	ft_max(int a, int b)
{
	return (a > b ? a : b);
}

int	main(void)
{
	int	n, limit, idx, s_idx;

	scanf("%d%d", &n, &limit);

	idx = 0;
	while (idx < n)
	{
		scanf("%d%d", &arr[idx].w, &arr[idx].v);
		idx++;
	}

	qsort(arr, n, sizeof(thing), ft_cmp);

	idx = arr[0].w;
	while (idx <= limit)
		dp[0][idx++] = arr[0].v;

	idx = 1;
	while (idx < n)
	{
		s_idx = arr[0].w;
		while (s_idx <= limit)
		{
			dp[idx][s_idx] = dp[idx - 1][s_idx];
			if (arr[idx].w <= s_idx)
				dp[idx][s_idx] = ft_max(arr[idx].v + dp[idx - 1][s_idx - arr[idx].w], \
										dp[idx][s_idx]);
			s_idx++;
		}
		idx++;
	}
	printf("%d", dp[n - 1][limit]);
	return (0);
}
*/

static int	res[100001];

int	main(void)
{
	int i, j, k, n, w, v;

	scanf("%d%d", &n, &k);
	i = 0;
	while (i < n)
	{
		scanf("%d%d", &w, &v);
		j = k;
		while (j >= w)
		{
			if (res[j] < res[j - w] + v)
				res[j] = res[j - w] + v;
			j--;
		}
		i++;
	}
	printf("%d", res[k]);
	return 0;
}