#include <stdio.h>

int main(void)
{
	int		c, n, idx, avg, count;
	float	per;
	int		arr[1000];

	scanf("%d", &c);

	while (c)
	{
		scanf("%d", &n);

		idx = 0;
		avg = 0;
		while (idx < n)
		{
			scanf("%d", &arr[idx]);
			avg += arr[idx++];
		}

		avg /= n;

		count = 0;
		idx = 0;
		while (idx < n)
		{
			if (arr[idx] > avg)
				count++;
			idx++;
		}
		per = (float) count / (float) n * 100;

		printf("%.3f%%\n", per);
		c--;
	}
	return (0);
}