#include <stdio.h>

void	ft_merge(int *arr, int left, int right, int mid)
{
	int temp[100];
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
	int n_arr[100];
	int n, k, idx, num, s_max, s_min, ans;

	scanf("%d%d", &n, &k);

	idx = 0;
	s_min = 100000;
	s_max = -100000;
	while (idx < n)
	{
		scanf("%d", &num);
		if (s_max < num)
			s_max = num;
		else if (s_max > num)
			s_min = num;
		idx++;
	}
	
	idx = 0;
	while (idx < n)
		scanf("%d", &n_arr[idx++]);
	
	ft_mergesort(n_arr, 0, n - 1);

	if (s_max < 0 && n_arr[0] > 0)
		
	printf("%d", s_max * n_arr[n - 1 - k]);
	return (0);
}
/*

s_max가 음수인 경우

	n_arr가 음수인 경우 -> s_min * n_arr[k]
	n_arr가 양수인 경우 -> s_max * n_arr[k]
	n_arr가 음~양 인경우 -> s_min * n_arr[k], s_max * n_arr[k] 비교

s_min이 양수인 경우

	n_arr가 음수인 경우 -> s_min * n_arr[n - 1 - k]
	n_arr가 양수인 경우 -> s_max * n_arr[n - 1 - k]
	n_arr가 음~양 인경우 -> s_max * n_arr[n - 1 - k]	

s_min은 음수 s_max는 양수인 경우

	n_arr가 음수인 경우 -> s_min * n_arr[k], s_min * n_arr[n - 1 - k] 비교
	n_arr가 양수인 경우 -> s_max * n_arr[k], s_max * n_arr[n - 1 - k] 비교
	n_arr가 음~양 인경우 -> s_

*/