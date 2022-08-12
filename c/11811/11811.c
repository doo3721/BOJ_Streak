#include <stdio.h>

static int	arr[1000];

int main(void)
{
	int n, x, i, j;

	scanf("%d", &n);

	i = 0;
	while (i < n)
	{
		scanf("%d", &arr[i]);
		j = 1;
		while (j < n)
		{
			scanf("%d", &x);
			arr[i] |= x;
			j++;
		}
		i++;
	}
	
	i = 0;
	while (i < n)
		printf("%d ", arr[i++]);
	return (0);
}