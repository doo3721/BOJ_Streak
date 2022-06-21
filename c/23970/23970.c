#include <stdio.h>
#include <stdlib.h>

static int n;

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
/*
void	ft_merge(int *s, int left, int right, int mid)
{
	int l, r, idx;
	int temp[n];

	l = left;
	r = mid + 1;
	idx = 0;
	while (l <= mid && r <= right)
	{
		if (s[l] <= s[r])
			temp[idx++] = s[l++];
		else
			temp[idx++] = s[r++];
	}

	while (l <= mid)
		temp[idx++] = s[l++];
	while (r <= right)
		temp[idx++] = s[r++];

	l = left;
	idx = 0;
	while (l <= right)
		s[l++] = temp[idx++];
}

void	ft_mergesort(int *s, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(s, left, mid);
		ft_mergesort(s, mid + 1, right);
		ft_merge(s, left, right, mid);
	}
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

void	ft_sort(int *a, int *b, int *s)
{
	int idx, i_n;

	i_n = n - 1;
	while (i_n && s[i_n] == b[i_n])
	{
		if (s[i_n] != a[i_n])
		{
			idx = 0;
			while (idx < i_n)
			{
				if (a[idx] > a[idx + 1])
					ft_swap(&a[idx], &a[idx + 1]);
				idx++;
			}
		}
		i_n--;
	}

	ft_equal(a, b);
	idx = 0;
	while (idx < i_n)
	{
		if (a[idx] > a[idx + 1])
		{	
			ft_swap(&a[idx], &a[idx + 1]);
			ft_equal(a, b);
		}
		idx++;
	}

	printf("0");
}

int main(void)
{
	int	a[10000];
	int b[10000];
	int s[10000];
	int idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
	{
		scanf("%d", &a[idx]);
		s[idx] = a[idx];
		idx++;
	}
	
	idx = 0;
	while (idx < n)
		scanf("%d", &b[idx++]);

	ft_mergesort(s, 0, n - 1);
	ft_sort(a, b, s);
	
	return (0);
}
*/

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

void	ft_sort(int *a, int *b)
{
	int idx, i_n;

	ft_equal(a, b);
	i_n = n - 1;
	while (i_n)
	{
		idx = 0;
		while (idx < i_n)
		{
			if (a[idx] > a[idx + 1])
			{	
				ft_swap(&a[idx], &a[idx + 1]);
				if (a[idx] == b[idx] && a[idx + 1] == b[idx + 1])
					ft_equal(a, b);
			}
			idx++;
		}
		i_n--;
	}
	
	printf("0");
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

	ft_sort(a, b);
	
	return (0);
}