#include <stdio.h>
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_quicksort(int *arr, int left, int right)
{
	int	i_l;
	int i_r;
	int pivot;

	i_l = left;
	i_r = right;
	pivot = arr[(left + right) / 2];
	while (i_l <= i_r)
	{
		while (arr[i_l] < pivot)
			i_l++;
		while (pivot < arr[i_r])
			i_r--;
		if (i_l <= i_r)
		{
			ft_swap(&arr[i_l], &arr[i_r]);
			i_l++;
			i_r--;
		}
	}

	if (left < i_r)
		ft_quicksort(arr, left, i_r);
	if (i_l < right)
		ft_quicksort(arr, i_l, right);
}

int	main(void)
{
	int	count;
	int	num;
	int *cards;
	int idx;
	int	max_comb;
	int last_comb;
	int	j_idx;
	int k_idx;

	scanf("%d", &count);
	scanf("%d", &num);

	cards = malloc(sizeof(int) * count);
	if (!cards)
		return (0);
	
	idx = 0;
	while (idx < count)
	{
		scanf("%d", &cards[idx]);
		idx++;
	}

	ft_quicksort(cards, 0, count - 1);

	idx = 0;
	max_comb = 0;
	while (idx < count - 2)
	{
		if (cards[idx] > num)
			break ;
		j_idx = idx + 1;
		while (j_idx < count - 1)
		{
			if ((cards[idx] + cards[j_idx]) > num)
				break ;
			k_idx = j_idx + 1;
			while (k_idx < count)
			{
				last_comb = cards[idx] + cards[j_idx] + cards[k_idx];
				if (last_comb > num)
					break ;
				if (last_comb > max_comb)
					max_comb = last_comb;
				k_idx++;
			}
			j_idx++;
		}
		idx++;
	}
	printf("%d", max_comb);
	free(cards);
	return (0);
}