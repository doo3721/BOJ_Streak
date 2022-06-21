#include <stdio.h>
#include <stdlib.h>

static int	n;

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_equal(int *a, int *b)
{
	int idx;

	idx = 0;
	while (idx < n)
	{
		if (a[idx] != b[idx])
			return ;
		idx++;
	}

	printf("1");
	exit(0);
}

int	ft_partition(int *a, int left, int right, int *b)
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
			if (idx != s_idx && a[idx] == b[idx] && a[s_idx] == b[s_idx])
				ft_equal(a, b);
		}
		s_idx++;
	}

	if (idx + 1 != right)
	{
		ft_swap(&a[idx + 1], &a[right]);
		if (idx + 1 != right && a[idx + 1] == b[idx + 1] && a[right] == b[right])
			ft_equal(a, b);
	}
	return (idx + 1);
}

void	ft_sort(int *a, int left, int right, int *b)
{
	int mid;

	if (left < right)
	{
		mid = ft_partition(a, left, right, b);
		ft_sort(a, left, mid - 1, b);
		ft_sort(a, mid + 1, right, b);
	}
}

int main(void)
{
	int	a[10000];
	int b[10000];
	int idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);
	
	idx = 0;
	while (idx < n)
		scanf("%d", &b[idx++]);

	ft_equal(a, b);
	ft_sort(a, 0, n - 1, b);
	printf("0");
	
	return (0);
}