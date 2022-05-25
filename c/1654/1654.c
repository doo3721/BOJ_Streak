#include <stdio.h>

int	main(void)
{
	int k, n, idx, sum, ans, n_comp;
	int arr[10000];

	scanf("%d%d", &k, &n);
	idx = 0;
	sum = 0;
	while (idx < k)
	{
		scanf("%d", &arr[idx]);
		sum += arr[idx++];
	}

	ans = sum / n;
	while (1)
	{
		idx = 0;
		n_comp = 0;
		while (idx < k)
			n_comp += arr[idx++] / ans;
		if (n_comp >= n)
			break ;
		ans--;
	}
	printf("%d", ans);
	return (0);
}