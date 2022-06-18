#include <stdio.h>
#include <stdlib.h>

static int	n, k;

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_partition(int *a, int left, int right)
{
	int	x, idx, s_idx;

	x = a[right];
	idx = left - 1;
	s_idx = left;
	while (s_idx < right)
	{
		if (a[s_idx] <= x)
		{
			ft_swap(&a[++idx], &a[s_idx]);
			if (!(--k))
			{
				idx = 0;
				while (idx < n)
					printf("%d ", a[idx++]);
				exit(0);
			}
		}
		s_idx++;
	}

	if (idx + 1 != right)
	{
		ft_swap(&a[idx + 1], &a[right]);
		if (!(--k))
		{
			idx = 0;
			while (idx < n)
				printf("%d ", a[idx++]);
			exit(0);
		}
	}
	return (idx + 1);
}

void	ft_sort(int *a, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = ft_partition(a, left, right);
		ft_sort(a, left, mid - 1);
		ft_sort(a, mid + 1, right);
	}
}

int main(void)
{
	int	a[10000];
	int idx;

	scanf("%d%d", &n, &k);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);

	ft_sort(a, 0, n - 1);
	if (k)
		printf("-1");
	
	return (0);
}