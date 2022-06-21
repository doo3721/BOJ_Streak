#include <stdio.h>
#include <stdlib.h>

static int	n, cnt;

void	ft_merge(int *a, int left, int right, int mid, int *b)
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
		cnt -= (a[l] == b[l]);
		a[l] = temp[idx++];
		cnt += (a[l] == b[l]);
		if (cnt == n)
		{
			printf("1");
			exit(0);
		}
		l++;
	}
}

void	ft_sort(int *a, int left, int right, int *b)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_sort(a, left, mid, b);
		ft_sort(a, mid + 1, right, b);
		ft_merge(a, left, right, mid, b);
	}
}

int main(void)
{
	int	a[500000];
	int b[500000];
	int idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);

	idx = 0;
	cnt = 0;
	while (idx < n)
	{
		scanf("%d", &b[idx]);
		cnt += (a[idx] == b[idx]);
		idx++;
	}

	if (cnt < n)
	{
		ft_sort(a, 0, n - 1, b);
		printf("0");
	}
	else
		printf("1");
	
	return (0);
}