#include <stdio.h>

void	ft_merge(int *a, int left, int right, int mid)
{
	int t[1000];
	int l, r, i;

	l = left;
	r = mid + 1;
	i = left;
	while (l <= mid && r <= right)
	{
		if (a[l] <= a[r])
			t[i++] = a[l++];
		else
			t[i++] = a[r++];
	}

	while (l <= mid)
		t[i++] = a[l++];
	while (r <= right)
		t[i++] = a[r++];

	i = left;
	while (i <= right)
	{
		a[i] = t[i];
		i++;
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
    int n, idx;
    int a[1000];

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
		scanf("%d", &a[idx++]);
	
	ft_sort(a, 0, n - 1);
	idx = 0;
	while (idx < n)
		printf("%d\n", a[idx++]);
	return (0);
}