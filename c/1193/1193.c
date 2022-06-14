#include <stdio.h>

int main(void)
{
	int n, idx;

	scanf("%d", &n);

	idx = 1;
	while ((idx * (idx + 1)) / 2 <= n)
		idx++;
	
	if ((idx * (idx + 1)) / 2 != n)
		idx--;
	
	n -= (idx * (idx + 1)) / 2;

	if (idx % 2 == 1)
	{
		if (n != 0)
			printf("%d/%d", n, idx - n + 2);
		else
			printf("1/%d", idx);
	}
	else
	{
		if (n != 0)
			printf("%d/%d", idx - n + 2, n);
		else
			printf("%d/1", idx);
	}

	return (0);
}
