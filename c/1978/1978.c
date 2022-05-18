#include <stdio.h>

int	ft_is_prime(int num)
{
	int idx;

	if (num < 2)
		return (0);
	
	idx = 2;
	while (idx * idx <= num)
	{
		if ((num % idx) == 0)
			return (0);
		idx++;
	}
	return (1);
}

int	main(void)
{
	int	count;
	int idx;
	int arr[200];
	int prime_count;

	scanf("%d", &count);

	idx = 0;
	prime_count = 0;
	while (idx < count)
	{
		scanf("%d", &arr[idx]);
		prime_count += ft_is_prime(arr[idx]);
		idx++;
	}
	printf("%d\n", prime_count);
	return (0);
}