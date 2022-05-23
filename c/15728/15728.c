#include <stdio.h>

void	ft_merge(int *arr, int left, int right, int mid)
{
	int temp[110];
	int i_l, i_r, t_idx;

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

int main(void)
{
	int mul[110];
	int n, k, idx, num, m_idx, s_min, s_max;

	scanf("%d%d", &n, &k);

	idx = 0;
	s_min = 100000;
	s_max = -100000;
	while (idx < n)
	{
		scanf("%d", &num);
		if (s_min > num)
			s_min = num;
		if (s_max < num)
			s_max = num;
		idx++;
	}
	
	idx = 0;
	m_idx = 0;
	while (idx < n)
	{
		scanf("%d", &num);
		if (s_min * num > s_max * num)
			mul[m_idx++] = s_min * num;
		else
			mul[m_idx++] = s_max * num;
		idx++;
	}
	
	ft_mergesort(mul, 0, n - 1);
	printf("%d", mul[n - 1 - k]);
	return (0);
}