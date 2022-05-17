#include <stdio.h>
#include <stdlib.h>

static int	count = 0;

void	ft_merge(int *arr, int left, int right, int mid)
{
	int	t_arr[count];
	int i_l;
	int	i_r;
	int	t_idx;

	i_l = left;
	i_r = mid + 1;
	t_idx = left;
	while (i_l <= mid && i_r <= right)
	{
		if (arr[i_l] <= arr[i_r])
			t_arr[t_idx++] = arr[i_l++];
		else
			t_arr[t_idx++] = arr[i_r++];
	}
	while (i_l <= mid)
		t_arr[t_idx++] = arr[i_l++];
	while (i_r <= right)
		t_arr[t_idx++] = arr[i_r++];
	t_idx--;
	while (t_idx >= left)
	{
		arr[t_idx] = t_arr[t_idx];
		t_idx--;
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
	int	*arr;
	int	idx;

	scanf("%d", &count);
	arr = malloc(sizeof(int) * count);
	if (!arr)
		return (0);

	idx = 0;
	while (idx < count)
	{
		scanf("%d", &arr[idx]);
		idx++;
	}

	ft_mergesort(arr, 0, count - 1);

	idx = 0;
	while (idx < count)
	{
		printf("%d\n", arr[idx]);
		idx++;
	}
	return (0);
}