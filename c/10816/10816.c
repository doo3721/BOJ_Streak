#include <stdio.h>

void	ft_merge(int *arr, int left, int right, int mid)
{
	int i_l;
	int i_r;
	int temp[500000];
	int t_idx;

	i_l = left;
	i_r = mid + 1;
	t_idx = left;
	while (i_l <= mid && i_r <= right)
	{
		if (arr[i_l] <= arr[i_r])
			temp[t_idx++] = arr[i_l++];
		else
			temp[t_idx++] = arr[i_r++];
	}
	while (i_l <= mid)
		temp[t_idx++] = arr[i_l++];
	while (i_r <= right)
		temp[t_idx++] = arr[i_r++];
	t_idx--;

	while (t_idx >= left)
	{
		arr[t_idx] = temp[t_idx];
		t_idx--;
	}
}

void	ft_mergesort(int *arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(arr, left, mid);
		ft_mergesort(arr, mid + 1, right);
		ft_merge(arr, left, right, mid);
	}
}

/*
	찾는 수가 존재하는 첫 위치와 끝 위치를 구해서 그것으로 갯수를 구한다
*/
int	ft_bi_count_search(int *arr, int i_find, int left, int right)
{
	int i_l;
	int i_r;
	int first;
	int mid;

	i_l = left;
	i_r = right;
	while (i_l <= i_r)
	{
		mid = (i_l + i_r) / 2;
		if (arr[mid] < i_find)
			i_l = mid + 1;
		else
			i_r = mid - 1;
	}
	
	if (arr[i_l] != i_find)
		return (0);
	first = i_l;

	i_l = left;
	i_r = right;
	while (i_l <= i_r)
	{
		mid = (i_l + i_r) / 2;
		if (arr[mid] <= i_find)
			i_l = mid + 1;
		else
			i_r = mid - 1;
	}

	return (i_r - first + 1);
}

int	main(void)
{
	int n_arr[500000];
	int n;
	int m;
	int m_num;
	int idx;

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
		printf("%d ", ft_bi_count_search(n_arr, m_num, 0, n - 1));
		idx++;
	}
	return (0);
}