#include <stdio.h>

int ft_check(int *arr, int k, int n, int target)
{
	int num, idx;

	idx = 0;
	num = 0;
	while (idx < k)
		num += arr[idx++] / target;

	if (num >= n)
		return (1);
	else
		return (0);
}

/*
	left + right 할 시 int 최댓값을 넘을 수 있다 
*/
int	ft_solve(int *arr, int k, int n, int max)
{
	int left, right, mid;

	left = 1;
	right = max;
	while (left < right)
	{
		mid = ((unsigned)(left + right)) / 2;
		if (ft_check(arr, k, n, mid))
			left = mid + 1;
		else
			right = mid;
	}

	while (!ft_check(arr, k, n, right))
		right--;

	return (right);
}

int	main(void)
{
	int k, n, idx, max;
	int arr[10000];

	scanf("%d%d", &k, &n);
	idx = 0;
	max = 0;
	while (idx < k)
	{
		scanf("%d", &arr[idx]);
		if (max < arr[idx])
			max = arr[idx];
		idx++;
	}
	
	printf("%d", ft_solve(arr, k, n, max));
	return (0);
}