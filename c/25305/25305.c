#include <stdio.h>
#include <stdlib.h>

static int	arr[1000];
static int	n, k;

int	ft_cmp(const void *a, const void *b)
{
	int i_a, i_b;

	i_a = *(int *)a;
	i_b = *(int *)b;

	return (i_b - i_a);
}

int main(void)
{
	int i;

	scanf("%d%d", &n, &k);
	i = 0;
	while (i < n)
		scanf("%d", &arr[i++]);
	
	qsort(arr, n, sizeof(int), ft_cmp);
	printf("%d", arr[k - 1]);
	return (0);
}