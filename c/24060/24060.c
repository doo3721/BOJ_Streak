#include <stdio.h>
#include <stdlib.h>

static int	n, k;

void	ft_merge(int *a, int left, int right, int mid)
{
	int l, r, idx;
	int temp[500000];

	l = left;
	r = mid + 1;
	idx = 0;

	while (l <= mid && r <= right)
	{
		if (a[l] <= a[r])
			temp[idx++] = a[l++];
		else
			temp[idx++] = a[r++];
	}

	while (l <= mid)
		temp[idx++] = a[l++];
	while (r <= right)
		temp[idx++] = a[r++];

	l = left;
	idx = 0;

	while (l <= right)
	{
		a[l++] = temp[idx++];
		if (!(--k))
		{
			printf("%d", a[l - 1]);
			exit(0);
		}
	}
}

void	ft_sort(int *a, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_sort(a, left, mid);
		ft_sort(a, mid + 1, right);
		ft_merge(a, left, right, mid);
	}
}

int main(void)
{
	int	a[500000];
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