#include <stdio.h>

int	main(void)
{
	int n;
	int k;
	int idx;
	int k_count;
	int n_count;
	int arr[1000] = {0, };

	scanf ("%d%d", &n, &k);

	idx = 0;
	while (idx < n)
		arr[idx++] = 1;
	
	n_count = 0;
	idx = 0;
	printf("<");
	while (n_count < n)
	{
		k_count = 0;
		while (k_count < k)
		{
			if (arr[idx % n])
				k_count++;
			if (k_count != k)
				idx++;
		}
		printf("%d", idx % n + 1);
		arr[idx % n] = 0;
		if (n_count != (n - 1))
			printf(", ");
		n_count++;
	}
	printf(">");
	return (0);
}