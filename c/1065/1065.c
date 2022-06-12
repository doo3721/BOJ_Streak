#include <stdio.h>

int main(void)
{
	int n, idx, count;

	scanf("%d", &n);

	idx = 100;
	if (n > 0 && n < idx)
		count = n;
	else
	{
		count = idx - 1;
		while (idx != 1000 && idx <= n)
		{
			if ((idx / 100 - idx % 100 / 10) == (idx % 100 / 10 - idx % 10))
				count++;
			idx++;
		}
	}
	printf("%d", count);
	return (0);
}