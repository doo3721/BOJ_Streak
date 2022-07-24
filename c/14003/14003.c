#include <stdio.h>

static int	arr[1000000];
static int	lis[1000000];
static int	rec[1000000];

static int	ft_bi_search(int t, int n)
{
	int	l, r, m;

	l = 0;
	r = n;
	while (l < r)
	{
		m = (l + r) / 2;
		if (lis[m] < t)
			l = m + 1;
		else
			r = m;
	}
	return (r);
}

int main(void)
{
	int n, idx, i, j;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &arr[idx++]);

	lis[0] = arr[0];
	rec[0] = 0;
	j = 0;
	i = 1;
	while (i < n)
	{
		if (lis[j] < arr[i])
		{
			lis[++j] = arr[i];
			rec[i] = j;
		}
		else
		{
			idx = ft_bi_search(arr[i], j);
			lis[idx] = arr[i];
			rec[i] = idx;
		}
		i++;
	}

	printf("%d\n", j + 1);
	idx = n - 1;
	i = j;
	while (idx >= 0 && i >= 0)
	{
		if (rec[idx] == i)
		{
			lis[i] = arr[idx];
			i--;
		}
		idx--;
	}
	idx = 0;
	while (idx <= j)
		printf("%d ", lis[idx++]);
	return (0);
}