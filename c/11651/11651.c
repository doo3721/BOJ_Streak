#include <stdio.h>

void	ft_merge(int *x_arr, int *y_arr, int left, int right, int mid)
{
	int x_temp[100000];
	int y_temp[100000];
	int i_l, i_r, t_idx;

	i_l = left;
	i_r = mid + 1;
	t_idx = left;
	while (i_l <= mid && i_r <= right)
	{
		if (y_arr[i_l] < y_arr[i_r])
		{
			x_temp[t_idx] = x_arr[i_l];
			y_temp[t_idx++] = y_arr[i_l++];
		}
		else if (y_arr[i_l] > y_arr[i_r])
		{
			x_temp[t_idx] = x_arr[i_r];
			y_temp[t_idx++] = y_arr[i_r++];
		}
		else
		{
			if (x_arr[i_l] <= x_arr[i_r])
			{
				x_temp[t_idx] = x_arr[i_l];
				y_temp[t_idx++] = y_arr[i_l++];
			}
			else
			{
				x_temp[t_idx] = x_arr[i_r];
				y_temp[t_idx++] = y_arr[i_r++];
			}
		}
	}
	while (i_l <= mid)
	{
		x_temp[t_idx] = x_arr[i_l];
		y_temp[t_idx++] = y_arr[i_l++];
	}
	while (i_r <= right)
	{
		x_temp[t_idx] = x_arr[i_r];
		y_temp[t_idx++] = y_arr[i_r++];
	}
	t_idx--;

	while (t_idx >= left)
	{
		x_arr[t_idx] = x_temp[t_idx];
		y_arr[t_idx] = y_temp[t_idx];
		t_idx--;
	}
}

void	ft_mergesort(int *x_arr, int *y_arr, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		ft_mergesort(x_arr, y_arr, left, mid);
		ft_mergesort(x_arr, y_arr, mid + 1, right);
		ft_merge(x_arr, y_arr, left, right, mid);
	}
}

int	main(void)
{
	int	x[100000];
	int y[100000];
	int n, idx;

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
	{
		scanf("%d%d", &x[idx], &y[idx]);
		idx++;
	}

	ft_mergesort(x, y, 0, n - 1);

	idx = 0;
	while (idx < n)
	{
		printf("%d %d\n", x[idx], y[idx]);
		idx++;
	}
	return (0);
}