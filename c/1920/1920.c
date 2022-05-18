#include <stdio.h>

int	ft_bi_search(int *arr, int i_find, int left, int right)
{
	int mid;

	if (left > right)
		return (0);
	
	mid = (left + right) / 2;
	if (i_find < arr[mid])
		return (ft_bi_search(arr, i_find, left, mid - 1));
	else if (i_find > arr[mid])
		return (ft_bi_search(arr, i_find, mid + 1, right));
	else
		return (1);
}

void	ft_merge(int *arr, int left, int right, int mid)
{
	int	i_l;
	int i_r;
	int temp[100001];
	int idx;

	i_l = left;
	i_r = mid + 1;
	idx = left;
	while (i_l <= mid && i_r <= right)
	{
		if (arr[i_l] <= arr[i_r])
			temp[idx++] = arr[i_l++];
		else
			temp[idx++] = arr[i_r++];
	}

	while (i_l <= mid)
		temp[idx++] = arr[i_l++];
	while (i_r <= right)
		temp[idx++] = arr[i_r++];
	idx--;
	while (idx >= left)
	{
		arr[idx] = temp[idx];
		idx--;
	}
}

void	ft_mergesort(int *arr, int left, int right)
{
	int	mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(arr, left, mid);
		ft_mergesort(arr, mid + 1, right);
		ft_merge(arr, left, right, mid);
	}
}

int	main(void)
{
	int n;
	int m;
	int idx;
	int m_num;
	int n_arr[100001];

	scanf("%d", &n);
	idx = 0;
	while (idx < n)
		scanf("%d", &n_arr[idx++]);

	ft_mergesort(n_arr, 0, n - 1);

	scanf("%d", &m);
	idx = 0;
	while (idx < m)
	{
		scanf("%d", &m_num);
		printf("%d\n", ft_bi_search(n_arr, m_num, 0, n - 1));
		idx++;
	}
	return (0);
}