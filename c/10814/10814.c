#include <stdio.h>
#include <stdlib.h>

static int	count = 0;

typedef struct s_signup
{
	int		age;
	char	name[101];
}	signup;

void	ft_merge(signup *arr, int left, int right, int mid)
{
	int	i_l;
	int	i_r;
	signup	temp[count];
	int		t_idx;

	i_l = left;
	i_r = mid + 1;
	t_idx = left;
	while (i_l <= mid && i_r <= right)
	{
		if (arr[i_l].age <= arr[i_r].age)
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

void	ft_mergesort(signup *arr, int left, int right)
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
	signup	*arr;
	int		idx;

	scanf("%d", &count);
	arr = malloc(sizeof(signup) * count);
	if (!arr)
		return (0);

	idx = 0;
	while (idx < count)
	{
		scanf("%d%s", &arr[idx].age, arr[idx].name);
		idx++;
	}

	ft_mergesort(arr, 0, count - 1);

	idx = 0;
	while (idx < count)
	{
		printf("%d %s\n", arr[idx].age, arr[idx].name);
		idx++;
	}
	free(arr);
	return (0);
}