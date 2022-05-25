#include <stdio.h>

int	main(void)
{
	int arr[100000] = {0, };
	int k, len, num;

	scanf("%d", &k);

	len = 0;
	while (k)
	{
		scanf("%d", &arr[len]);
		if (!arr[len])
			arr[--len] = 0;
		else
			len++;
		k--;
	}

	num = 0;
	while (--len >= 0)
		num += arr[len];
	
	printf("%d", num);
	return (0);
}