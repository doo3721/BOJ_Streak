#include <stdio.h>

int main(void)
{
	int n, idx, num;
	int	arr[10000] = {0, };

	scanf("%d", &n);

	idx = 0;
	while (idx < n)
	{
		scanf("%d", &num);
		arr[num - 1]++;
		idx++;
	}

	idx = 0;
	while (idx < 10000)
	{
		while (arr[idx])
		{
			printf("%d\n", idx + 1);
			arr[idx]--;
		}
		idx++;
	}
	return (0);
}