#include <stdio.h>
#include <stdlib.h>

typedef struct s_sorting
{
	int v;
	int i;
}	sorting;

static int n;

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_search(sorting *s, int v)
{
	int left, right, mid;

	left = 0;
	right = n - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (s[mid].v > v)
			right = mid - 1;
		else if (s[mid].v < v)
			left = mid + 1;
		else
			return (mid);
	}

	return (0);
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

void	ft_sort(int *a, int *b, sorting *s)
{
	int i_n, idx;

	ft_equal(a, b);
	i_n = n - 1;
	while (i_n)
	{
		if (a[i_n] != s[i_n].v)
		{
			idx = s[i_n].i;
			ft_swap(&a[idx], &a[i_n]);
			ft_equal(a, b);
			s[i_n].i = i_n;
			s[ft_search(s, a[idx])].i = idx;
		}

		i_n--;
	}
	
	printf("0");
}

void	ft_merge(sorting *s, int left, int right, int mid)
{
	int l, r, idx;
	sorting temp[n];

	l = left;
	r = mid + 1;
	idx = 0;
	while (l <= mid && r <= right)
	{
		if (s[l].v <= s[r].v)
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

void	ft_mergesort(sorting *s, int left, int right)
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

int main(void)
{
	int	a[500000];
	int b[500000];
	sorting	*s;
	int idx;

	scanf("%d", &n);
	s = malloc(sizeof(sorting) * n);

	idx = 0;
	while (idx < n)
	{
		scanf("%d", &a[idx]);
		s[idx].v = a[idx];
		s[idx].i = idx;
		idx++;
	}

	idx = 0;
	while (idx < n)
		scanf("%d", &b[idx++]);

	ft_mergesort(s, 0, n - 1);
	ft_sort(a, b, s);
	
	return (0);
}