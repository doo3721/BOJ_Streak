#include <stdio.h>
#include <stdlib.h>

static int n, u_i;

void	ft_merge(int *a, int left, int right, int mid)
{
	int t[n];
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

void	ft_unique(int *src, int *dest, int n)
{
	int i;

	i = 0;
	u_i = 0;
	while (i < n)
	{
		dest[u_i] = src[i];
		u_i++;
		while (src[i] == src[i + 1])
			i++;
		i++;
	}
}

int	ft_search(int *a, int t, int n)
{
	int l, r, m;

	l = 0;
	r = n - 1;
	while (l <= r)
	{
		m = (l + r) / 2;
		if (a[m] > t)
			r = m - 1;
		else if (a[m] < t)
			l = m + 1;
		else
			return (m);
	}

	return (-1);
}

int main(void)
{
	int	*a;
	int *b;
	int *c;
	int	i;
	
	scanf("%d", &n);
	a = malloc(sizeof(int) * n);
	b = malloc(sizeof(int) * n);

	i = 0;
	while (i < n)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
		i++;
	}

	ft_sort(b, 0, n - 1);
	
	c = malloc(sizeof(int) * n);
	ft_unique(b, c, n);

	i = 0;
	while (i < n)
		printf("%d ", ft_search(c, a[i++], u_i));
	
	free(a);
	free(b);
	free(c);
	return (0);
}