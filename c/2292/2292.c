#include <stdio.h>

int main(void)
{
	int n;
	int idx;
	int count;

	scanf("%d", &n);

	idx = 1;
	count = 1;
	while (n > 1)
	{
		n -= idx * 6;
		idx++;
		count++;
	}
	printf("%d", count);
	return (0);
}